# Ayudantía 7 (P2): AVL

## Ejercicio 1: Inserción y Eliminación en AVL

### Descripción

Inserta los siguientes elementos en un Árbol AVL, mostrando **después de cada inserción**:

1. El árbol resultante
2. El factor de equilibrio (FE) de cada nodo
3. Si se requiere alguna rotación, indica el tipo (LL, RR, LR, RL) y muestra el árbol **antes y después** de la rotación

### Ejercicio

```
Insertar: [10, 5, 7, 4, 20, 15, 30, 35, 45, 25, 12, 1, 6, 8, 9]
Eliminar: [25, 20, 1, 12]

📤 Solucion:

Paso 1: Insertar 10
      10(FE:0)

Paso 2: Insertar 5
        10(FE:1)
       /
    5(FE:0)

Paso 3: Insertar 7 → Desbalance en 10 (FE = 2, caso LR)
       Rotacion LR en 10:

       Antes:          Despues:
           10             7
          /              / \
        5       →       5   10
         \
          7
```

---

**Volver al [README del curso](../../Readme.md)**
