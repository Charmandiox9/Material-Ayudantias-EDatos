void eliminarUltimo(Nodo*& head) {
    if(head == nullptr) {
        return;
    }
    
    if(head->siguiente == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Nodo* prev = nullptr;
    Nodo* temp = head;
    
    while (temp->siguiente != nullptr) {
        prev = temp;
        temp = temp->siguiente;
    }
    
    prev->siguiente = nullptr;
    delete temp;
}