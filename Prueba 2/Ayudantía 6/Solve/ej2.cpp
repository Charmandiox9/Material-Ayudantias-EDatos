class Node {
public:
    int value;
    Node* next;
    
    Node() {
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    
public:
    Stack() : top(nullptr) {}
    
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    int peek() {
        if (top != nullptr) {
            return top->value;
        }
        return -1; // valor inválido
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

bool canBeObtainable(int* pushed, int* popped, int size) {
    Stack stack;
    int popIndex = 0;
    
    // Recorrer todos los elementos de pushed
    for (int i = 0; i < size; i++) {
        stack.push(pushed[i]);
        
        // Mientras el tope coincida con popped, hacer pop
        while (!stack.isEmpty() && stack.peek() == popped[popIndex]) {
            stack.pop();
            popIndex++;
        }
    }
    
    // Si la pila quedó vacía, significa que se pudo obtener popped
    return stack.isEmpty();
}

int main() {
    int pushed1[] = {1, 2, 3, 4, 5};
    int popped1[] = {4, 5, 3, 2, 1};
    std::cout << "Ejemplo 1: " << (canBeObtainable(pushed1, popped1, 5) ? "TRUE" : "FALSE") << std::endl;
    
    int pushed2[] = {1, 2, 3, 4, 5};
    int popped2[] = {4, 3, 5, 1, 2};
    std::cout << "Ejemplo 2: " << (canBeObtainable(pushed2, popped2, 5) ? "TRUE" : "FALSE") << std::endl;
    
    return 0;
}