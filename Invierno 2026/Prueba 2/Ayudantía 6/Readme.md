# Ayudantía 6 (P2): Recorridos en Árboles Binarios

## Estructura Base

Para ambos ejercicios se utiliza la siguiente estructura de nodo:

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

## Ejercicio 1: Recorridos en Árboles Binarios

### Descripción

Dado un árbol binario, explica brevemente en qué consiste cada recorrido
(preorder, inorder, postorder) y luego implementa una función para cada uno.
Las funciones deben imprimir por consola los valores visitados, separados
por espacio, en el orden correspondiente.

Implementa las funciones:

```cpp
void preorder(TreeNode* root);
void inorder(TreeNode* root);
void postorder(TreeNode* root);
```

### Ejemplo

```
        1
       / \
      2   3
     / \   \
    4   5   6

Preorder: 1 2 4 5 3 6
Inorder: 4 2 5 1 3 6
Postorder: 4 5 2 6 3 1
```

---

## Ejercicio 2: Generación de Árboles Binarios

### Descripción

Dados dos vectores que representan las secuencias de inorder y postorder
de un árbol binario, devuelve el árbol binario generado.

Implementa la función:

```cpp
TreeNode* generateBinaryTree(std::vector<int> inorder, std::vector<int> postorder);
```

**Consideraciones:**

- Se recomienda utilizar recursividad para la resolución del problema.
- Los vectores dados se entregan como `vector<int>`.
- Deben utilizar la clase `TreeNode` provista para la creación del árbol binario.

### Ejemplo

```
inorder = {4, 2, 5, 1, 6, 3, 7}
postorder = {4, 5, 2, 6, 7, 3, 1}

Output:
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

---

**Volver al [README del curso](../../Readme.md)**
