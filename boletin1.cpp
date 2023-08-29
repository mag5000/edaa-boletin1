#include "boletin1.h"
using namespace std;

// Constructor y destructor de la clase boletin1
boletin1::boletin1(){}
boletin1::~boletin1(){}


// Busqueda Lineal: busca en cada posición del arreglo el elemento recibido como parametro 
int busqueda_lineal(const vector<int> &arr, int element) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == element) {
            return i; // Se encontró el elemento, devuelve su índice
        }
    }
    return -1; // No se encontró el elemento
}

// Busqueda Lineal: busca un elemento en un arreglo ordenado comparando el elemento con la mitad del arreglo 
int busqueda_binaria(const vector<int> &arr, int element) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == element) {
            return mid; // Se encontró el elemento, devuelve su índice
        } else if (arr[mid] < element) {
            left = mid + 1; // Buscar en la mitad derecha
        } else {
            right = mid - 1; // Buscar en la mitad izquierda
        }
    }

    return -1; // No se encontró el elemento
}

// Busqueda Lineal: busca un elemento en un arreglo ordenado comparando el elemento con la mitad del arreglo
int busqueda_galopante(const vector<int> &arr, int element) {
    int size = arr.size();
    int jump = sqrt(size); // Tamaño del jump (raíz cuadrada del tamaño del arreglo)
    int left = 0;

    // Se realizan saltos hasta que el elemento sea menor al valor encontrado en el salto
    while (arr[min(jump, size) - 1] < element) {
        left = jump;
        jump += sqrt(size);
        if (left >= size) {
            return -1; // No se encontró el elemento
        }
    }

    // Realizar búsqueda binaria en el elemento encontrado

    while (left <= size) {
        int mid = left + (size - left) / 2;   //======================================== puede que sea menos 1

        if (arr[mid] == element) {
            return mid; // Se encontró el elemento, devuelve su índice
        } else if (arr[mid] < element) {
            left = mid + 1; // Buscar en la mitad derecha
        } else {
            right = mid - 1; // Buscar en la mitad izquierda
        }
    }




    return -1; // No se encontró el elemento
}