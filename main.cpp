#include <iostream>
#include <fstream>
#include <vector>

#include "boletin1.h"

using namespace std;

// Función para imprimir los arreglos
void printArray(string algName, int arr[], int size)
{
   cout<<algName<<": "<<endl;
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


// Funcion que sirve para leer el dataset de arreglos que seran ordenados
// recibe la ruta como parametro.
// Fuente: elaboración propia basado en lo enseñado por Vicente Lermanda
vector <vector<int>> readArrayDataset(string route){

  int size = 0;
  vector<vector<int>> arrays;
  ifstream inputfile(route);

  while(inputfile>>size){
    if(size>0){
      vector<int> temp_vector(size);
      for(int i=0; i<size;i++){
        inputfile>>temp_vector[i];
      }   
      arrays.push_back(temp_vector);
      temp_vector.clear();
    }
  }
  return arrays;
}


// Funcion que llama las funciones que toman el tiempo x veces y los guarda los resultados 
//en un archivo de texto en la carpetga output, con el nombre "results.txt"
void takeTime(int exp_x_array, vector< vector<int>> arrays, vector<int> positions){

  int* temp_array;
  int temp_array_size;
  int position;
  boletin1 *busqueda = new boletin1();

  long long int secuencial_time = 0;
  long long int binaria_time = 0;
  long long int galopante_time = 0;

  ofstream outfile("output/results.csv");
  outfile << "size,position,algorithm,time\n";

  //para cada vector del dataset
  for(int k = 0; k<arrays.size(); k++){ 

    temp_array_size = arrays[k].size();
    temp_array = new int[temp_array_size];

    for(int i = 0; i<temp_array_size; i++){
      temp_array[i] = arrays[k][i];
    }

    // Para cada posición definida
    for(int j = 0: j<positions.size(); j++){

      position = positions[j];

      // La busqueda se ejecuta el número de veces definido
      for(int i =0;i< exp_x_array;i++){

        secuencial_time += busqueda->secuencial_time(temp_array, element);
        binaria_time += busqueda->binaria_time(temp_array, element);
        galopante_time += busqueda->galopante_time(temp_array, element);
        
      }

      outfile << temp_array_size << "," << position << ",Bubble Sort,"<< secuencial_time/exp_x_array << endl;
      outfile << temp_array_size << "," << position << ",Merge Sort,"<< binaria_time/exp_x_array << endl;
      outfile << temp_array_size << "," << position << ",STL Sort,"<< galopante_time/exp_x_array << endl;

    }


  }

  outfile.close(); 

}


int main(){

  vector<vector<int>> arrays = readArrayDataset("datasets/random_array_dataset.txt");
  takeSortingTime(10, arrays);
  return 0;

}