#include <algorithm>
#include <chrono>
#include <iostream>
#include <cstring>

using namespace std;

class boletin1{

  private:

    void imprimir(int array_copy[], int size);

  public:
    boletin1();
    ~boletin1();  

    int busqueda_lineal(const vector<int> &arr, int element);
	int busqueda_binaria(const vector<int> &arr, int element); 
	int busqueda_galopante(const vector<int> &arr, int element); 


    long long lineal_time(const vector<int> &arr, int element);
    long long binaria_time(const vector<int> &arr, int element);
    long long galopante_time(const vector<int> &arr, int element);


};