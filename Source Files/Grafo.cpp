#include <iostream>
#include "../Header Files/Grafo.h"

Grafo::Grafo() {
        primero = nullptr;
        tamano = 0;
}

bool Grafo::EstaVacio() {

    return tamano == 0;
}

int Grafo::ObtenerTamano() {
    return tamano;
}

Vertice *Grafo::ObtenerVertice(std::string nombre) {
    Vertice* i = primero;
    while (i != nullptr) {
        if (i->nombre == nombre) {
            return i;
        }

        i = i->sig;
    }
    return nullptr;
}

void Grafo::InsertarVertice(std::string nombre) {
    if (ObtenerVertice(nombre) == nullptr) {
        Vertice* nuevo = new Vertice(nombre);

        if (EstaVacio()) {
            primero = nuevo;
        }
        else {
            Vertice* i = primero;
            while (i->sig != nullptr) {
                i = i->sig;
            }
            i->sig = nuevo;
        }
        tamano++;
    }
    else {
        std::cout << "Ese vértice ya se encuentra en el grafo" << std::endl;//Mensaje verificacion
    }
}

void Grafo::InsertarArista(std::string ori, std::string dest, int precio) {
    Vertice* vori = ObtenerVertice(ori);
    Vertice* vdest = ObtenerVertice(dest);

    if (vori == nullptr){
        std::cout<<"El vertice origen no existe"<<std::endl; //Mensaje Verifiacion
    }

    if (vdest == nullptr){
        std::cout<<"El vertice destino no existe"<<std::endl; //Mensaje Verifiacion
    }
    if (vori != nullptr && vdest != nullptr){
        Arista* nueva = new Arista(vdest, precio);

        if (vori->ari == nullptr) {
            vori->ari = nueva;
        } else {
            Arista* J = vori->ari;
            while (J->sig != nullptr) {
                J = J->sig;
            }
            J->sig = nueva;
        }
    }

}

void Grafo::MostrarListaAdyacencia() {
    Vertice* i = primero;
    while (i != nullptr){
        Arista* J = i->ari;

        while (J != nullptr){
            std::cout<<i-> nombre<< " -> "<< J->precio << " -> "<< J->dest->nombre <<std::endl; //Imprimir datos de los grafos
            J - J->sig;
        }
        i = i->sig;
    }
    std::cout<<std::endl; //Salto para cada vertice en una linea diferente
}


void Grafo::EliminarAristas(Vertice *vertice) {
    if(vertice == nullptr){
        return;
    }

    Arista* i = vertice-> ari;
    while(vertice->ari != nullptr){
        i = vertice->ari;
        vertice->ari = vertice->ari->sig;
        std::cout<<"Arista "<<vertice->nombre<< " -> "<<i->dest->nombre<<" eliminado"<<std::endl;
        delete(i);
    }
}

void Grafo::EliminarAristasDestino(std::string dest) {
    Vertice* i = primero;
    while(i != nullptr){
        if(i->nombre == dest){
            continue;
        }
        if(i->ari->dest->nombre == dest){
            Arista* J = i->ari;
            i->ari = i->ari->sig;
            std::cout<<"Arista "<<i->nombre<<" -> "<< dest<<" fue elimianada"<<std::endl; //Mensaje Verifiacion
            delete(J);
        }
        else{
            Arista* x = i->ari;
            Arista* y = x->sig;

            while (y != nullptr){
                if(y->dest->nombre == dest){
                    x-> sig = y-> sig;
                    std::cout<<"Arista "<<i->nombre<<" -> "<< dest <<" fue elimianada"<<std::endl; //Mensaje Verifiacion
                    delete(y);
                }
                x = y;
                y = y->sig;
            }
        };
        i = i->sig;
    }
}

void Grafo::EliminarVertice(std::string nombre) {
    if(primero->nombre == nombre){
        Vertice* i = primero;
        primero = primero->sig;
        EliminarAristas(i);
        EliminarAristasDestino(i->nombre);
        std::cout<<"Vertice "<< nombre << " fue elimianado"<<std::endl;//Mensaje Verificacion
        delete(i);
        tamano--;
    }
    else{
        Vertice* i = primero;
        Vertice* J = i->sig;
        bool existe = false;

        while(J != nullptr){
            if(J->nombre == nombre){
                i->sig = J->sig;
                EliminarAristas(J);
                EliminarAristasDestino(J->nombre);
                delete(J);
                tamano--;
                std::cout<<"Vertice "<< nombre << " fue elimianado"<<std::endl;//Mensaje Verificacion
                existe = true;
                break;
            }
            i = J;
            J = J->sig;
        }
        if(!existe){
            std::cout<<"El vertice seleccionado no existe"<<std::endl;
        }
    }
}

void Grafo::EliminarArista(std::string ori, std::string dest) {
    Vertice* vori = ObtenerVertice(ori);
    Vertice* vdest = ObtenerVertice(dest);

    if (vori == nullptr){
        std::cout<<"El vertice origen no existe"<<std::endl; //Mensaje Verifiacion
    }

    if (vdest == nullptr){
        std::cout<<"El vertice destino no existe"<<std::endl; //Mensaje Verifiacion
    }
    if (vori != nullptr && vdest != nullptr){
        if(vori->ari->dest == vdest){
            Arista* i = vori->ari;
            vori->ari = vori->ari->sig;
            std::cout<<"Arista "<<ori<<" -> "<< dest <<" fue elimianada"<<std::endl; //Mensaje Verifiacion
            delete(i);
        }
        else{
            Arista* i = vori->ari;
            Arista* J = vori->ari;
            while(J != nullptr){
                if(J->dest == vdest){
                    i->sig = J->sig;
                    std::cout<<"Arista "<<ori<<" -> "<< dest <<" fue elimianada"<<std::endl; //Mensaje Verifiacion
                    delete(J);
                    break;
                }
                i = J;
                J = J->sig;
            }
        }
    }
}

void Grafo::EliminarTodo() {
    Vertice* i = primero;
    while (primero != nullptr){

        i = primero;
        primero = primero->sig;
        EliminarAristas(i);
        std::cout<<"Vertice "<<i->nombre<<" fue elimianada"<<std::endl; //Mensaje Verifiacion
        delete(i);
        tamano--;
    }
}