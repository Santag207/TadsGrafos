#include <iostream>
#include "Header Files/Grafo.h"

int main()
{
    Grafo* grafo = new Grafo();
    int opc = 0;


    grafo->InsertaVertice("A");
    grafo->InsertaVertice("B");
    grafo->InsertaVertice("C");
    grafo->InsertaVertice("D");
    grafo->InsertaVertice("E");
    grafo->InsertaVertice("F");
    grafo->InsertaVertice("G");
    grafo->InsertaArista("A", "B", 7);
    grafo->InsertaArista("A", "D", 5);
    grafo->InsertaArista("B", "A", 7);
    grafo->InsertaArista("B", "C", 8);
    grafo->InsertaArista("B", "D", 9);
    grafo->InsertaArista("B", "E", 7);
    grafo->InsertaArista("C", "B", 8);
    grafo->InsertaArista("C", "E", 5);
    grafo->InsertaArista("D", "A", 5);
    grafo->InsertaArista("D", "B", 9);
    grafo->InsertaArista("D", "E", 15);
    grafo->InsertaArista("D", "F", 6);
    grafo->InsertaArista("E", "B", 7);
    grafo->InsertaArista("E", "C", 5);
    grafo->InsertaArista("E", "D", 15);
    grafo->InsertaArista("E", "F", 8);
    grafo->InsertaArista("E", "G", 9);
    grafo->InsertaArista("F", "D", 6);
    grafo->InsertaArista("F", "E", 8);
    grafo->InsertaArista("F", "G", 11);
    grafo->InsertaArista("G", "E", 9);
    grafo->InsertaArista("G", "F", 11);

    /*grafo->InsertaVertice("A");
    grafo->InsertaVertice("B");
    grafo->InsertaVertice("C");
    grafo->InsertaVertice("D");
    grafo->InsertaVertice("E");
    grafo->InsertaVertice("F");
    grafo->InsertaVertice("G");
    grafo->InsertaArista("A", "A", 13);
    grafo->InsertaArista("A", "D", 8);
    grafo->InsertaArista("B", "B", 52);
    grafo->InsertaArista("B", "C", 17);
    grafo->InsertaArista("B", "D", 83);
    grafo->InsertaArista("B", "F", 97);
    grafo->InsertaArista("B", "G", 60);
    grafo->InsertaArista("C", "A", 4);
    grafo->InsertaArista("D", "B", 97);
    grafo->InsertaArista("D", "C", 37);
    grafo->InsertaArista("D", "D", 22);
    grafo->InsertaArista("D", "E", 41);
    grafo->InsertaArista("D", "G", 64);
    grafo->InsertaArista("E", "B", 8);
    grafo->InsertaArista("E", "E", 45);
    grafo->InsertaArista("E", "F", 92);
    grafo->InsertaArista("F", "A", 12);
    grafo->InsertaArista("F", "B", 8);
    grafo->InsertaArista("F", "E", 42);
    grafo->InsertaArista("G", "D", 17);*/

    while (opc != 16){
        system("cls");
        std::cout << "1. Insertar vertice" << std::endl;
        std::cout << "2. Insertar arista" << std::endl;
        std::cout << "3. Obtener tamano" << std::endl;
        std::cout << "4. Mostrar lista de adyacencia" << std::endl;
        std::cout << "5. Eliminar vertice" << std::endl;
        std::cout << "6. Eliminar arista" << std::endl;
        std::cout << "7. Eliminar todo" << std::endl;
        std::cout << "8. Recorrido en anchura" << std::endl;
        std::cout << "9. Recorrido en profundidad" << std::endl;
        std::cout << "10. Primero en anchura" << std::endl;
        std::cout << "11. Primero en profundidad" << std::endl;
        std::cout << "12. Primero el mejor" << std::endl;
        std::cout << "13. Dijkstra" << std::endl;
        std::cout << "14. Kruskal" << std::endl;
        std::cout << "15. Prim" << std::endl;
        std::cout << "16. Salir" << std::endl;

        std::cout << std::endl;
        std::cout << "Ingrese una opcion del menu: ";
        std::cin >> opc;

        system("cls");

        switch (opc){
            case 1:
            {
                std::string nombre;
                std::cout << "Ingrese el nombre del vertice: ";
                std::cin >> nombre;

                grafo->InsertaVertice(nombre);

                break;
            }
            case 2:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string ori, dest;
                    int precio;
                    std::cout << "Ingrese el nombre del vertice origen: ";
                    std::cin >> ori;
                    std::cout << "Ingrese el nombre del vertice destino: ";
                    std::cin >> dest;
                    std::cout << "Ingrese el precio: ";
                    std::cin >> precio;

                    grafo->InsertaArista(ori, dest, precio);
                }

                break;
            }
            case 3:
            {
                int tamano = grafo->ObtenerTamano();
                std::cout << "El grafo tiene " << tamano << " vertices" << std::endl;

                break;
            }
            case 4:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                    grafo->MostrarListaAdyacencia();

                break;
            }
            case 5:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string nombre;
                    std::cout << "Ingrese el nombre del vertice a eliminar: ";
                    std::cin >> nombre;

                    grafo->EliminarVertice(nombre);
                }

                break;
            }
            case 6:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string ori, dest;
                    std::cout << "Ingrese el nombre del vertice origen: ";
                    std::cin >> ori;
                    std::cout << "Ingrese el nombre del vertice destino: ";
                    std::cin >> dest;

                    grafo->EliminarArista(ori, dest);
                }
                break;
            }
            case 7:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    grafo->EliminarTodo();
                }

                break;
            }
            case 8:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string nombre;
                    std::cout << "Ingrese el nombre del vertice origen: ";
                    std::cin >> nombre;

                    grafo->RecorridoAnchura(nombre);
                }

                break;
            }
            case 9:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string nombre;
                    std::cout << "Ingrese el nombre del vertice origen: ";
                    std::cin >> nombre;

                    grafo->RecorridoProfundidad(nombre);
                }

                break;
            }
            case 10:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string ori, dest;
                    std::cout << "Ingrese el nombre del vertice origen: ";
                    std::cin >> ori;
                    std::cout << "Ingrese el nombre del vertice destino: ";
                    std::cin >> dest;

                    grafo->PrimeroEnAnchura(ori, dest);
                }

                break;
            }
            case 11:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string ori, dest;
                    std::cout << "Ingrese el nombre del vertice origen: ";
                    std::cin >> ori;
                    std::cout << "Ingrese el nombre del vertice destino: ";
                    std::cin >> dest;

                    grafo->PrimeroEnProfundidad(ori, dest);
                }

                break;
            }
            case 12:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string ori, dest;
                    std::cout << "Ingrese el nombre del vertice origen: ";
                    std::cin >> ori;
                    std::cout << "Ingrese el nombre del vertice destino: ";
                    std::cin >> dest;

                    grafo->PrimeroElMejor(ori,dest);
                }

                break;
            }
            case 13:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string ori;
                    std::cout << "Ingrese el nombre del vertice origen: ";
                    std::cin >> ori;

                    grafo->Dijkstra(ori);
                }

                break;
            }
            case 14:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    grafo->Kruskal();
                }

                break;
            }
            case 15:
            {
                if (grafo->EstaVacio())
                    std::cout << "El grafo esta vacio" << std::endl;
                else
                {
                    std::string nombre;
                    std::cout << "Ingrese el nombre del vertice origen: ";
                    std::cin >> nombre;

                    grafo->Prim(nombre);
                }

                break;
            }
        }

        std::cin.get();
        std::cin.get();
    }

    delete grafo;
    return 0;
}

/*
Diseño TADs
    +----------------+       +----------------+       +----------------+
    |     Grafo      |-------|    Vertice     |-------|     Arista     |
    +----------------+       +----------------+       +----------------+
    | - primero      |       | - nombre       |       | - precio       |
    | - tamano       |       | - sig          |       | - sig          |
    |                |       | - ari          |       | - dest         |
    |                |       +----------------+       +----------------+
    |                |
    | - EstaVacio()  |
    | - ObtenerTamano|
    | - ObtenerVertice|
    | - InsertaVertice|
    | - InsertaArista|
    | - MostrarListaA|
    | - EliminarVerti|
    | - EliminarArist|
    | - EliminarTodo |
    | - EliminarArist|
    | - EliminarArist|
    | - RecorridoAnch|
    | - RecorridoProf|
    | - PrimeroEnAnc |
    | - PrimeroEnPro |
    | - PrimeroElMej |
    | - MostrarRutaE|
    | - Dijkstra     |
    | - Kruskal      |
    | - Prim         |
    +----------------+

 */