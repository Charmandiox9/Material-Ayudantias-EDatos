#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* moverUltimaAlFrente(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* ultima = head;
    Node* preUltima = head;

    while (ultima->next != nullptr) {
        preUltima = ultima;
        ultima = ultima->next;
    }

    preUltima->next = nullptr;
    ultima->next = head;
    return ultima;
}

void imprimir(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original: ";
    imprimir(head);  // 1 -> 2 -> 3 -> 4

    head = moverUltimaAlFrente(head);

    cout << "Despues:  ";
    imprimir(head);  // 4 -> 1 -> 2 -> 3

    return 0;
}
