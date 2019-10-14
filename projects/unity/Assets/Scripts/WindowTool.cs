using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.Runtime.InteropServices;
using System;

public class WindowTool : EditorWindow
{
    /// <summary>
    /// Exportador 
    /// </summary>
    Exporter exporterTool;

    /// <summary>
    /// Estructura que recoge los ajustes de la herramienta
    /// </summary>
    struct Settings
    {
        public string path;
        public string name;
        public bool allScene;
    };

    /// <summary>
    /// Ajustes de la herramienta
    /// </summary>
    static Settings toolSettings;

    /// <summary>
    /// Cantidad de mallas seleccionadas a exportar
    /// </summary>
    private int objectsCount;

    /// <summary>
    /// Inicializa la ventana
    /// </summary>
    [MenuItem("Window/Tools/OBJ Expoter")]
    static void Init()
    {
        WindowTool tool = (WindowTool)EditorWindow.GetWindow(typeof(WindowTool));
        tool.titleContent.text = "OBJ Exporter";
        tool.titleContent.image = (Texture2D)AssetDatabase.LoadAssetAtPath("Assets/Textures/tool-icon.png", typeof(Texture2D));
        tool.Show();
        toolSettings.allScene = false;
        toolSettings.name = "scene";
        toolSettings.path = "Example: D:/Documents/Unity/projects/unity-project/Assets/";
        
    }

    /// <summary>
    /// Gestion de la ventana
    /// </summary>
    private void OnGUI()
    {

        GUILayout.Label("Base Settings", EditorStyles.boldLabel);
        toolSettings.path = EditorGUILayout.TextField("File path", toolSettings.path);
        toolSettings.name = EditorGUILayout.TextField("File name", toolSettings.name);
        toolSettings.allScene = EditorGUILayout.Toggle("Export all scene", toolSettings.allScene);
        
        EditorGUILayout.Space();
        GUILayout.Label("Selected Objects " + GetSelected(), EditorStyles.label);
        EditorGUILayout.Space();
        EditorGUILayout.Space();

        if (GUILayout.Button("Export"))
        {
            EditorUtility.DisplayProgressBar("Exporting...", "Taking meshes from the scene", 1);
            if (GetSelected() == 0)
            {
                EditorUtility.DisplayDialog("ERROR", "It have to be selected almost one object to export. " +
                            "You can check 'Export all scene' if you want to export all the meshes on the current scene", "Close");

                return;
            }

            EditorUtility.DisplayProgressBar("Exporting...", "Checking directory", 40);

            if (CheckPath() && CheckName())
            {
                EditorUtility.DisplayProgressBar("Exporting...", "Setting the tool", 60);

                exporterTool = new Exporter();

                exporterTool.allScene = toolSettings.allScene;
                exporterTool.name = toolSettings.name;
                EditorUtility.DisplayProgressBar("Exporting...", "Creating the file", 80);
                if (!exporterTool.Export(toolSettings.path, toolSettings.name))
                {
                    EditorUtility.DisplayProgressBar("Exporting...", "Creating the file", 99);

                    //Debug.Log("Error: " + exporterTool.GetLog());
                    if(EditorUtility.DisplayDialog("ERROR", "Export error: " + exporterTool.GetLog(), "Close"))
                    {
                        EditorUtility.ClearProgressBar();
                    }
                }
                else
                {
                    EditorUtility.DisplayProgressBar("Exporting...", "Completed!", 100);


                    if(EditorUtility.DisplayDialog("Done!!", "It has been created and .obj file named " + exporterTool.name + 
                        " that containts " + GetSelected() + " meshes at the directory " + toolSettings.path +".", "Close"))
                    {
                        EditorUtility.ClearProgressBar();
                    }

                }
            }
        }
    }

    /// <summary>
    /// Return the number of selected meshes
    /// </summary>
    /// <returns></returns>
    private int GetSelected()
    {
        int count = 0;
        if(!toolSettings.allScene)
        {
            foreach(GameObject g in Selection.gameObjects)
            {
                if (g.GetComponent<MeshFilter>() != null)
                    ++count;
            }
        }
        else
        {
            count = (FindObjectsOfType(typeof(MeshFilter))).Length;
        }

        return count;
    }

    /// <summary>
    /// Check that the path is valid
    /// </summary>
    /// <returns></returns>
    private bool CheckPath()
    {
        //Comprobacion de que no esta vacio
        if(toolSettings.path.Length == 0)
        {
            EditorUtility.DisplayDialog("ERROR", "The path field can not be empty.", "Close");
            return false;
        }
        //Comprueba si existe la ruta
        if(!System.IO.Directory.Exists(toolSettings.path))
        {
            if(EditorUtility.DisplayDialog("ERROR", "The current directory is not valid", "Create directory", "Close"))
            {
                System.IO.Directory.CreateDirectory(toolSettings.path);
                return true;
            }
            else
            {
                return false;
            }
        }
        //Comprueba si la ruta acaba con /
        if(toolSettings.path[toolSettings.path.Length -1] != '/')
        {
            EditorUtility.DisplayDialog("ERROR", "The directory has to end to the character '/'. Please check it and try again.", "Close");
            return false;
        }

        return true;
    }

    /// <summary>
    /// Check that the name is a valid name
    /// </summary>
    /// <returns></returns>
    private bool CheckName()
    {
        //Comrpeuba que no es un nombre vacio
        if(toolSettings.name.Length == 0)
        {
            EditorUtility.DisplayDialog("ERROR", "The name field can not be empty.", "Close");
            return false;
        }
        //Comprueba que no existe actualmente el archivo
        if(System.IO.File.Exists(toolSettings.path + toolSettings.name + ".obj"))
        {
            EditorUtility.DisplayDialog("ERROR", "There is already an object with that name in the directory. Please, delete the file or change the name", "Close");
            return false;
        }

        return true;
    }
}
