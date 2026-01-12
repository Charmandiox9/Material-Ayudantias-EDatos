struct Nodo {
    int dato;
    Nodo* siguiente;
    
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

Nodo* sumaDeListas(Nodo *head1, Nodo* head2) {
    Nodo* resultado = nullptr;
    Nodo* tail = nullptr;
    int carry = 0;
    
    while (head1 != nullptr || head2 != nullptr || carry > 0) {
        int suma = carry;
        
        if (head1 != nullptr) {
            suma += head1->dato;
            head1 = head1->siguiente;
        }
        
        if (head2 != nullptr) {
            suma += head2->dato;
            head2 = head2->siguiente;
        }
        
        carry = suma / 10;
        int digito = suma % 10;
        
        Nodo* nuevoNodo = new Nodo(digito);
        
        if (resultado == nullptr) {
            resultado = nuevoNodo;
            tail = nuevoNodo;
        } else {
            tail->siguiente = nuevoNodo;
            tail = nuevoNodo;
        }
    }
    
    return resultado;
}