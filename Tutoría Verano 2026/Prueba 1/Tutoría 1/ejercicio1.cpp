void eliminarUltimo(Nodo* head) {
    Nodo* temp = head;
    while (temp->siguiente != nullptr) {
        temp = temp->siguiente;
    }
    delete temp; 
}