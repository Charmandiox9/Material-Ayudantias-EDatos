<style>
table {
    border-collapse: collapse;
    width: 100%;
    margin: 20px 0;
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
    border-radius: 8px;
    overflow: hidden;
}

thead {
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
    color: white;
}

thead th {
    padding: 15px 12px;
    text-align: left;
    font-weight: 600;
    text-transform: uppercase;
    font-size: 0.85em;
    letter-spacing: 0.5px;
}

tbody td {
    padding: 12px;
    border-bottom: 1px solid #e0e0e0;
    transition: background-color 0.3s ease;
}

tbody tr:nth-child(even) {
    background-color: #f8f9fa;
}

tbody tr:hover {
    background-color: #e3f2fd;
}

.step {
    background-color: #e8f5e8 !important;
    font-weight: 500;
}

.initial {
    background-color: #fff3e0 !important;
    border-left: 4px solid #ff9800;
}

.final {
    background-color: #e8f5e8 !important;
    border-left: 4px solid #4caf50;
    font-weight: bold;
}

.highlight {
    background-color: #fff9c4 !important;
    font-weight: bold;
    color: #f57c00;
}

code {
    background-color: #f5f5f5;
    padding: 2px 6px;
    border-radius: 4px;
    font-family: 'Consolas', 'Monaco', 'Courier New', monospace;
    font-size: 0.9em;
    color: #d63384;
}

h4 {
    background: linear-gradient(45deg, #667eea, #764ba2);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    background-clip: text;
    margin: 30px 0 15px 0;
    font-size: 1.2em;
    font-weight: 600;
    border-bottom: 2px solid #667eea;
    padding-bottom: 5px;
}

.big-number {
    font-size: 1.1em;
    font-weight: bold;
    color: #1976d2;
}

.operation::before {
    margin-right: 5px;
}

.conversion::before {
    margin-right: 5px;
}

.result::before {
    margin-right: 5px;
}
</style>

- <h4>Ejecución Principal</h4>
<table>
    <thead>
        <tr>
            <th>Paso</th>
            <th>Variable</th>
            <th>Valor</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
        <tr class="initial">
            <td>1</td>
            <td><code>first</code></td>
            <td>ptr → 1→2→5</td>
            <td>Puntero a primera lista</td>
        </tr>
        <tr class="initial">
            <td>2</td>
            <td><code>second</code></td>
            <td>ptr → 2→3</td>
            <td>Puntero a segunda lista</td>
        </tr>
        <tr class="step">
            <td>3</td>
            <td>Validación</td>
            <td><code>first != nullptr && second != nullptr</code></td>
            <td>Ambas listas son válidas</td>
        </tr>
        <tr class="operation">
            <td>4</td>
            <td>Llamada</td>
            <td><code>convertToNumber(first)</code></td>
            <td class="conversion">Convierte primera lista</td>
        </tr>
        <tr class="highlight">
            <td>5</td>
            <td><code>firstNumber</code></td>
            <td class="big-number">125</td>
            <td class="result">Resultado de la conversión</td>
        </tr>
        <tr class="operation">
            <td>6</td>
            <td>Llamada</td>
            <td><code>convertToNumber(second)</code></td>
            <td class="conversion">Convierte segunda lista</td>
        </tr>
        <tr class="highlight">
            <td>7</td>
            <td><code>secondNumber</code></td>
            <td class="big-number">23</td>
            <td class="result">Resultado de la conversión</td>
        </tr>
        <tr class="final">
            <td>8</td>
            <td><code>return</code></td>
            <td class="big-number">125 × 23 = 2875</td>
            <td>Multiplicación final</td>
        </tr>
    </tbody>
</table>

- <h4>Detalle - convertToNumber(first) → Lista: 1→2→5</h4>
<table>
    <thead>
        <tr>
            <th>Iteración</th>
            <th>head→data</th>
            <th>num (antes)</th>
            <th>Operación</th>
            <th>num (después)</th>
            <th>head (siguiente)</th>
        </tr>
    </thead>
    <tbody>
        <tr class="initial">
            <td>Inicial</td>
            <td>-</td>
            <td>0</td>
            <td>Inicialización</td>
            <td>0</td>
            <td>ptr → 1→2→5</td>
        </tr>
        <tr class="step">
            <td>1</td>
            <td class="big-number">1</td>
            <td>0</td>
            <td><code>0 × 10 + 1</code></td>
            <td class="big-number">1</td>
            <td>ptr → 2→5</td>
        </tr>
        <tr class="step">
            <td>2</td>
            <td class="big-number">2</td>
            <td>1</td>
            <td><code>1 × 10 + 2</code></td>
            <td class="big-number">12</td>
            <td>ptr → 5</td>
        </tr>
        <tr class="step">
            <td>3</td>
            <td class="big-number">5</td>
            <td>12</td>
            <td><code>12 × 10 + 5</code></td>
            <td class="big-number">125</td>
            <td>nullptr</td>
        </tr>
        <tr class="final">
            <td>Final</td>
            <td>-</td>
            <td class="big-number">125</td>
            <td>Retorno</td>
            <td class="big-number">125</td>
            <td>-</td>
        </tr>
    </tbody>
</table>

- <h4>Paso a Paso Detallado - Primera Lista</h4>
<table>
    <thead>
        <tr>
            <th>Paso</th>
            <th>head→data</th>
            <th>num</th>
            <th>Cálculo completo</th>
            <th>Resultado</th>
        </tr>
    </thead>
    <tbody>
        <tr class="step">
            <td>1</td>
            <td class="big-number">1</td>
            <td>0</td>
            <td><code>(0 × 10) + 1 = 0 + 1</code></td>
            <td class="big-number">1</td>
        </tr>
        <tr class="step">
            <td>2</td>
            <td class="big-number">2</td>
            <td>1</td>
            <td><code>(1 × 10) + 2 = 10 + 2</code></td>
            <td class="big-number">12</td>
        </tr>
        <tr class="step">
            <td>3</td>
            <td class="big-number">5</td>
            <td>12</td>
            <td><code>(12 × 10) + 5 = 120 + 5</code></td>
            <td class="big-number">125</td>
        </tr>
    </tbody>
</table>

- <h4>Detalle - convertToNumber(second) → Lista: 2→3</h4>
<table>
    <thead>
        <tr>
            <th>Iteración</th>
            <th>head→data</th>
            <th>num (antes)</th>
            <th>Operación</th>
            <th>num (después)</th>
            <th>head (siguiente)</th>
        </tr>
    </thead>
    <tbody>
        <tr class="initial">
            <td>Inicial</td>
            <td>-</td>
            <td>0</td>
            <td>Inicialización</td>
            <td>0</td>
            <td>ptr → 2→3</td>
        </tr>
        <tr class="step">
            <td>1</td>
            <td class="big-number">2</td>
            <td>0</td>
            <td><code>0 × 10 + 2</code></td>
            <td class="big-number">2</td>
            <td>ptr → 3</td>
        </tr>
        <tr class="step">
            <td>2</td>
            <td class="big-number">3</td>
            <td>2</td>
            <td><code>2 × 10 + 3</code></td>
            <td class="big-number">23</td>
            <td>nullptr</td>
        </tr>
        <tr class="final">
            <td>Final</td>
            <td>-</td>
            <td class="big-number">23</td>
            <td>Retorno</td>
            <td class="big-number">23</td>
            <td>-</td>
        </tr>
    </tbody>
</table>

- <h4>Paso a Paso Detallado - Segunda Lista</h4>
<table>
    <thead>
        <tr>
            <th>Paso</th>
            <th>head→data</th>
            <th>num</th>
            <th>Cálculo completo</th>
            <th>Resultado</th>
        </tr>
    </thead>
    <tbody>
        <tr class="step">
            <td>1</td>
            <td class="big-number">2</td>
            <td>0</td>
            <td><code>(0 × 10) + 2 = 0 + 2</code></td>
            <td class="big-number">2</td>
        </tr>
        <tr class="step">
            <td>2</td>
            <td class="big-number">3</td>
            <td>2</td>
            <td><code>(2 × 10) + 3 = 