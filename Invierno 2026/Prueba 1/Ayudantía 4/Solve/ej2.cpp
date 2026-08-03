#include <iostream>
using namespace std;

struct NodeDLL {
    int data;
    NodeDLL* next;
    NodeDLL* prev;

    NodeDLL(int x) : data(x), next(nullptr), prev(nullptr) {}
};

int josephus(NodeDLL* head, int k) {
    if (head == nullptr || k <= 0) {
        return -1;
    }

    NodeDLL* current = head;
    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            current = current->next;
        }

        NodeDLL* nextNode = current->next;
        current->prev->next = nextNode;
        nextNode->prev = current->prev;

        delete current;
        current = nextNode;
    }

    int result = current->data;
    delete current;
    return result;
}

int main() {
    // Crear lista circular con n=7 y ejecutar josephus con k=3
    int n1 = 7, k1 = 3;
    NodeDLL* head1 = new NodeDLL(1);
    NodeDLL* curr1 = head1;
    for (int i = 2; i <= n1; i++) {
        curr1->next = new NodeDLL(i);
        curr1->next->prev = curr1;
        curr1 = curr1->next;
    }
    curr1->next = head1;
    head1->prev = curr1;

    cout << "Josephus(n=" << n1 << ", k=" << k1 << "): "
              << josephus(head1, k1) << endl;

    // Crear lista circular con n=5 y ejecutar josephus con k=2
    int n2 = 5, k2 = 2;
    NodeDLL* head2 = new NodeDLL(1);
    NodeDLL* curr2 = head2;
    for (int i = 2; i <= n2; i++) {
        curr2->next = new NodeDLL(i);
        curr2->next->prev = curr2;
        curr2 = curr2->next;
    }
    curr2->next = head2;
    head2->prev = curr2;

    cout << "Josephus(n=" << n2 << ", k=" << k2 << "): " << josephus(head2, k2) << endl;

    return 0;
}