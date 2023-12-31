#define UNTITLED1_GRAFO_H

#include "Vertice.h"
#include "Arista.h"
#include <queue>
#include <list>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_set>
#include <limits>
#pragma once


/*
Clase Grafo:
    Atributos:
        - primero: puntero a Vertice
        - tamano: entero

    Métodos:
        - Grafo() // Constructor
        - EstaVacio() -> booleano
        - ObtenerTamano() -> entero
        - ObtenerVertice(nombre: cadena) -> puntero a Vertice
        - InsertaVertice(nombre: cadena)
        - InsertaArista(ori: cadena, dest: cadena, precio: entero)
        - MostrarListaAdyacencia()
        - EliminarVertice(nombre: cadena)
        - EliminarArista(ori: cadena, dest: cadena)
        - EliminarTodo()
        - EliminarAristas(vertice: puntero a Vertice)
        - EliminarAristasDestino(dest: cadena)
        - RecorridoAnchura(origen: cadena)
        - RecorridoProfundidad(origen: cadena)
        - PrimeroEnAnchura(origen: cadena, destino: cadena)
        - PrimeroEnProfundidad(origen: cadena, destino: cadena)
        - PrimeroElMejor(origen: cadena, destino: cadena)
        - MostrarRutaEncontrada(pilaPar: pila de pares de Vertice, vdest: puntero a Vertice)
        - Dijkstra(origen: cadena)
        - Kruskal()
        - Prim(origen: cadena)
 */

class Grafo
{
    Vertice* primero;
    int tamano;

public:
    Grafo();
    bool EstaVacio(); // Retorna true si el grafo está vacío
    int ObtenerTamano(); // Retorna el número de vertices en el grafo
    Vertice* ObtenerVertice(std::string nombre); // Retornar el vertice que tenga el nombre especificado
    void InsertaVertice(std::string nombre); // Inserta un vertice al grafo
    void InsertaArista(std::string ori, std::string dest, int precio); // Inserta arista entre los dos vertices especificados con el precio especificado
    void MostrarListaAdyacencia(); // Mostrar todos los vertices con sus aristas y precios
    void EliminarVertice(std::string nombre); // Elimina el vertice con el nombre especificado
    void EliminarArista(std::string ori, std::string dest); // Elimina la arista entre los dos vertices especificados
    void EliminarTodo(); // Elimina todos los vertices y aristas del grafo
    void EliminarAristas(Vertice* vertice); // Elimina las aristas del vertice especificado
    void EliminarAristasDestino(std::string dest); // Elimina las aristas que tienen como destino el vertice especificado
    void RecorridoAnchura(std::string origen); // Recorre el grafo con el algoritmo de anchura
    void RecorridoProfundidad(std::string origen); // Recorre el grafo con el algoritmo de profundidad
    void PrimeroEnAnchura(std::string origen, std::string destino); // Despliega la ruta entre los dos vertices especificados con el algoritmo de primero en anchura
    void PrimeroEnProfundidad(std::string origen, std::string destino); // Despliega la ruta entre los dos vertices especificados con el algoritmo de primero en profundidad
    void PrimeroElMejor(std::string origen, std::string destino); // Despliega la ruta entre los dos vertices especificados con el algoritmo de primero el mejor
    void MostrarRutaEncontrada(std::stack<std::pair<Vertice*, Vertice*>> pilaPar, Vertice* vdest); // Despliega la ruta encontrada
    void Dijkstra(std::string origen); // Despliega la ruta más corta entre el origen y los demás vertices
    void Kruskal(); // Genera el arbol recubridor minimo con el algoritmo de kruskal
    void Prim(std::string origen);// Genera el arbol recubridor minimo con el algoritmo de Prim
};