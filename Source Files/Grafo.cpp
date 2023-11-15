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

void Grafo::InsertaVertice(std::string nombre) {
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

void Grafo::InsertaArista(std::string ori, std::string dest, int precio) {
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
        std::cout<< i->nombre <<" = "<<std::endl;

        while (J != nullptr){
            std::cout<<i-> nombre<< " -> "<< J->precio << " -> "<< J->dest->nombre <<", "; //Imprimir datos de los grafos
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
        if(i->nombre == dest || i->ari == nullptr){
            i = i->sig;
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
        EliminarAristasDestino(i->nombre);
        std::cout<<"Vertice "<<i->nombre<<" fue elimianada"<<std::endl; //Mensaje Verifiacion
        delete(i);
        tamano--;
    }
}

void Grafo::RecorridoAnchura(std::string origen) {
    Vertice* vOrigen = ObtenerVertice(origen);

    if(vOrigen != nullptr){
        std::cout<<"Origen "<< origen <<std::endl;
        std::cout<<"En anchura: ";

        std::queue<Vertice*> cola;
        std::list<Vertice*>lista;
        cola.push(vOrigen);

        while (!cola.empty()){
            Vertice* vActual = cola.front();
            cola.pop();

            std::list<Vertice*>::iterator iter = std::find(lista.begin(), lista.end(),vActual);

            if(iter == lista.end()){
                std::cout<<vActual<<", ";
                lista.push_back(vActual);
            }

            Arista* i = vActual->ari;

            while (i != nullptr){
                Vertice* vDestino = i->dest;
                i = i->sig;
                iter = find(lista.begin(), lista.end(),vDestino);

                if(iter ==lista.end()){
                    cola.push(vDestino);
                }
                i = i->sig;
            }
        }

    }
    else{
        std::cout<<"El vertice especificado no existe"<<std::endl;
    }
}

void Grafo::RecorridoProfundidad(std::string origen) {
    Vertice* vOrigen = ObtenerVertice(origen);

    if(vOrigen != nullptr) {
        std::cout<<"Origen "<< origen <<std::endl;
        std::cout<<"En profundidad: ";

        std::stack<Vertice*> pila;
        std::list<Vertice*>lista;
        pila.push(vOrigen);

        while(!pila.empty()){
            Vertice* vActual = pila.top();
            pila.pop();
            std::list<Vertice*>::iterator iter = std::find(lista.begin(), lista.end(),vActual);

             if(iter ==lista.end()){
                 std::cout<<vActual<<", ";
             }

            Arista* i = vActual->ari;

            while (i != nullptr){
                Vertice* vDestino = i->dest;
                i = i->sig;
                iter = std::find(lista.begin(), lista.end(),vDestino);

                if(iter ==lista.end()){
                    pila.push(vDestino);
                }
                i = i->sig;
            }
        }
    }
    else{
        std::cout<<"El vertice especificado no existe"<<std::endl;
    }
}

void Grafo::PrimeroEnAnchura(std::string origen, std::string destino){
    Vertice* vori = ObtenerVertice(origen);
    Vertice* vdest = ObtenerVertice(destino);

    if (vori == nullptr)
        std::cout << "El vertice origen no existe" << std::endl;

    if (vdest == nullptr)
        std::cout << "El vertice destino no existe" << std::endl;

    if (vori != nullptr && vdest != nullptr){
        std::queue<Vertice*> cola;
        std::stack<std::pair<Vertice*, Vertice*>> pilaPar;
        std::list<Vertice*> visitados;
        bool rutaEncontrada = false;
        cola.push(vori);

        while (!cola.empty()){
            Vertice* vActual = cola.front();
            cola.pop();

            std::list<Vertice*>::iterator iter = find(visitados.begin(), visitados.end(), vActual);

            if (iter == visitados.end()){
                if (vActual == vdest){
                    rutaEncontrada = true;
                    MostrarRutaEncontrada(pilaPar, vdest);
                    break;
                }

                visitados.push_back(vActual);
                Arista* i = vActual->ari;

                while (i != nullptr){
                    Vertice* dest = i->dest;
                    iter = find(visitados.begin(), visitados.end(), dest);

                    if (iter == visitados.end()){
                        cola.push(dest);
                        std::pair<Vertice*, Vertice*> par;
                        par.first = vActual;
                        par.second = dest;
                        pilaPar.push(par);
                    }

                    i = i->sig;
                }
            }
        }

        if (!rutaEncontrada)
            std::cout << "No existe una ruta entre esos dos vertices" << std::endl;
    }
}

void Grafo::PrimeroEnProfundidad(std::string origen, std::string destino)
{
    Vertice* vori = ObtenerVertice(origen);
    Vertice* vdest = ObtenerVertice(destino);

    if (vori == nullptr)
        std::cout << "El vertice origen no existe" << std::endl;

    if (vdest == nullptr)
        std::cout << "El vertice destino no existe" << std::endl;

    if (vori != nullptr && vdest != nullptr){
        std::stack<Vertice*> pila;
        std::stack<std::pair<Vertice*, Vertice*>> pilaPar;
        std::list<Vertice*> visitados;
        bool rutaEncontrada = false;
        pila.push(vori);

        while (!pila.empty()){
            Vertice* vActual = pila.top();
            pila.pop();

            std::list<Vertice*>::iterator iter = find(visitados.begin(), visitados.end(), vActual);

            if (iter == visitados.end()){
                if (vActual == vdest){
                    rutaEncontrada = true;
                    MostrarRutaEncontrada(pilaPar, vdest);
                    break;
                }

                visitados.push_back(vActual);
                Arista* i = vActual->ari;

                while (i != nullptr){
                    Vertice* dest = i->dest;
                    iter = std::find(visitados.begin(), visitados.end(), dest);

                    if (iter == visitados.end()){
                        pila.push(dest);
                        std::pair<Vertice*, Vertice*> par;
                        par.first = vActual;
                        par.second = dest;
                        pilaPar.push(par);
                    }

                    i = i->sig;
                }
            }
        }

        if (!rutaEncontrada)
            std::cout << "No existe una ruta entre esos dos vertices" << std::endl;
    }
}

bool OrderPorCosto(const std::pair<Vertice*, int>& a, const std::pair<Vertice*, int>& b){
    return a.second < b.second;
}

void Grafo::PrimeroElMejor(std::string origen, std::string destino){
    Vertice* vori = ObtenerVertice(origen);
    Vertice* vdest = ObtenerVertice(destino);

    if (vori == nullptr)
        std::cout << "El vertice origen no existe" << std::endl;

    if (vdest == nullptr)
        std::cout << "El vertice destino no existe" << std::endl;

    if (vori != nullptr && vdest != nullptr){
        typedef std::pair<Vertice*, int> parVerInt;
        typedef std::pair<Vertice*, Vertice*> parVerVer;
        std::list<parVerInt> costos, costosOrd;
        std::stack<parVerVer> pilaPar;
        bool rutaEncontrada = false;
        parVerInt parVI;
        parVI.first = vori;
        parVI.second = 0;
        costos.push_back(parVI);
        costosOrd.push_back(parVI);

        while (!costosOrd.empty()){
            Vertice* vActual = costosOrd.front().first;
            int costoActual = costosOrd.front().second;
            costosOrd.pop_front();

            if (vActual == vdest){
                rutaEncontrada = true;
                MostrarRutaEncontrada(pilaPar, vdest);
                break;
            }

            Arista* i = vActual->ari;

            while (i != nullptr){
                Vertice* dest = i->dest;
                costoActual += i->precio;

                std::list<parVerInt>::iterator iter = find_if(costos.begin(), costos.end(), [&](const parVerInt& par) { return par.first == dest; });

                if (iter == costos.end()){
                    parVI.first = dest;
                    parVI.second = costoActual;
                    costos.push_back(parVI);
                    costosOrd.push_back(parVI);
                    costosOrd.sort(OrderPorCosto);
                    parVerVer parVV;
                    parVV.first = vActual;
                    parVV.second = dest;
                    pilaPar.push(parVV);}
                else if (costoActual < iter->second){
                    iter->second = costoActual;
                    iter = find_if(costosOrd.begin(), costosOrd.end(), [&](const parVerInt& par) { return par.first == dest; });
                    iter->second = costoActual;
                    costosOrd.sort(OrderPorCosto);
                    parVerVer parVV;
                    parVV.first = vActual;
                    parVV.second = dest;
                    pilaPar.push(parVV);
                }

                costoActual -= i->precio;
                i = i->sig;
            }
        }

        if (!rutaEncontrada)
            std::cout << "No existe una ruta entre esos dos vertices" << std::endl;
    }
}

void Grafo::MostrarRutaEncontrada(std::stack<std::pair<Vertice*, Vertice*>> pilaPar, Vertice* vdest){
    Vertice* destinoActual = vdest;

    while (!pilaPar.empty()){
        std::cout << destinoActual->nombre << "<-";

        while (!pilaPar.empty() && pilaPar.top().second != destinoActual)
            pilaPar.pop();

        if (!pilaPar.empty())
            destinoActual = pilaPar.top().first;
    }
}

bool CostoMinimo(const std::pair<Vertice*, int>& a, const std::pair<Vertice*, int>& b)
{
    return a.second < b.second;
}

void Grafo::Dijkstra(std::string origen){
    Vertice* vorigen = ObtenerVertice(origen);

    if (vorigen == nullptr)
        std::cout << "El vertice origen no existe" << std::endl;
    else{
        std::map<Vertice*, std::map<Vertice*, int>> matriz;
        std::map<Vertice*, bool> visitados;
        std::map<Vertice*, Vertice*> rutas;
        std::map<Vertice*, int> cola;
        std::map<Vertice*, int> distancias;

        Vertice* vi = primero;

        // Inicializar colecciones de datos
        while (vi != nullptr){
            visitados[vi] = false;
            rutas[vi] = nullptr;
            distancias[vi] = std::numeric_limits<int>::max();

            Vertice* vj = primero;

            while (vj != nullptr){
                matriz[vi][vj] = std::numeric_limits<int>::max();
                vj = vj->sig;
            }

            Arista* aj = vi->ari;

            while (aj != nullptr){
                matriz[vi][aj->dest] = aj->precio;
                aj = aj->sig;
            }

            vi = vi->sig;
        }

        distancias[vorigen] = 0;
        visitados[vorigen] = true;
        cola[vorigen] = distancias[vorigen];

        while (!cola.empty()){
            // Encuentra el vertice con el costo menor en la cola
            std::map<Vertice*, int>::iterator iter = min_element(cola.begin(), cola.end(), CostoMinimo);
            visitados[iter->first] = true;

            // Recorre todos los vertices que tiene como destino
            Arista* ai = iter->first->ari;

            while (ai != nullptr){
                if (!visitados[ai->dest])
                {
                    if (distancias[ai->dest] > distancias[iter->first] + matriz[iter->first][ai->dest]){
                        distancias[ai->dest] = distancias[iter->first] + matriz[iter->first][ai->dest];
                        rutas[ai->dest] = iter->first;
                        cola[ai->dest] = distancias[ai->dest];
                    }
                }

                ai = ai->sig;
            }

            cola.erase(iter->first);
        }

        // Muestra los vertices destino con su respectivo peso total
        for (std::map<Vertice*, int>::iterator i = distancias.begin(); i != distancias.end(); i++)
            std::cout << i->first->nombre << ": " << i->second << std::endl;


        // Muestra las rutas completas
        for (std::map<Vertice*, Vertice*>::iterator i = rutas.begin(); i != rutas.end(); i++){
            Vertice* vAct = i->first;

            while (vAct != nullptr){
                std::cout << vAct->nombre << " <- ";
                vAct = rutas[vAct];
            }

            std::cout << std::endl;
        }
    }
}

void Grafo::Kruskal(){
    std::map<Vertice*, std::map<Vertice*, int>> matrizady;
    std::map<Vertice*, std::map<Vertice*, int>> matrizsol;
    std::map<Vertice*, Vertice*> conectados;

    Vertice* vi = primero;

    while (vi != nullptr){
        conectados[vi] = vi;

        Vertice* vj = primero;

        while (vj != nullptr){
            matrizady[vi][vj] = 0;
            vj = vj->sig;
        }

        Arista* aj = vi->ari;

        while (aj != nullptr){
            matrizady[vi][aj->dest] = aj->precio;
            aj = aj->sig;
        }

        vi = vi->sig;
    }


    Vertice* vA, * vB;
    int aristas = 1;

    while (aristas < tamano){
        int min = std::numeric_limits<int>::max();

        for (std::map<Vertice*, std::map<Vertice*, int>>::iterator i = matrizady.begin(); i != matrizady.end(); i++){
            for (std::map<Vertice*, int>::iterator j = i->second.begin(); j != i->second.end(); j++){
                if (j->second < min && j->second != 0 && conectados[i->first] != conectados[j->first]){
                    min = j->second;
                    vA = i->first;
                    vB = j->first;
                }
            }
        }

        if (conectados[vA] != conectados[vB]){
            matrizsol[vA][vB] = min;

            Vertice* vTemp = conectados[vB];
            conectados[vB] = conectados[vA];

            for (std::map<Vertice*, Vertice*>::iterator i = conectados.begin(); i != conectados.end(); i++){
                if (i->second == vTemp)
                    i->second = conectados[vA];
            }

            aristas++;
        }
    }

    for (std::map<Vertice*, std::map<Vertice*, int>>::iterator i = matrizsol.begin(); i != matrizsol.end(); i++){
        for (std::map<Vertice*, int>::iterator j = i->second.begin(); j != i->second.end(); j++){
            std::cout << i->first->nombre << " <-> " << j->second << " <-> " << j->first->nombre << std::endl;
        }
    }

}

void Grafo::Prim(std::string origen){
    Vertice* vOrigen = ObtenerVertice(origen);

    if (vOrigen == nullptr){
        std::cout << "El vertice origen no existe" << std::endl;
        return;
    }

    std::map<Vertice*, std::map<Vertice*, int>> matrizady;
    std::list<std::pair<Vertice*, std::pair<Vertice*, int>>> listaSolucion;
    std::unordered_set<Vertice*> visitados;

    Vertice* vi = primero;

    while (vi != nullptr){
        Vertice* vj = primero;

        while (vj != nullptr){
            matrizady[vi][vj] = 0;
            vj = vj->sig;
        }

        Arista* aj = vi->ari;

        while (aj != nullptr){
            matrizady[vi][aj->dest] = aj->precio;
            aj = aj->sig;
        }

        vi = vi->sig;
    }

    visitados.insert(vOrigen);
    int aristas = 1;

    while (aristas < tamano){
        Vertice* vMinOrigen, * vMinDestino;
        int precioMin = std::numeric_limits<int>::max();

        for (std::unordered_set<Vertice*>::iterator i = visitados.begin(); i != visitados.end(); i++){
            for (std::map<Vertice*, int>::iterator j = matrizady[*i].begin(); j != matrizady[*i].end(); j++){
                if (j->second < precioMin && j->second != 0 && visitados.count(j->first) == 0){
                    precioMin = j->second;
                    vMinOrigen = *i;
                    vMinDestino = j->first;
                }
            }
        }

        listaSolucion.push_back(std::pair<Vertice*, std::pair<Vertice*, int>>(vMinOrigen, std::pair<Vertice*, int>(vMinDestino, precioMin)));
        visitados.insert(vMinDestino);
        aristas++;
    }

    for (std::list<std::pair<Vertice*, std::pair<Vertice*, int>>>::iterator i = listaSolucion.begin(); i != listaSolucion.end(); i++){
        std::cout << i->first->nombre << " <-> " << i->second.second << " <-> " << i->second.first->nombre << std::endl;
    }
}