struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        if(head == nullptr || m == 0) {
            return nullptr;
        }
        
        Node* current = head;
        
        while(current != nullptr) {
            // Avanzar m-1 posiciones (ya estamos en la primera)
            for(int i = 1; i < m && current != nullptr; i++) {
                current = current->next;
            }
            
            // Si current es nullptr, hemos llegado al final
            if(current == nullptr) {
                break;
            }
            
            // Guardar el nodo desde donde vamos a eliminar
            Node* nodeToDelete = current->next;
            
            // Eliminar los siguientes n nodos
            for(int i = 0; i < n && nodeToDelete != nullptr; i++) {
                Node* temp = nodeToDelete;
                nodeToDelete = nodeToDelete->next;
                delete temp;
            }
            
            // Conectar el último nodo mantenido con el siguiente grupo
            current->next = nodeToDelete;
            current = nodeToDelete;
        }
        
        return head;
    }
};