
#include <chrono>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class boletin1{

  private:

    void imprimir(int array_copy[], int size);

  public:
    boletin1();
    ~boletin1();  

    int busqueda_secuencial(const vector<int> &arr, int element);
	  int busqueda_binaria(const vector<int> &arr, int left, int right, int element);
	  int busqueda_galopante(const vector<int> &arr, int element); 

    long long secuencial_time(const vector<int> &arr, int element);
    long long binaria_time(const vector<int> &arr, int element);
    long long galopante_time(const vector<int> &arr, int element);


};