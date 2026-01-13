struct Nodo {
    int dato;
    Nodo* siguiente;
};

Nodo* invertirLista(Nodo*& cabeza) {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) return;

    Nodo* prev = nullptr;
    Nodo* curr = cabeza;
    Nodo* next = nullptr;

    while (curr != nullptr) {
        // Se Guarda la referencia al resto de la lista 
        next = curr->siguiente;
        
        // Se invierte el enlace actual
        curr->siguiente = prev;
        
        // Se mueven los punteros una posición adelante
        prev = curr;
        curr = next;
    }
    return prev;
}