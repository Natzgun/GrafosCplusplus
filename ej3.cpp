#include <iostream>
#include <fstream>

using namespace std;

void leerMatriz(int matriz[6][6]);
void leerSubgrafo(int subMatriz[][6]);
void mostrarMatriz(int matriz[6][6]);
void generarGrafo(int matriz[6][6], int vertices[], ofstream &sal);
void verificarSubgrafo(int subMatriz[6][6], int matriz[6][6]);

int main () {
  //Grafo principal
  int matriz[6][6];
  int vertices[6] = {1, 2, 3, 4, 5};

  //subgrafoG
  int subMatriz[6][6];
  int subVertices[6] = {1,2,3,4,5};
  
  //Salida del archvio
  ofstream sal;
  sal.open("./archivosDot/grafo3.dot");

  //leer Archivos
  leerMatriz(matriz);
  leerSubgrafo(subMatriz);
  // Muestra los grafos en la terminal
  mostrarMatriz(matriz);
  cout << "\n";
  mostrarMatriz(subMatriz);
  // Determinar si es un SUB-GRAFO
  verificarSubgrafo(subMatriz,matriz);
  // Genera los grafos en formato DOT
  // --------------------------------
  generarGrafo(subMatriz,subVertices,sal);
  // --------------------------------
  //Compila el archvo DOT generando un PDF con el grafo
  system("dot -Tpdf ./archivosDot/grafo3.dot -o ./PDFgenerados/graph3.pdf");
  system("code ./PDFgenerados/graph3.pdf");
  return 0;
}


void leerMatriz(int matriz[6][6]){
  ifstream en;
  en.open("./grafos/grafo1.txt");
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++){
      en >> matriz[i][j];
    }
}

void leerSubgrafo(int matriz[6][6]){
  ifstream en;
  en.open("./grafos/subgrafoG.txt");
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++){
      en >> matriz[i][j];
    }
}

void mostrarMatriz(int matriz[6][6]){
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++)
      cout << matriz[i][j] << "\t";
    cout << endl;
  }
}

void generarGrafo(int matriz[][6], int vertices[6], ofstream &sal){
  sal << "graph A {";
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (matriz[i][j] == 1 && i < j) {
        sal << vertices[i] << " -- "<< vertices[j]<< endl;
      }
    }
  }
  sal << "}";
  sal.close();
}

void verificarSubgrafo(int subGrafo[6][6], int grafoP[6][6]) {
  int cont{0};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (subGrafo[i][j] == 1 && grafoP[i][j] != subGrafo[i][j] && i<j)
        cont =+ 1;
    }
  }
  if (cont > 0)
    cout << "No es subgrafo" << endl;
  else
    cout << "Si es subgrafo" << endl;
}