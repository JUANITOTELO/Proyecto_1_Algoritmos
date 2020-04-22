#ifndef __PR1GRAFOS_HPP
#define __PR1GRAFOS_HPP

#include <list>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <iostream>
#include <string>
#define MAX 100

using namespace std;

class Arista;

struct GrMat;
struct ArrM;

class Vertice{
	Vertice *sig;
	Arista *ady;
	char nombre;
	friend class Grafo;
};

class Arista{
	Arista *sig;
	Vertice *ady;
	int peso;
	friend class Grafo;
};

class Grafo{
	private:
		Vertice *h;
	
	public:
		Vertice *getVertice(char nombre);
		int size();
		int getPeso(Vertice *origen,Vertice *destino);
		bool vacio();
		void init();
		void insertArista(Vertice *origen,Vertice *destino,int peso);
		void insertVertice(char nombre);
		void listAdya();
		void eliminarArista(Vertice *origen, Vertice *destino);
		void eliminarVertice(Vertice *vert);
		GrMat crearMatrizYlistAdyAl(Grafo myGrafo, int nl);
		GrMat crearMatrizYlistAdyAlSimple(Grafo myGrafo, int nl);
		void iAristas(ArrM);
		void eAristas(ArrM);
		void anular();
		
};

struct ArrM{
	char matriz[MAX][MAX];
	int matrizNumE[MAX][MAX];
	int nl;
};

struct GrMat{
	Grafo g;
	ArrM m;
};

#endif
