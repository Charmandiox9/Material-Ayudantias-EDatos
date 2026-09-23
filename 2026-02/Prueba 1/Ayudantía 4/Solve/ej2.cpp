#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node* crearListaDobleCircular(int vals[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(vals[0]);
    head->next = head;
    head->prev = head;
    Node* curr = head;
    for (int i = 1; i < n; i++) {
        Node* nuevo = new Node(vals[i]);
        nuevo->prev = curr;
        nuevo->next = head;
        curr->next = nuevo;
        head->prev = nuevo;
        curr = nuevo;
    }
    return head;
}

Node* eliminarValor(Node* head, int valor) {
    if (head == nullptr) return nullptr;

    if (head->next == head) {
        if (head->data == valor) {
            delete head;
            return nullptr;
        }
        return head;
    }

    Node* originalHead = head;
    bool originalHadValue = (originalHead->data == valor);

    Node* base = nullptr;
    Node* probe = originalHead->next;
    while (probe != originalHead) {
        if (probe->data != valor) {
            base = probe;
            break;
        }
        probe = probe->next;
    }
    if (base == nullptr) {
        if (originalHead->data == valor) {
            Node* curr = originalHead;
            do {
                Node* next = curr->next;
                delete curr;
                curr = next;
            } while (curr != originalHead);
            return nullptr;
        }
    }

    Node* curr = base->next;
    while (curr != base) {
        Node* next = curr->next;
        if (curr->data == valor) {
            curr->prev->next = next;
            next->prev = curr->prev;
            Node* toDelete = curr;
            delete toDelete;
            curr = next;
        } else {
            curr = next;
        }
    }

    if (!originalHadValue) {
        return originalHead;
    }
    return base;
}

void imprimir(Node* head) {
    if (head == nullptr) {
        cout << "(lista vacia)" << endl;
        return;
    }
    Node* curr = head;
    do {
        cout << curr->data;
        if (curr->next != head) cout << " -> ";
        curr = curr->next;
    } while (curr != head);
    cout << " (circular)" << endl;
}

int main() {
    int vals1[] = {1, 2, 3, 2, 4};
    Node* head = crearListaDobleCircular(vals1, 5);
    head = eliminarValor(head, 2);
    imprimir(head);

    int vals2[] = {5, 5, 5};
    Node* head2 = crearListaDobleCircular(vals2, 3);
    head2 = eliminarValor(head2, 5);
    imprimir(head2);

    return 0;
}
