class Navegador {
private:
    string paginaActual;
    stack<string> pilaAtras;
    stack<string> pilaAdelante;

public:
    Navegador(string inicio) {
        paginaActual = inicio;
        cout << "Inicio en: " << paginaActual << endl;
    }

    void visitar(string url) {
        pilaAtras.push(paginaActual);
        
        paginaActual = url;

        while (!pilaAdelante.empty()) {
            pilaAdelante.pop();
        }
    }

    void atras() {
        if (pilaAtras.empty()) {
            return;
        }

        pilaAdelante.push(paginaActual);

        paginaActual = pilaAtras.top();
        pilaAtras.pop();
    }

    void adelante() {
        if (pilaAdelante.empty()) {
            return;
        }

        pilaAtras.push(paginaActual);

        paginaActual = pilaAdelante.top();
        pilaAdelante.pop();
    }
};