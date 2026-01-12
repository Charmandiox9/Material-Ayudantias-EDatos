struct Nodo {
    int dato;
    Nodo* siguiente;
    
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

Nodo* rotarSublista(Nodo* head, int m, int n, int k) {
    if (!head || m == n || k == 0) return head;
    
    int tamanoSublista = n - m + 1;
    k = k % tamanoSublista;
    if (k == 0) return head;
    
    Nodo* prevM = nullptr; 
    Nodo* nodoM = head;
    Nodo* nodoN = nullptr;
    Nodo* siguienteN = nullptr;
    
    Nodo* actual = head;
    int posicion = 1;
    
    while (actual) {
        if (posicion == m - 1) {
            prevM = actual;
        }
        
        if (posicion == m) {
            nodoM = actual;
        }
        
        if (posicion == n) {
            nodoN = actual;
            siguienteN = actual->siguiente;
            break;
        }
        
        actual = actual->siguiente;
        posicion++;
    }
    
    if (prevM) prevM->siguiente = nullptr;
    nodoN->siguiente = nullptr;
    
    int cortarEn = tamanoSublista - k;
    
    Nodo* nuevaCola = nodoM;
    for (int i = 1; i < cortarEn; i++) {
        nuevaCola = nuevaCola->siguiente;
    }
    
    Nodo* nuevaCabeza = nuevaCola->siguiente;
    nuevaCola->siguiente = nullptr;
    

    Nodo* finNuevaCabeza = nuevaCabeza;
    while (finNuevaCabeza->siguiente) {
        finNuevaCabeza = finNuevaCabeza->siguiente;
    }
    

    finNuevaCabeza->siguiente = nodoM;
    
    if (prevM) {
        prevM->siguiente = nuevaCabeza;
    } else {
        head = nuevaCabeza;
    }
    
    Nodo* finSublista = nuevaCabeza;
    while (finSublista->siguiente) {
        finSublista = finSublista->siguiente;
    }
    finSublista->siguiente = siguienteN;
    
    return head;
}