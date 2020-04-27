#ifndef __PR1GRAFOS_HPP
#define __PR1GRAFOS_HPP

#include <map>
#include <queue>
#include <list>
#include <stdlib.h>
#include <time.h>
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
		GrMat crearMatrizYlistAdyAl(Grafo myGrafo, int nl);
		GrMat crearMatrizYlistAdyAlSimple(Grafo myGrafo, int nl);
		int size();
		int getPeso(Vertice *origen,Vertice *destino);
		bool vacio();
		void init();
		void insertArista(Vertice *origen,Vertice *destino,int peso);
		void insertVertice(char nombre);
		void listAdya();
		void recAnchura(Vertice *origen);
		void eliminarArista(Vertice *origen, Vertice *destino);
		void eliminarVertice(Vertice *vert);
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
