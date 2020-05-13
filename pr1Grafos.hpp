#ifndef __PR1GRAFOS_HPP
#define __PR1GRAFOS_HPP

#include <map>
#include <queue>
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include "colores.hpp"
#define MAX 100
#define INFINITY 99999999

using namespace std;

class Arista;// define la clase arista

struct GrMat;// contiene un grafo y una estructura ArrM
struct ArrM;// contiene 2 matrices una de tipo caracter y la otra de tipo entero
struct MpV;// contiene el vertce de procedencia y valores de ady

class Vertice{// crea apuntadores con el fin de acceder a el vertice
	Vertice *sig;
	Arista *ady;
	int sumaV;
	char nombre;
	friend class Grafo;//hereda las los metodos de la clase Grafo
};

class Arista{// crea apuntadores para acceder a los Vertices
	Arista *sig;
	Vertice *ady;
	int peso;
	friend class Grafo;//hereda las los metodos de la clase Grafo
};

class Grafo{// crea la plantilla para la elaboracion de grafos.
	private:
		Vertice *h;
		MpV recordFMmenor(Vertice *origen);//recorre la fila y retorna los menores
		MpV recordFP(Vertice *origen);//recorre la fila y retorna todos los valores
		char dijkstra(Vertice *origen, Vertice *destino);// Camino mas corto, retorna una lista con las llaves del camino
		
	public:
		Vertice *getVertice(char nombre);//recibe el nombre del vertice que queremos obtener y retorna el vertice.
		GrMat crearMatrizYlistAdyAl(Grafo myGrafo, int nl);//crea la matriz lista de adyacencia de forma aleatoria.
		GrMat crearMatrizYlistAdyAlSimple(Grafo myGrafo, int nl);//crea la matriz lista de adyacencia y el primer vertice no se conecta con nadie
		GrMat crearMLUnid(Grafo myGrafo, int nl);//crea un grafo con su matriz y lista de adyacencia
		MpV reCorsFM(char nombre);//guarda los valores minimos de sus adyacentes y retona de donde viene y el mapa con los respectivos valores
		MpV reCorsF(char nombre);//recorre las filas y las guarda en un MpV
		int size();// retorna la cantidad de vertices
		int getPeso(Vertice *origen,Vertice *destino);// retorna el peso de la arista.
		char Dijkstra(char origen, char fin);
		bool vacio();// dice si el grafo esta vacio.
		void init();// inicializa el grafo.(cambiar por el constructor :V)
		void insertArista(Vertice *origen,Vertice *destino,int peso);// permite insertar una arista nueva.
		void insertVertice(char nombre);// permite insertar un vertice nuevo.
		void listAdya();//imprime la lista adyacente
		void eliminarArista(Vertice *origen, Vertice *destino);//permite eliminar la arista deseada.
		void eliminarVertice(Vertice *vert);// permite eleminar el vertice deseado.
		void iAristas(ArrM);// imprime la matriz como los caracteres.
		void eAristas(ArrM);// imprime la matriz como los valores.
		void anular();// destruye el grafo (cambiar por el destructor :V)
		//~ ~Grafo();

};

struct ArrM{
	char matriz[MAX][MAX];//crea la  copia del grafo en una matriz de Adyacencia.
	int matrizNumE[MAX][MAX];//representa el peso de las aristas en numeros
	int nl;// numero de vertices.
};

struct GrMat{
	Grafo g;
	ArrM m;
};

struct MpV{
	char Proc;
	map<char,int> valores;
	int sPesos;
	list<char> keys;
};

#endif
