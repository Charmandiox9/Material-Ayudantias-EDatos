#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayDinamico {
private:
    int* data;
    int tamano;

public:
    ArrayDinamico(int tam) : tamano(tam) {
        if (tam <= 0) {
            throw invalid_argument("El tamano debe ser positivo");
        }
        data = new int[tamano]();
    }

    ~ArrayDinamico() {
        delete[] data;
    }

    // Constructor de copia
    ArrayDinamico(const ArrayDinamico& otro) : tamano(otro.tamano) {
        data = new int[tamano];
        for (int i = 0; i < tamano; i++) {
            data[i] = otro.data[i];
        }
    }

    // Operador de asignación
    ArrayDinamico& operator=(const ArrayDinamico& otro) {
        if (this != &otro) {
            delete[] data;
            tamano = otro.tamano;
            data = new int[tamano];
            for (int i = 0; i < tamano; i++) {
                data[i] = otro.data[i];
            }
        }
        return *this;
    }


    int& operator[](int i) {
        if (i < 0 || i >= tamano) {
            throw out_of_range("Indice fuera de rango");
        }
        return data[i];
    }

    const int& operator[](int i) const {
        if (i < 0 || i >= tamano) {
            throw out_of_range("Indice fuera de rango");
        }
        return data[i];
    }

    friend ostream& operator<<(ostream& os, const ArrayDinamico& arr) {
        os << "[";
        for (int i = 0; i < arr.tamano; i++) {
            if (i > 0) os << " ";
            os << arr.data[i];
        }
        os << "]";
        return os;
    }

    int getTamano() const {
        return tamano;
    }
};

int main(){
    ArrayDinamico a(5);
    a[0] = 10; a[1] = 20; a[2] = 30; a[3] = 40; a[4] = 50;

    ArrayDinamico b = a;
    cout << b;

    ArrayDinamico c(3);
    c = a;
    cout << c;
}