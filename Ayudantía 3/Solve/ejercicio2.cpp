struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* mergeKLists(vector<Node*>& arr) {
    if(arr.size() == 0){
        return nullptr;
    }
    
    if(arr.size() == 1){
        return arr[0];
    }
    
    while(arr.size() > 1) {
        vector<Node*> mergedLists;
        
        for(int i = 0; i < arr.size(); i += 2) {
            Node* l1 = arr[i];
            Node* l2 = (i + 1 < arr.size()) ? arr[i + 1] : nullptr;
            mergedLists.push_back(mergeTwoLists(l1, l2));
        }
        
        arr = mergedLists;
    }
    
    return arr[0];
}

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* current = &dummy;
    
    while(l1 != nullptr && l2 != nullptr) {
        if(l1->data <= l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    if(l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }
    
    return dummy.next;
}

