#### 1. Solución Lógica (Dibujo)
* **Cola Paso 1:** `[0]` (Visitamos Inicio).
* **Cola Paso 2:** Sacamos 0. Entran vecinos `[1, 2]`.
* **Cola Paso 3:** Sacamos 1. Entra vecino `[2, 3]`. (Nota: el 2 ya estaba, depende de la implementación si se duplica o marca visitado, asumimos visitado). Cola real: `[2, 3]`.
* **Cola Paso 4:** Sacamos 2. Vecino es `4` (Fin). **¡Fin encontrado!**
* **Conclusión:** BFS encontró la ruta `0 -> 2 -> 4` (2 saltos) antes que la ruta por arriba `0 -> 1 -> 3 -> 4` (3 saltos).