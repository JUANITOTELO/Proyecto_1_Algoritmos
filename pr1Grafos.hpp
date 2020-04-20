#ifndef __PR1GRAFOS_HPP
#define __PR1GRAFOS_HPP

#include <iostream>
#include <string>

using namespace std;

class Arista;

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
		void anular();
};



#endif
