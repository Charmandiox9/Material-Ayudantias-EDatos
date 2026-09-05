#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;

class Cuenta {
protected:
    string titular;
    double saldo;

public:
    Cuenta(const string& t, double s) : titular(t), saldo(s) {}

    virtual ~Cuenta() {}

    double getSaldo() const { return saldo; }

    void depositar(double monto) {
        if (monto <= 0) throw invalid_argument("El monto debe ser positivo");
        saldo += monto;
    }

    virtual void retirar(double monto) {
        if (monto <= 0) throw invalid_argument("El monto debe ser positivo");
        if (monto > saldo) throw runtime_error("Saldo insuficiente");
        saldo -= monto;
    }

    virtual double calcularInteres() const = 0;

    virtual void mostrar() const {
        cout << titular << ": saldo=" << fixed << setprecision(2) << saldo
             << ", interes=" << calcularInteres() << endl;
    }
};

class CuentaCorriente : public Cuenta {
private:
    double topeDescubierto;

public:
    CuentaCorriente(const string& t, double s, double tope)
        : Cuenta(t, s), topeDescubierto(tope) {}

    void retirar(double monto) override {
        if (monto <= 0) throw invalid_argument("El monto debe ser positivo");
        if (monto > saldo + topeDescubierto) {
            throw runtime_error("Excede el tope de descubrimiento");
        }
        saldo -= monto;
    }

    double calcularInteres() const override { return 0.0; }
};

class CuentaAhorro : public Cuenta {
public:
    CuentaAhorro(const string& t, double s) : Cuenta(t, s) {}

    double calcularInteres() const override {
        return 0.02 * saldo;
    }
};

double saldoTotal(Cuenta** cuentas, int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += (*cuentas[i]).getSaldo();
    }
    return total;
}

int main() {
    Cuenta** cuentas = new Cuenta*[2];
    int n = 2;
    cuentas[0] = new CuentaCorriente("Ana", 1000.0, 500.0);
    cuentas[1] = new CuentaAhorro("Pedro", 2000.0);

    for (int i = 0; i < n; i++) {
        cuentas[i]->depositar(100.0);
        cuentas[i]->mostrar();
    }

    cout << "Saldo total: " << fixed << setprecision(2)
         << saldoTotal(cuentas, n) << endl;

    for (int i = 0; i < n; i++) {
        delete cuentas[i];
    }
    delete[] cuentas;

    return 0;
}
