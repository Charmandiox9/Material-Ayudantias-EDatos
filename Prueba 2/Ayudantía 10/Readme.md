# 🔗 Ayudantía 10: Binary Tree y Teoría de Grafos

## 📝 Ejercicio 1: Teoría de árboles

### 🎯 Descripción
Dado el siguiente árbol binario, responda:

1. ¿Cuál es la altura del árbol?
2. ¿Cuántos nodos hoja tiene?
3. Indique el recorrido **preorder**
4. Indique el recorrido **inorder**
5. Indique el recorrido **postorder**
6. ¿Es un árbol binario de búsqueda (BST)? Justifique.

### 💡 Ejemplo
```
         50
        /  \
      30    70
     /  \   /  \
   20   40 60  80
   /
  10
```

---

## 📝 Ejercicio 2: Teoría de grafos

### 🎯 Descripción
Suponga una empresa de entregas que debe encontrar la ruta más corta desde el punto A al punto F. 

1. Liste todos los caminos posibles desde A hasta F
2. Calcule la distancia total en KM de cada camino
3. Determine cuál es el camino más corto
4. ¿Qué algoritmo usaría para encontrar el camino mas corto?

### 💡 Ejemplo
```
Grafo (distancias en KM):

    A ---8--- B ---7--- C
    |         |         |
    4         3         5
    |         |         |
    D ---2--- E ---6--- F
    |                   |
    10------------------+

Aristas:
A-B: 8 km
A-D: 4 km
B-C: 7 km
B-E: 3 km
C-F: 5 km
D-E: 2 km
D-F: 10 km
E-F: 6 km
```

---

## 📝 Ejercicio 3: Árboles

### 🎯 Descripción
Generar una función que construya un árbol binario dados los recorridos **preorder** y **inorder**.

Los nodos del árbol tienen la siguiente estructura:

```
Class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
        ~TreeNode(){}
};
```

### 💡 Ejemplo
```
📥 Input: 
preOrder:  [5, 3, 2, 4, 8, 7, 9]
inOrder:   [2, 3, 4, 5, 7, 8, 9]

📤 Output (árbol construido):
         5
        / \
       3   8
      / \ / \
     2  4 7  9

```

- Se recomienda utilizar recursividad.
- los recorridos preorder y inorder se entregan en forma de vector<int> preOrder, vector<int> inOrder.

---
