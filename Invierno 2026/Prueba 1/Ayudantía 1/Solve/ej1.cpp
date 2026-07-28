#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

struct Alumno {
    char* nombre;
    int edad;
    double promedio;
};

Alumno* crearAlumno(const char* nombre, int edad, double promedio) {
    if (nombre == nullptr) {
        throw invalid_argument("El nombre no puede ser nullptr");
    }

    Alumno* alumno = new Alumno;

    int len = strlen(nombre);
    alumno->nombre = new char[len + 1];
    strcpy(alumno->nombre, nombre);

    alumno->edad = edad;
    alumno->promedio = promedio;

    return alumno;
}

void mostrarAlumno(Alumno* alumno) {
    if (alumno == nullptr) {
        throw invalid_argument("Puntero nullptr");
    }
    cout << "Nombre: " << alumno->nombre << ", Edad: " << alumno->edad << ", Promedio: " << alumno->promedio << endl;
}

void eliminarAlumno(Alumno* alumno) {
    if (alumno == nullptr) {
        return;
    }
    delete[] alumno->nombre;
    delete alumno;
}

int main(){
  Alumno* a1 = crearAlumno("Ana", 20, 8.5);
  Alumno* a2 = crearAlumno("Carlos", 22, 7.3);

  mostrarAlumno(a1);
  mostrarAlumno(a2);

  eliminarAlumno(a1);
  eliminarAlumno(a2);
}

