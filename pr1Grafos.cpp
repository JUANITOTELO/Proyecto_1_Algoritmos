#include "pr1Grafos.hpp"

void Grafo::init(){
	h = nullptr;
}

bool Grafo::vacio(){
	return h == nullptr;
}

int Grafo::size(){
	Vertice *aux;
	int count = 0;
	aux = h;
	if(vacio()){
		cout<<"Esta vacio.";
	}else{
		while(aux != nullptr){
			count++;
			aux = aux->sig;
		}
	}
	return count;
}

Vertice* Grafo::getVertice(char nombre){
	Vertice *aux;
	aux = h;
	while(aux != nullptr){
		if(aux->nombre == nombre){
			return aux;
		}
		aux = aux->sig;
	}
	return nullptr;
}

void Grafo::insertVertice(char nombre){
	Vertice *nuevo = new Vertice;
	nuevo->nombre = nombre;
	nuevo->sig = nullptr;
	nuevo->ady = nullptr;
	
	if(vacio()){
		h = nuevo;
	}
	else{
		Vertice *aux;
		aux = h;
		while(aux->sig != nullptr){
			
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void Grafo::insertArista(Vertice *origen, Vertice *destino, int peso){
	Arista *nueva = new Arista;
	Arista *aux;
	aux = origen->ady; 
	nueva->peso = peso;
	nueva->sig = nullptr;
	nueva->ady = nullptr;
	
	if(aux == nullptr){
		origen->ady = nueva;
		nueva->ady = destino;
	}else{
		while(aux->sig != nullptr){
			aux = aux->sig;
		}
		aux->sig = nueva;
		nueva->ady = destino;
	}
}

void Grafo::listAdya(){
	Vertice *verAux;
	Arista *arAux;
	
	verAux = h;
	if(h == nullptr){
		cout<<"esta vacio";
	}else{
		while(verAux != nullptr){
			cout<<verAux->nombre;
			arAux = verAux->ady;
			while(arAux != nullptr){// ~ Llega al ultimo elemento
				cout<<"-"<<arAux->peso<<"->"<<arAux->ady->nombre;
				arAux = arAux->sig;
			}
			verAux = verAux->sig;
			cout<<endl;
		}
	}
}

void Grafo::anular(){
	Vertice *aux;
	while(h != nullptr){
		aux = h;
		h = h->sig;
		delete (aux);	
	}
}

void Grafo::eliminarArista(Vertice *origen, Vertice *destino){
	Arista *actual, *anterior;
	int band = 0;
	actual = origen->ady;
	if(actual == nullptr){
		cout<<"El vertice origen no tiene aristas."<<endl;
	}
	else if(actual->ady == destino){
		origen->ady = actual->sig;
		delete (actual);
	}
	else{
		while(actual != nullptr){
			if(actual->ady == destino){
				band = 1;
				anterior->sig = actual->sig;
				delete (actual);
				break;
			}
			anterior = actual;
			actual = actual->sig;
		}
		if(band == 0){
			cout<<"Los vertices no estan conectados."<<endl;
		}
		
	}
}

void Grafo::eliminarVertice(Vertice *vert){
	Vertice *actual, *anterior;
	Arista *aux;
	
	actual = h;
	while(actual != nullptr){
		aux = actual->ady;
		while(aux != nullptr){
			if(aux->ady == vert){
				eliminarArista(actual, aux->ady);
				break;
			}
			aux = aux->sig;
		}
		
		actual = actual->sig;
	}
	actual = h;
	if(h == vert){
		h = h->sig;
		delete (actual);
	}else{
		while(actual != vert){
			anterior = actual;
			actual = actual->sig;
		}
		anterior->sig = actual->sig;
		delete (actual);
	}
}
