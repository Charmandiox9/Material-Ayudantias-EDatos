struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


Node* linkdelete(Node* head, int n, int m) {
    if(head == nullptr || m == 0) {
        return nullptr;
    }
    
    Node* current = head;
    
    while(current != nullptr) {
        for(int i = 1; i < m && current != nullptr; i++) {
            current = current->next;
        }
        
        if(current == nullptr) {
            break;
        }
        
        Node* nodeToDelete = current->next;
        
        for(int i = 0; i < n && nodeToDelete != nullptr; i++) {
            Node* temp = nodeToDelete;
            nodeToDelete = nodeToDelete->next;
            delete temp;
        }
        
        current->next = nodeToDelete;
        current = nodeToDelete;
    }
    
    return head;
}

