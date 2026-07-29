#include <iostream>
#include <stdexcept>

using namespace std;

void invertir(int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        throw invalid_argument("Parametros invalidos");
    }    

    int* inicio = arr;
    int* fin = arr + size - 1;

    while (inicio < fin) {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++;
        fin--;
    }
}

int buscar(int* arr, int size, int target) {
    if (arr == nullptr || size <= 0) {
        throw invalid_argument("Parametros invalidos");
    }

    int* ptr = arr;
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) == target) {
            return i;
        }
    }

    return -1;
}

void imprimirArray(int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i > 0) cout << " ";
        cout << *(arr + i);
    }
    cout << "]" << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    invertir(arr, 5);
    cout<<buscar(arr, 5, 3)<<endl;
    cout<<buscar(arr, 5, 9)<<endl;

    imprimirArray(arr, 5);
}