# 🔗 Ayudantía 3: Simple Linked List

## 📋 Estructura de un Nodo

```cpp
struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
```

---

## 📝 Ejercicio 1: Omitir y Eliminar Nodos

### 🎯 Descripción
Dada una lista enlazada y dos enteros **m** y **n**, la tarea es recorrer la lista enlazada de modo que se **omitan m nodos**, luego se **eliminen los n nodos siguientes** y continúen igual hasta el final de la lista enlazada.

### 💡 Ejemplo
```
📥 Input:  
Linked List: 9→1→3→5→9→4→10→1  
n = 1, m = 2  

📤 Output: 9→1→5→9→10→1
```

### ⚠️ Restricciones
- ✅ El tamaño de la linked list va desde **1-1000**
- ✅ **n** siempre será mayor a **0**
- ✅ **m** siempre será menor o igual al **tamaño de la lista**

---

## 🔄 Ejercicio 2: Fusionar Listas Enlazadas Ordenadas

### 🎯 Descripción
Dada una lista **arr[]** de **n** listas enlazadas ordenadas de diferentes tamaños. Su tarea es **fusionar todas estas listas** en una sola lista enlazada ordenada y devolver el encabezado de la lista combinada.

### 💡 Ejemplo
```
📥 INPUT:
┌─ Lista 1: 1 → 3 → 7 → nullptr
├─ Lista 2: 2 → 4 → 8 → nullptr  
└─ Lista 3: 9 → nullptr

📤 OUTPUT: 1 → 2 → 3 → 4 → 7 → 8 → 9 → nullptr
```

---

*📚 Estructura de Datos*