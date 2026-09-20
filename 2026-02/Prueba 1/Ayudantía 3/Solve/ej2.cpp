#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* crearListaCircular(int n) {
    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2; i <= n; i++) {
        curr->next = new Node(i);
        curr = curr->next;
    }
    curr->next = head;
    return head;
}

int josephus(Node* head, int k) {
    if (head == nullptr || k <= 0) {
        throw invalid_argument("head no puede ser nullptr y k debe ser positivo");
    }

    Node* current = head;
    Node* prev = head;
    while (prev->next != head) {
        prev = prev->next;
    }

    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }

    int sobreviviente = current->data;
    delete current;
    return sobreviviente;
}

int main() {
    Node* lista1 = crearListaCircular(7);
    cout << josephus(lista1, 3) << endl;  // 4

    Node* lista2 = crearListaCircular(5);
    cout << josephus(lista2, 2) << endl;  // 3

    return 0;
}
