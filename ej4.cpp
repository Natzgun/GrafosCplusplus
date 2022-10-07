#include <iostream>
#include <fstream>

using namespace std;

void leerMatriz(int matriz[][30],int,int);
void generarGrafo(int matriz[][30], int vertices[], ofstream &sal);
void crearMatrizIncidencia(int,int);
void mostrarMatriz(int matriz[][30], int, int);

int main () {
  //Grafo principal
  int matriz[30][30];
  int vertices[6] = {1, 2, 3, 4, 5};
  //Generar nodo
  int nodo,aristas;
  cout << "Numero de vertices: "; cin >> nodo;
  aristas = (nodo*(nodo-1))/2;
  cout << "Nodos: " << aristas << endl;

  crearMatrizIncidencia(nodo,aristas);
  leerMatriz(matriz, nodo,aristas);
  mostrarMatriz(matriz,nodo,aristas);
  //Salida del archvio
/*   ofstream sal;
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
  system("code ./PDFgenerados/graph2.pdf"); */
  
  return 0;
}

void leerMatriz(int matriz[][30],int n,int a){
  ifstream en;
  en.open("./grafos/incidencia.txt");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < a; j++){
      en >> matriz[i][j];
    }
}

void crearMatrizIncidencia(int n,int a) {
  ofstream matrizIncidencia;
  matrizIncidencia.open("./grafos/incidencia.txt");
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i == k || j == k)
          matrizIncidencia << "1 ";
        else
          matrizIncidencia << "0 ";
      }
      matrizIncidencia << endl;
    }
  }
}

void mostrarMatriz(int matriz[][30], int nodo, int aristas){
  for (int i = 0; i < nodo; i++){
    for (int j = 0; j < aristas; j++)
      cout << matriz[i][j] << "\t";
    cout << endl;
  }
}

void generarGrafo(int matriz[][30], int vertices[6], ofstream &sal){
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