#include <iostream>
using namespace std;

struct NodeDLL {
    int data;
    NodeDLL* next;
    NodeDLL* prev;

    NodeDLL(int x) : data(x), next(nullptr), prev(nullptr) {}
};

NodeDLL* rotateRight(NodeDLL* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    // Calcular longitud
    int n = 0;
    NodeDLL* curr = head;
    while (curr != nullptr) {
        n++;
        curr = curr->next;
    }

    if (k > n) {
        k = k % n;
    }

    // Encontrar el nodo en la posicion (n - k) para ver la nueva cola
    int steps = n - k;
    NodeDLL* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    NodeDLL* newHead = newTail->next;

    // Desconectar newTail del resto
    newTail->next = nullptr;
    newHead->prev = nullptr;

    // Conectar el final con el head original
    NodeDLL* oldTail = newHead;
    while (oldTail->next != nullptr) {
        oldTail = oldTail->next;
    }
    oldTail->next = head;
    head->prev = oldTail;

    return newHead;
}

void printList(NodeDLL* head) {
    NodeDLL* curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    NodeDLL* head = new NodeDLL(1);
    NodeDLL* curr = head;
    for (int i = 2; i <= 5; i++) {
        curr->next = new NodeDLL(i);
        curr->next->prev = curr;
        curr = curr->next;
    }

    cout << "Lista original: ";
    printList(head);

    int k = 2;
    NodeDLL* newHead = rotateRight(head, k);

    cout << "Lista rotada k=" << k << ": ";
    printList(newHead);

    return 0;
}