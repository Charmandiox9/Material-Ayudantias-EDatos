# Ayudantía 1: Simple Linked List

## Estructura de un nodo
```
struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
```

## Ejercicio 1
Dado el siguiente código, indicar que es lo que va sucediendo línea por línea, y cómo se comportan las variables en cada iteración.

### Código
```
Node *removeDuplicates(Node *head) {
    if(head == nullptr) return nullptr;
    
    if(head -> next == nullptr) return head;
    
    vector<int> numbers;
    Node* current = head;
    Node* prev = nullptr;
    while(current != nullptr){
        if(find(numbers, current -> data)){
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else{
            prev = current;
            current = current -> next;
        }
    }
    return head;
}

bool find(vector<int>& numbers, int number){
    bool found = false;
    
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == number){
            found = true;
            break;
        }
    }
    
    if(!found){
        numbers.push_back(number);
    }
    
    return found;
}
```

### Input
`5 2 2 4 8 7 9 6 4 3 2 5 8 4 9 8 2 2 5 6 3 7 1 5 8`

### Ejemplo de respuesta
<table>
            <thead>
                <tr>
                    <th>Paso</th>
                    <th>current->data</th>
                    <th>Vector numbers</th>
                    <th>find() retorna</th>
                    <th>Acción</th>
                    <th>prev->data</th>
                    <th>Estado Lista</th>
                </tr>
            </thead>
            <tbody>
                <tr class="step">
                    <td>Inicial</td>
                    <td class="pointer">5</td>
                    <td class="vector">[]</td>
                    <td>-</td>
                    <td>Inicialización</td>
                    <td>nullptr</td>
                    <td>5→2→2→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
                </tr>
                <tr class="unique">
                    <td>1</td>
                    <td class="pointer">5</td>
                    <td class="vector">[5]</td>
                    <td>false</td>
                    <td class="action">Avanzar (único)</td>
                    <td>5</td>
                    <td>5→2→2→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
                </tr>
                <tr class="duplicate">
                    <td>3</td>
                    <td class="pointer">2</td>
                    <td class="vector">[5,2]</td>
                    <td>true</td>
                    <td class="action">Eliminar duplicado</td>
                    <td>2</td>
                    <td>5→2→<span class="deleted">𝟐̸</span>→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
                </tr>
            </tbody>
</table>

---

## Ejercicio 2
Dado el siguiente código, indicar que es lo que va sucediendo línea por línea, y cómo se comportan las variables en cada iteración.

### Código
```
long long multiplyTwoLists(Node *first, Node *second) {
    if(first == nullptr || second == nullptr) {
        return 0;
    }
        
    long long firstNumber = convertToNumber(first);
    long long secondNumber = convertToNumber(second);
    return (firstNumber * secondNumber);
}
    
long long convertToNumber(Node* head) {
    long long num = 0;
    while (head != nullptr) {
        num = (num * 10 + head->data);
        head = head->next;
    }
    return num;
}
```

### Input
`1->2->5`
`2->3`

### Ejemplo de respuesta
- <h4>Ejecución principal</h4>
<table>
    <thead>
        <tr>
            <th>Paso</th>
            <th>Variable</th>
            <th>Valor</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbdoy>
        <tr class="step">
            <td>1</td>
            <td>first</td>
            <td>ptr -> 1->2->5</td>
            <td>Puntero a primera lista</td>
        </tr>
        <tr class="step">
            <td>4</td>
            <td>Llamada</td>
            <td>convertToNumber(first)</td>
            <td>Convierte primera lista</td>
        </tr>
    </tbody>
</table>

- <h4>Detalle - convertToNumber(first) → Lista: 1→2→5</h4>
<table>
    <thead>
        <tr>
            <th>Paso</th>
            <th>head -> data</th>
            <th>num</th>
            <th>Cálculo completo</th>
            <th>Resultado</th>
        </tr>
    </thead>
    <tbdoy>
        <tr class="step">
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>(0 × 10) + 1 = 0 + 1</td>
            <td>1</td>
        </tr>
    </tbody>
</table>

- <h4>Paso a Paso Detallado - Primera Lista</h4>
<table>
    <thead>
        <tr>
            <th>Iteración</th>
            <th>head -> data</th>
            <th>num (antes)</th>
            <th>Operación</th>
            <th>num (después)</th>
            <th>head (siguiente)</th>
        </tr>
    </thead>
    <tbdoy>
        <tr class="step">
            <td>Inicial</td>
            <td>-</td>
            <td>0</td>
            <td>Inicialización</td>
            <td>0</td>
            <td>ptr → 1→2→5</td>
        </tr>
        <tr class="step">
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>0 * 10 + 1</td>
            <td>1</td>
            <td>ptr → 2→5</td>
        </tr>
    </tbody>
</table>
