<h1>Resolución Ejercicio 1 </h1>
Para resolver el ejercicio, se deberá detallar a través de la siguiente tabla el comportamiento que van teniendo las distintas variables, llamados y retornos que participan en todo el programa.

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
        <tr class="unique">
            <td>2</td>
            <td class="pointer">2</td>
            <td class="vector">[5,2]</td>
            <td>false</td>
            <td class="action">Avanzar (único)</td>
            <td>2</td>
            <td>5→2→2→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="duplicate">
            <td>3</td>
            <td class="pointer">2</td>
            <td class="vector">[5,2]</td>
            <td>true</td>
            <td class="action">Eliminar duplicado</td>
            <td>2</td>
            <td>5→2→<span class="deleted">2</span>→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="unique">
            <td>4</td>
            <td class="pointer">4</td>
            <td class="vector">[5,2,4]</td>
            <td>false</td>
            <td class="action">Avanzar (único)</td>
            <td>4</td>
            <td>5→2→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="unique">
            <td>5</td>
            <td class="pointer">8</td>
            <td class="vector">[5,2,4,8]</td>
            <td>false</td>
            <td class="action">Avanzar (único)</td>
            <td>8</td>
            <td>5→2→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="unique">
            <td>6</td>
            <td class="pointer">7</td>
            <td class="vector">[5,2,4,8,7]</td>
            <td>false</td>
            <td class="action">Avanzar (único)</td>
            <td>7</td>
            <td>5→2→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="unique">
            <td>7</td>
            <td class="pointer">9</td>
            <td class="vector">[5,2,4,8,7,9]</td>
            <td>false</td>
            <td class="action">Avanzar (único)</td>
            <td>9</td>
            <td>5→2→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="unique">
            <td>8</td>
            <td class="pointer">6</td>
            <td class="vector">[5,2,4,8,7,9,6]</td>
            <td>false</td>
            <td class="action">Avanzar (único)</td>
            <td>6</td>
            <td>5→2→4→8→7→9→6→4→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="duplicate">
            <td>9</td>
            <td class="pointer">4</td>
            <td class="vector">[5,2,4,8,7,9,6]</td>
            <td>true</td>
            <td class="action">Eliminar duplicado</td>
            <td>6</td>
            <td>5→2→4→8→7→9→6→<span class="deleted">4</span>→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="unique">
            <td>10</td>
            <td class="pointer">3</td>
            <td class="vector">[5,2,4,8,7,9,6,3]</td>
            <td>false</td>
            <td class="action">Avanzar (único)</td>
            <td>3</td>
            <td>5→2→4→8→7→9→6→3→2→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="duplicate">
            <td>11</td>
            <td class="pointer">2</td>
            <td class="vector">[5,2,4,8,7,9,6,3]</td>
            <td>true</td>
            <td class="action">Eliminar duplicado</td>
            <td>3</td>
            <td>5→2→4→8→7→9→6→3→<span class="deleted">2</span>→5→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="duplicate">
            <td>12</td>
            <td class="pointer">5</td>
            <td class="vector">[5,2,4,8,7,9,6,3]</td>
            <td>true</td>
            <td class="action">Eliminar duplicado</td>
            <td>3</td>
            <td>5→2→4→8→7→9→6→3→<span class="deleted">5</span>→8→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="duplicate">
            <td>13</td>
            <td class="pointer">8</td>
            <td class="vector">[5,2,4,8,7,9,6,3]</td>
            <td>true</td>
            <td class="action">Eliminar duplicado</td>
            <td>3</td>
            <td>5→2→4→8→7→9→6→3→<span class="deleted">8</span>→4→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="duplicate">
            <td>14</td>
            <td class="pointer">4</td>
            <td class="vector">[5,2,4,8,7,9,6,3]</td>
            <td>true</td>
            <td class="action">Eliminar duplicado</td>
            <td>3</td>
            <td>5→2→4→8→7→9→6→3→<span class="deleted">4</span>→9→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="duplicate">
            <td>15</td>
            <td class="pointer">9</td>
            <td class="vector">[5,2,4,8,7,9,6,3]</td>
            <td>true</td>
            <td class="action">Eliminar duplicado</td>
            <td>3</td>
            <td>5→2→4→8→7→9→6→3→<span class="deleted">9</span>→8→2→2→5→6→3→7→1→5→8</td>
        </tr>
        <tr class="duplicate">
            <td>16-24</td>
            <td class="pointer">8,2,2,5,6,3,7</td>
            <td class="vector">[5,2,4,8,7,9,6,3]</td>
            <td>true</td>
            <td class="action">Eliminar todos (duplicados)</td>
            <td>3</td>
            <td>5→2→4→8→7→9→6→3→<span class="deleted">8,2,2,5,6,3,7</span>→1→5→8</td>
        </tr>
        <tr class="unique">
            <td>25</td>
            <td class="pointer">1</td>
            <td class="vector">[5,2,4,8,7,9,6,3,1]</td>
            <td>false</td>
            <td class="action">Avanzar (único)</td>
            <td>1</td>
            <td>5→2→4→8→7→9→6→3→1→5→8</td>
        </tr>
        <tr class="duplicate">
            <td>26</td>
            <td class="pointer">5</td>
            <td class="vector">[5,2,4,8,7,9,6,3,1]</td>
            <td>true</td>
            <td class="action">Eliminar duplicado</td>
            <td>1</td>
            <td>5→2→4→8→7→9→6→3→1→<span class="deleted">5</span>→8</td>
        </tr>
        <tr class="duplicate">
            <td>27</td>
            <td class="pointer">8</td>
            <td class="vector">[5,2,4,8,7,9,6,3,1]</td>
            <td>true</td>
            <td class="action">Eliminar duplicado</td>
            <td>1</td>
            <td>5→2→4→8→7→9→6→3→1→<span class="deleted">8</span></td>
        </tr>
        <tr class="step">
            <td>Final</td>
            <td>nullptr</td>
            <td class="vector">[5,2,4,8,7,9,6,3,1]</td>
            <td>-</td>
            <td class="action">Terminar</td>
            <td>1</td>
            <td><strong>5→2→4→8→7→9→6→3→1</strong></td>
        </tr>
    </tbody>
</table>

<div style="margin-top: 20px; padding: 15px; background: #fff3e0; border-radius: 5px;">
            <h3>Resumen:</h3>
            <ul>
                <li><strong>Lista original:</strong> 25 nodos</li>
                <li><strong>Lista final:</strong> 9 nodos únicos</li>
                <li><strong>Nodos eliminados:</strong> 16 duplicados</li>
                <li><strong>Vector final:</strong> [5,2,4,8,7,9,6,3,1]</li>
            </ul>
        </div>