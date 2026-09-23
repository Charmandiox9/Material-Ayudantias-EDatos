#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node* invertir(Node* head) {
    Node* curr = head;
    Node* newHead = nullptr;
    Node* temp = nullptr;

    while (curr != nullptr) {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        newHead = curr;
        curr = temp;
    }

    return newHead;
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
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    head->next = n2;  n2->prev = head;
    n2->next = n3;    n3->prev = n2;

    cout << "Original: ";
    imprimir(head);

    head = invertir(head);

    cout << "Invertida:";
    imprimir(head);

    return 0;
}
