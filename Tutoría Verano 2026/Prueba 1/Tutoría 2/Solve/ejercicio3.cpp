void retirarAuto(stack<string>& estacionamiento, string patenteBuscada) {
    stack<string> calle;
    bool encontrado = false;

    while (!estacionamiento.empty()) {
        string autoActual = estacionamiento.top();
        
        if (autoActual == patenteBuscada) {
            encontrado = true;
            estacionamiento.pop();
            break;
        } else {
            calle.push(autoActual);
            estacionamiento.pop();
        }
    }

    while (!calle.empty()) {
        string autoCalle = calle.top();
        estacionamiento.push(autoCalle);
        calle.pop();
    }
}