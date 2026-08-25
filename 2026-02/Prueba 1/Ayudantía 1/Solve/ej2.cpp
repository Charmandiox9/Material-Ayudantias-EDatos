#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Estudiante {
    string nombre;
    int nota;
};


string estudianteMaximaNota(const vector<Estudiante>& lista) {
    if (lista.empty()) {
        throw invalid_argument("La lista esta vacia");
    }
    string nombreMax = lista[0].nombre;
    int notaMax = lista[0].nota;
    for (size_t i = 1; i < lista.size(); i++) {
        if (lista[i].nota > notaMax) {
            notaMax = lista[i].nota;
            nombreMax = lista[i].nombre;
        }
    }
    return nombreMax;
}

double promedioGeneral(const vector<Estudiante>& lista) {
    if (lista.empty()) {
        return 0.0;
    }
    int total = 0;
    for (size_t i = 0; i < lista.size(); i++) {
        total += lista[i].nota;
    }
    return static_cast<double>(total) / lista.size();
}

vector<string> aprobados(const vector<Estudiante>& lista, int notaMinima) {
    if (lista.empty()) {
        return vector<string>();
    }
    vector<Estudiante> copia = lista;

    for (size_t i = 0; i < copia.size() - 1; i++) {
        for (size_t j = 0; j < copia.size() - 1 - i; j++) {
            if (copia[j].nota < copia[j + 1].nota) {
                Estudiante temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    vector<string> nombres;
    for (size_t i = 0; i < copia.size(); i++) {
        if (copia[i].nota >= notaMinima) {
            nombres.push_back(copia[i].nombre);
        }
    }
    return nombres;
}

bool existe(const vector<Estudiante>& lista, const string& nombre) {
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].nombre == nombre) {
            return true;
        }
    }
    return false;
}


int main() {
    vector<Estudiante> lista = {
        {"Ana", 85}, {"Pedro", 45}, {"Maria", 92},
        {"Luis", 70}, {"Carmen", 45}
    };

    cout << boolalpha;
    cout << estudianteMaximaNota(lista) << endl;
    cout << promedioGeneral(lista) << endl;
    vector<string> apro = aprobados(lista, 60);
    for (size_t i = 0; i < apro.size(); i++) {
        cout << apro[i] << " ";
    }
    cout << endl;
    cout << existe(lista, "Carmen") << endl;
    cout << existe(lista, "Jorge") << endl;

    return 0;
}
