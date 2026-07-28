#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

using namespace std;

class Figura {
public:
    virtual ~Figura() = default;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void printInfo() const {
        cout << "Figura desconocida" << endl;
    }
};

class Rectangulo : public Figura {
private:
    double ancho;
    double alto;

public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {
        if (a <= 0 || h <= 0) {
            throw invalid_argument("Dimensiones deben ser positivas");
        }
    }

    double area() const override {
        return ancho * alto;
    }

    double perimeter() const override {
        return 2 * (ancho + alto);
    }

    void printInfo() const override {
        cout << fixed << setprecision(2);
        cout << "Rectangulo: " << ancho << " x " << alto
             << " | Area: " << area()
             << " | Perimetro: " << perimeter() << endl;
    }
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {
        if (r <= 0) {
            throw invalid_argument("Radio debe ser positivo");
        }
    }

    double area() const override {
        return M_PI * radio * radio;
    }

    double perimeter() const override {
        return 2 * M_PI * radio;
    }

    void printInfo() const override {
        cout << fixed << setprecision(2);
        cout << "Circulo: r=" << radio
             << " | Area: " << area()
             << " | Perimetro: " << perimeter() << endl;
    }
};

class Triangulo : public Figura {
private:
    double lado1;
    double lado2;
    double lado3;

    bool esValido() const {
        return (lado1 + lado2 > lado3) &&
               (lado1 + lado3 > lado2) &&
               (lado2 + lado3 > lado1);
    }

public:
    Triangulo(double a, double b, double c) : lado1(a), lado2(b), lado3(c) {
        if (!esValido()) {
            throw invalid_argument("Los lados no forman un triangulo valido");
        }
    }

    double area() const override {
        double s = (lado1 + lado2 + lado3) / 2.0;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }

    double perimeter() const override {
        return lado1 + lado2 + lado3;
    }

    void printInfo() const override {
        cout << fixed << setprecision(2);
        cout << "Triangulo: " << lado1 << " x " << lado2 << " x " << lado3 << " | Area: " << area() << " | Perimetro: " << perimeter() << endl;
    }
};

int main() {
    Figura* f1 = new Rectangulo(5.0, 3.0);
    Figura* f2 = new Circulo(7.0);
    Figura* f3 = new Triangulo(3.0, 4.0, 5.0);

    Figura* figures[] = {f1, f2, f3};

    for (auto* f : figures) {
        f->printInfo();
        delete f;
    }

    return 0;
}
