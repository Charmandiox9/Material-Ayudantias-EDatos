# Ayudantía 1: Punteros y referencias
- **Variable normal**: int x = 10;
- **Dirección de memoria** (señala la posición de la memoria donde se encuentra una variable): &x
- **Puntero** (Variable que almacena una dirección de memoria): int* ptr = &x;
- **Referencia** (permite acceder al valor guardado dentro de una dirección de memoria): int& ref = x; 

## Ejercicio
Cree un programa que:
1. Pida al usuario 3 números enteros.
2. Guarde esos números en un arreglo.
3. Use un puntero para recorrer el arreglo y mostrar los valores junto a sus direcciones de memoria.
4. Cree una referencia hacia el primero número del arreglo y modifiquelo mediante la referencia.
5. Recorra nuevamente el arreglo mostrando los valores y direcciones de memoria.

## Extra
- Use la librería `vector` para crear un array.
- Con el método `push_back` puede insertar elementos al arreglo.


## Ejemplo de salida.
```
Ingrese su número 1: 5
Ingrese su número 2: 9
Ingrese su número 3: 12

Array original
Pos 0 -> Valor: 5 dirección: 0x6381eac76ad0
Pos 1 -> Valor: 9 dirección: 0x6381eac76ad4
Pos 2 -> Valor: 12 dirección: 0x6381eac76ad8

Array modificado
Pos 0 -> Valor: 14 dirección: 0x6381eac76ad0
Pos 1 -> Valor: 9 dirección: 0x6381eac76ad4
Pos 2 -> Valor: 12 dirección: 0x6381eac76ad8
```