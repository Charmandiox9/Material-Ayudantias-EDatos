#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = this; // se apunta a sí mismo
        prev = this;
    }
};


Node *reverseKGroup(Node *head, int k) {
    if (head == nullptr || k <= 1) {
        return head;
    }

    if (head->next == head) {
        return head; // solo un nodo
    }


    // Romper temporalmente la circularidad
    Node* tail = head->prev;
    tail->next = nullptr;
    head->prev = nullptr;

    Node* curr = head;
    Node* newHead = nullptr;
    Node* lastGroupTail = nullptr;

    while (curr != nullptr) {
        // Verificar si hay al menos k nodos restantes
        Node* temp = curr;
        int available = 0;
        while (temp != nullptr && available < k) {
            temp = temp->next;
            available++;
        }

        if (available < k) {
            // No hay suficientes nodos para un grupo completo
            if (lastGroupTail != nullptr) {
                lastGroupTail->next = curr;
                curr->prev = lastGroupTail;
            }
            break;
        }

        // Reversar el grupo de k nodos
        Node* groupHead = curr;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;

        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = next; // temporal, se corregirá después
            prev = curr;
            curr = next;
            count++;
        }

        // Corregir punteros prev del grupo reversado
        temp = prev;
        while (temp != nullptr && temp != curr) {
            if (temp->next != nullptr) {
                temp->next->prev = temp;
            }
            temp = temp->next;
        }

        // Conectar con el grupo anterior
        if (newHead == nullptr) {
            newHead = prev; // primer grupo reversado
        } else {
            lastGroupTail->next = prev;
            prev->prev = lastGroupTail;
        }

        lastGroupTail = groupHead;
    }

    // Restaurar la circularidad
    if (newHead != nullptr) {
        Node* newTail = newHead->prev;
        while (newTail->next != nullptr) {
            newTail = newTail->next;
        }
        
        newTail->next = newHead;
        newHead->prev = newTail;
    }

    return newHead;
}

Node* generarLista(Node* head, Node* nuevo){
    if(head == nullptr){
        return nuevo; // primer nodo, ya apunta a sí mismo
    }
    
    Node* tail = head->prev; // último nodo
    tail->next = nuevo;
    nuevo->prev = tail;
    nuevo->next = head;
    head->prev = nuevo;

    return head; // head se mantiene
}

void imprimirLista(Node* head){
    if(head == nullptr){
        cout << "Lista vacía" << endl;
        return;
    }
    
    Node* aux = head;
    do {
        cout << aux->data << " <-> ";
        aux = aux->next;
    } while(aux != head);
    
    cout << "(circular)" << endl;
}

int main()
{
    Node* lista = nullptr;
    for(int i = 0; i < 20; i++){
        lista = generarLista(lista, new Node(i+1));
    }
    
    
    imprimirLista(lista);
    
    lista = reverseKGroup(lista, 4);
    imprimirLista(lista);
}