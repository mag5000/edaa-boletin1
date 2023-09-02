#include <iostream>
#include <fstream>
#include <vector>
#include "boletin1.h"
using namespace std;


// Funcion que sirve para leer el dataset de arreglos que seran ordenados
// recibe la ruta como parametro.
vector <vector<int>> read_dataset(string route){

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
//void take_time(int exp_x_array, vector< vector<int>> arrays, vector<int> positions){
void take_time(int exp_x_array, vector< vector<int>> arrays){

  vector<int> *temp_array;
  int temp_array_size;
  int element;
  int position;
  boletin1 *busqueda = new boletin1();

  double secuencial_time = 0;
  double binaria_time = 0;
  double galopante_time = 0;

  ofstream outfile("output/results.csv");
  outfile << "size,position,algorithm,time\n";


  //para cada vector del dataset
  for(int k = 0; k<arrays.size(); k++){ 

    temp_array_size = arrays[k].size();
    vector<int> positions = {5,temp_array_size/4,temp_array_size/2,(3*temp_array_size)/4,temp_array_size-5}; //porcentaje de la posición

    // Para cada posición definida
    for(int j = 0; j<positions.size(); j++){


      secuencial_time = 0;
      binaria_time = 0;
      galopante_time = 0;

      position = positions[j];
      element = arrays[k][position];
      cout<<"temp_array_size: "<<temp_array_size<<" y la posicion: "<<position<<endl;
      
      // La busqueda se ejecuta el número de veces definido
      for(int i =0;i< exp_x_array;i++){

        secuencial_time += busqueda->secuencial_time(arrays[k], element);
        binaria_time += busqueda->binaria_time(arrays[k], element);
        galopante_time += busqueda->galopante_time(arrays[k], element);
      }
      outfile << temp_array_size << "," << j << ",Secuencial,"<< secuencial_time/exp_x_array << endl;
      outfile << temp_array_size << "," << j << ",Binaria,"<< binaria_time/exp_x_array << endl;
      outfile << temp_array_size << "," << j << ",Galopante,"<< galopante_time/exp_x_array << endl;
    }

  }

  outfile.close(); 

}


int main(){

  vector<vector<int>> arrays = read_dataset("datasets/ordered_array_dataset.txt");
  take_time(1000, arrays);
  return 0;

}