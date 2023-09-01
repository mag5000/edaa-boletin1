#include "boletin1.h"
using namespace std;

// Constructor y destructor de la clase boletin1
boletin1::boletin1(){}
boletin1::~boletin1(){}

//========================================================== Búsquedas ============================================================================

// Busqueda Lineal: busca en cada posición del arreglo el elemento recibido como parametro 
int boletin1::busqueda_secuencial(const vector<int> &arr, int element) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == element) {
            return i; // Se encontró el elemento, devuelve su índice
        }
    }
    return -1; // No se encontró el elemento
}

// Busqueda Binaria: busca un elemento en un arreglo ordenado comparando el elemento con el elemento en la mitad del arreglo y llamando
// recursivamente a la misma funcion con la mitad derecha del arreglo si el eleento buscado es menor, o con la mitad derecha si es mayor 
int boletin1::busqueda_binaria(const vector<int> &arr, int left, int right, int element)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;
        // Si justo el elemento esta en la posición comparada se retorna la posición
        if (arr[mid] == element)
            return mid;
        // Si el elemento es menor se llama recursivamente con la mitad izquierda del arreglo
        if (arr[mid] > element)
            return busqueda_binaria(arr, left, mid - 1, element);
        // Si el elemento es menor se llama recursivamente con la mitad derecha del arreglo
        return busqueda_binaria(arr, mid + 1, right, element);
    }
    // En caso de no encontrar el elemento 
    return -1;
}

// Busqueda Lineal: busca un elemento en un arreglo ordenado comparando el elemento con la mitad del arreglo
int boletin1::busqueda_galopante(const vector<int> &arr, int element) {
    int size = arr.size();
    int jump = 1; // Tamaño del salto
    int left = 0;
    int position = 0;

    // Se realizan saltos hasta que el elemento sea menor al valor encontrado en el salto
    while (arr[min(position, size)] < element) {
        if (left >= size) {
            return -1; // No se encontró el elemento
        }
        left=position;
        position=position+jump;
        jump=jump*2;
    }
    // Finalmente se realiza una búsqueda binaria en el rango encontrado
    return busqueda_binaria(arr, left, position, element); 
}

//========================================================== Funciones para tomar tiempo ====================================================================

// Función que toma el tiempo de ejecución de la búsqueda secuencial
long long boletin1::secuencial_time(const vector<int> &arr, int element){

    int result;
    auto start_time = chrono::steady_clock::now();
    result = busqueda_secuencial(arr, element);
    auto end_time = chrono::steady_clock::now();
    long long duration = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    
    if(result==-1){
      cout<<"Error en busqueda secuencial con elemento "<<element<<endl;
    }
    return duration;
}

// Función que toma el tiempo de ejecución de la búsqueda binaria
long long boletin1::binaria_time(const vector<int> &arr, int element){

    int result;
    auto start_time = chrono::steady_clock::now();
    result = busqueda_binaria(arr, 0, arr.size()-1, element);
    auto end_time = chrono::steady_clock::now();
    long long duration = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

    if(result==-1){
      cout<<"Error en búsqueda binaria con elemento "<<element<<endl;
    }

    return duration;
}

// Funcion que toma el tiempor de ejecución de busqueda secuencial
long long boletin1::galopante_time(const vector<int> &arr, int element){

    int result;
    auto start_time = chrono::steady_clock::now();
    result = busqueda_galopante(arr, element);
    auto end_time = chrono::steady_clock::now();
    long long duration = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    
    if(result==-1){
      cout<<"Error en busqueda galopante con elemento "<<element<<endl;
    }
    return duration;
}