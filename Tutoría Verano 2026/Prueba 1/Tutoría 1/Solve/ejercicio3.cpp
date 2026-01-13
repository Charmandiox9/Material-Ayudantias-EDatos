Nodo* fusionarListas(Nodo* l1, Nodo* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    Nodo* cabezaFusionada = nullptr;
    
    // Se determina quién es la cabeza inicial
    if (l1->dato <= l2->dato) {
        cabezaFusionada = l1;
        l1 = l1->siguiente;
    } else {
        cabezaFusionada = l2;
        l2 = l2->siguiente;
    }

    // Puntero para ir construyendo la lista
    Nodo* actual = cabezaFusionada;

    // Bucle mientras ambas tengan elementos
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->dato <= l2->dato) {
            actual->siguiente = l1;
            l1 = l1->siguiente;
        } else {
            actual->siguiente = l2;
            l2 = l2->siguiente;
        }
        actual = actual->siguiente;
    }

    // Se pega el resto (si una lista se acabó antes que la otra)
    if (l1 != nullptr) {
        actual->siguiente = l1;
    } else {
        actual->siguiente = l2;
    }

    return cabezaFusionada;
}