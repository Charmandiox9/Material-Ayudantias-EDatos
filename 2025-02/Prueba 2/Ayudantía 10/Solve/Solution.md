# 🔗 Ayudantía 10: Binary Tree y Teoría de Grafos


## 📝 Ejercicio 1: Teoría de árboles
**Soluciones:**
- a) Altura = 3 (contando desde la raíz hasta el nodo más profundo)
- b) Nodos hoja = 4 (10, 40, 60, 80)
- c) Preorder: 50, 30, 20, 10, 40, 70, 60, 80
- d) Inorder: 10, 20, 30, 40, 50, 60, 70, 80
- e) Postorder: 10, 20, 40, 30, 60, 80, 70, 50
- f) Sí, es un BST porque todos los nodos del subárbol izquierdo son menores que la raíz y todos los del subárbol derecho son mayores.

---

## 📝 Ejercicio 2: Teoría de grafos
**Solución:**

**Caminos posibles de A a F:**
1. A → B → C → F: 8 + 7 + 5 = 20 km
2. A → B → E → F: 8 + 3 + 6 = 17 km
3. A → D → E → F: 4 + 2 + 6 = 12 km ✓ (más corto)
4. A → D → F: 4 + 10 = 14 km

**Camino más corto:** A → D → E → F con 12 km

**Algortimo más óptimo:** Dado que el grafo tiene es ponderado, el mejor algortimo es **Dijkstra**, ay que este busca el camino mas corto en base a los pesos que tengan las aristas, en cambio, **BFS** no considera pesos, por lo que este no sería un grafo adecuado para ocuparlo, y **DFS** no garantiza un camino optimo, solo encuentra el camino.

---

## 📝 Ejercicio 3: Árboles

### 🔍 Algoritmo sugerido:
```
TreeNode* buildTree(vector& preorder, vector& inorder) {
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }
    
    // El primer elemento del preorder es la raíz
    int rootVal = preorder[0];
    TreeNode* root = new TreeNode(rootVal);
    
    // Encontrar la posición de la raíz en inorder
    int rootIndex = 0;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }
    
    // Dividir inorder en izquierda y derecha
    vector leftInorder(inorder.begin(), inorder.begin() + rootIndex);
    vector rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
    
    // Dividir preorder en izquierda y derecha
    vector leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
    vector rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());
    
    // Construir recursivamente subárboles
    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);
    
    return root;
}
```
### 💭 Hints:
- El primer elemento de **preorder** siempre es la raíz
- En **inorder**, los elementos a la izquierda de la raíz forman el subárbol izquierdo
- Los elementos a la derecha forman el subárbol derecho
- Aplicar recursividad para construir cada subárbol

---

## 🎓 Conceptos Clave

### Recorridos de Árbol:
- **Preorder (NLR):** Raíz → Izquierda → Derecha
- **Inorder (LNR):** Izquierda → Raíz → Derecha (en BST da orden ascendente)
- **Postorder (LRN):** Izquierda → Derecha → Raíz

### Grafos:
- **BFS (Breadth-First Search):** Explora por niveles, usa cola
- **DFS (Depth-First Search):** Explora en profundidad, usa pila/recursión
- **Dijkstra:** Encuentra camino más corto con pesos positivos