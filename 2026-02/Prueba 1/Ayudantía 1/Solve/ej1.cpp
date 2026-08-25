#include <iostream>
#include <stdexcept>

using namespace std;

class ArregloEnteros {
private:
    int* data;
    int tamano;

public:
    ArregloEnteros(int n) : tamano(n) {
        if (n <= 0) {
            throw invalid_argument("El tamano debe ser positivo");
        }
        data = new int[tamano]();
    }

    ~ArregloEnteros() {
        delete[] data;
    }

    ArregloEnteros(const ArregloEnteros&) = delete;
    ArregloEnteros& operator=(const ArregloEnteros&) = delete;

    int get(int i) const {
        if (i < 0 || i >= tamano) {
            throw out_of_range("Indice fuera de rango");
        }
        return *(data + i);
    }

    void set(int i, int valor) {
        if (i < 0 || i >= tamano) {
            throw out_of_range("Indice fuera de rango");
        }
        *(data + i) = valor;
    }

    int sumar() const {
        int total = 0;
        for (int i = 0; i < tamano; i++) {
            total += *(data + i);
        }
        return total;
    }

    double promedio() const {
        return static_cast<double>(sumar()) / tamano;
    }

    int maximo() const {
        int max = *(data + 0);
        for (int i = 1; i < tamano; i++) {
            if (*(data + i) > max) {
                max = *(data + i);
            }
        }
        return max;
    }

    int minimo() const {
        int min = *(data + 0);
        for (int i = 1; i < tamano; i++) {
            if (*(data + i) < min) {
                min = *(data + i);
            }
        }
        return min;
    }

    void duplicar() {
        int nuevoTamano = tamano * 2;
        int* nuevo = new int[nuevoTamano]();

        for (int i = 0; i < tamano; i++) {
            *(nuevo + i) = *(data + i);
        }

        delete[] data;
        data = nuevo;
        tamano = nuevoTamano;
    }

    void imprimir() const {
        cout << "[";
        for (int i = 0; i < tamano; i++) {
            if (i > 0) cout << " ";
            cout << *(data + i);
        }
        cout << "]" << endl;
    }
};

int main() {
    ArregloEnteros a(5);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);
    a.set(3, 40);
    a.set(4, 50);

    a.imprimir();
    cout << "Suma: " << a.sumar() << endl;
    cout << "Prom: " << a.promedio() << endl;
    cout << "Max: " << a.maximo() << endl;
    cout << "Min: " << a.minimo() << endl;

    a.duplicar();
    a.set(7, 99);
    a.imprimir();

    return 0;
}
