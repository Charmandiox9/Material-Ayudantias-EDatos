#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* detectAndRemoveCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = nullptr;
            return head;
        }
    }
    return head;
}

void imprimirLista(Node* head, int maxNodos = 20) {
    Node* actual = head;
    int contador = 0;
    while (actual != nullptr && contador < maxNodos) {
        cout << actual->data;
        if (actual->next != nullptr) cout << " -> ";
        actual = actual->next;
        contador++;
    }
    cout<<endl;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;

    cout << "Lista con ciclo (mostrando solo los primeros 10 nodos:\n";
    imprimirLista(n1, 10);

    Node* resultado = detectAndRemoveCycle(n1);

    cout << "\nLista despues de eliminar el ciclo:\n";
    imprimirLista(resultado);

    //liberar memoria
    Node* actual = resultado;
    while (actual != nullptr) {
        Node* siguiente = actual->next;
        delete actual;
        actual = siguiente;
    }

    return 0;
}