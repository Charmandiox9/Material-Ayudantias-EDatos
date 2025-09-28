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


Node* rotarListaSegunK(Node* head, int k){
    if(head == nullptr){
        return nullptr;
    }
    
    if(k == 0){
        return head;
    }
    
    Node* aux = head;
    do{
        for(int i = 0; i < k; i++){
            aux = aux -> prev;
        }
        head = aux;
        
    } while(aux != head);
    
    return head;
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
    
    lista = rotarListaSegunK(lista, 15);
    imprimirLista(lista);
}