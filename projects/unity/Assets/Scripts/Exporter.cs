using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;
using UnityEditor;

public unsafe class Exporter
{
    //WRAPPER


    //Comunicacion con la DLL
    //Aqui se incluyen las funciones de llamada a la DLL
    #region Native
    struct NativeExporter { }

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern NativeExporter* create();

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern void destroy(NativeExporter* ptr);

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern bool export_obj(NativeExporter* ptr, string path, string name);

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern IntPtr get_path(NativeExporter* ptr);

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern IntPtr get_log(NativeExporter* ptr);

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern bool set_mesh_transform(NativeExporter* ptr, int index, Vector3 position, Vector3 rotation, Vector3 scale);

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern bool set_mesh_by_index(NativeExporter* ptr, int index, Vector3[] vertex, Vector3[] normals, Vector2[] uvs, int size_v, int size_n, int size_uv);

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern void set_meshes_count(NativeExporter* ptr, int size);

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern bool set_mesh_submeshes_count(NativeExporter* ptr, int index, int size);

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern bool set_submesh_triangles(NativeExporter* ptr, int index, int submesh, int[] triangles, int size);

    [DllImport("ExportTool", CallingConvention = CallingConvention.Cdecl)]
    private static extern int get_meshes_count(NativeExporter* ptr);

    #endregion

    //Exportador
    NativeExporter* nativeExporter;

    //Indica si se debe exportar toda la escena
    public bool allScene = false;
    //Nombre del archivo que se va a crear
    public string name = "scene";

    #region API friendly
    /// <summary>
    /// Constructor del exportador
    /// </summary>
    public Exporter()
    {
        nativeExporter = create();
    }
    /// <summary>
    /// Destructor del exportador
    /// </summary>
    ~Exporter()
    {
        destroy(nativeExporter);
    }
    
    /// <summary>
    /// Exporta los elementos seleccionados a un archivo obj
    /// </summary>
    /// <param name="path">Ruta en la que se va a crear el archivo .obj</param>
    /// <param name="fileName">Nombre del archivo .obj</param>
    /// <returns></returns>
    public bool Export(string path, string fileName)
    {
        
        //-----------------------------------------------------------------------
        //Seleccion de mallas
        List<MeshFilter> meshesList = new List<MeshFilter>();

        if(allScene)
        {
            foreach(MeshFilter m in UnityEngine.Object.FindObjectsOfType(typeof(MeshFilter)) as MeshFilter[])
            {
                meshesList.Add(m);
            }
        }
        else
        {
            foreach (GameObject gameobject in Selection.gameObjects)
            {
                if (gameobject.GetComponent<MeshFilter>() != null)
                    meshesList.Add(gameobject.GetComponent<MeshFilter>());
            }
        }
        
        if (meshesList.Count == 0)
        {
            Debug.Log("Ninguna malla seleccionada");
            return false;
        }

        MeshFilter[] meshes = meshesList.ToArray();

        //------------------------------------------------------------------------
        //Comprobacion de que las mallas no sean parte del static batch/batching
        if (Application.isPlaying)
        {
            foreach (MeshFilter filter in meshes)
            {
                MeshRenderer renderer = filter.gameObject.GetComponent<MeshRenderer>();
                if (renderer != null && renderer.isPartOfStaticBatch)
                {
                    Debug.Log("Error malla con static batch");
                    return false;
                }
            }
        }
        //------------------------------------------------------------------------
        //Paso de elemenos necesarios para la exportacion
        set_meshes_count(nativeExporter, meshes.Length);

        for (int i = 0; i < meshes.Length; ++i)
        {
            string name = meshes[i].gameObject.name;
            MeshRenderer renderer = meshes[i].gameObject.GetComponent<MeshRenderer>();
            
            if (!set_mesh_transform(nativeExporter, i, meshes[i].transform.position, meshes[i].transform.rotation.eulerAngles, meshes[i].transform.lossyScale))
                return false;

            if (!set_mesh_by_index(nativeExporter, i, meshes[i].sharedMesh.vertices, meshes[i].sharedMesh.normals, meshes[i].sharedMesh.uv, meshes[i].sharedMesh.vertices.Length, meshes[i].sharedMesh.normals.Length, meshes[i].sharedMesh.uv.Length))
                return false;

            if (!set_mesh_submeshes_count(nativeExporter, i, meshes[i].sharedMesh.subMeshCount))
                return false;

            for (int j = 0; j < meshes[i].sharedMesh.subMeshCount; ++j)
            {
                if (!set_submesh_triangles(nativeExporter, i, j, meshes[i].sharedMesh.GetTriangles(j), meshes[i].sharedMesh.GetTriangles(j).Length))
                    return false;

            }
        }
        
        //Exportacion. Creacion del archivo
        return export_obj(nativeExporter, path, fileName);
    }

    /// <summary>
    /// Devuelve la actual ruta de destino
    /// </summary>
    /// <returns></returns>
    public string GetPath()
    {
        var ptr = get_path(nativeExporter);
        string back = Marshal.PtrToStringAnsi(ptr);
        return back;
    }
    /// <summary>
    /// Devuelve el Log de error
    /// </summary>
    /// <returns></returns>
    public string GetLog()
    {
        var ptr = get_log(nativeExporter);
        string back = Marshal.PtrToStringAnsi(ptr);
        return back;
    }


    #endregion
}
