
struct Node{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};



class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        if(head1 == nullptr || head2 == nullptr){
            return nullptr;
        }
        
        if(head1 -> next == nullptr && head2 -> next == nullptr){
            if(head1 -> data == head2 -> data){
                return new Node(head1 -> data);
            } else{
                return nullptr;
            }
        }
        
        Node* intersectionList = nullptr;
        Node* aux1 = head1;
        
        while(aux1 != nullptr){
            Node* aux2 = head2;
            while(aux2 != nullptr){
                if(aux1 -> data == aux2 -> data){
                    if(intersectionList == nullptr){
                        intersectionList = new Node(aux1 -> data);
                    } else{
                        Node* auxIntersection = intersectionList;
                        while(auxIntersection -> next != nullptr){
                            auxIntersection = auxIntersection -> next;
                        }
                        
                        auxIntersection -> next = new Node(aux1 -> data);
                    }
                    aux2 = aux2 -> next;
                } else{
                    aux2 = aux2 -> next;
                }
            }
            aux1 = aux1 -> next;
        }
        
        return intersectionList;
    }
};