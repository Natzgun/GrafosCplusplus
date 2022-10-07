#include <iostream>
#include <fstream>

using namespace std;

void leerMatriz(int matriz[][6]);
void mostrarMatriz(int matriz[][6]);
void generarGrafo(int matriz[][6], int vertices[], ofstream &sal);

int main () {
  //Grafo principal
  int matriz[6][6];
  int vertices[6] = {1, 2, 3, 4, 5};

  //Salida del archvio
  ofstream sal;
  sal.open("./archivosDot/grafo2.dot");

  //leer Archivos
  leerMatriz(matriz);
  // Muestra los grafos en la terminal
  mostrarMatriz(matriz);

  // Genera los grafos en formato DOT
  // --------------------------------
  generarGrafo(matriz,vertices,sal);
  // --------------------------------
  //Compila el archvo DOT generando un PDF con el grafo
  system("dot -Tpdf ./archivosDot/grafo2.dot -o ./PDFgenerados/graph2.pdf");
  system("code ./PDFgenerados/graph2.pdf");
  
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
      if (matriz[i][j] == 0 && i < j) {
        sal << vertices[i] << " -- "<< vertices[j]<< endl;
      }
    }
  }
  sal << "}";
  sal.close();
}