struct Tarea {
    string id;
    int tiempoRestante;
};

void simularCPU(queue<Tarea>& colaProcesos, int quantum) {
    while (!colaProcesos.empty()) {
        Tarea actual = colaProcesos.front();
        colaProcesos.pop();

        int tiempoEjecucion = min(quantum, actual.tiempoRestante);
        
        actual.tiempoRestante -= tiempoEjecucion;
        tiempoTotal += tiempoEjecucion;

        if (actual.tiempoRestante > 0) {
            colaProcesos.push(actual);
        } else {
            cout << "-> TAREA TERMINADA." << endl;
        }
    }
    
}