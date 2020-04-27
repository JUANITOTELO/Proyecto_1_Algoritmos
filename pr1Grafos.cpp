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


//Función para crear una matriz y listata de adyacencia aleatoria
GrMat Grafo::crearMatrizYlistAdyAl(Grafo myGrafo, int nl){
	ArrM matrizValores;
	matrizValores.nl = nl;
	
	char matrizAdy[MAX][MAX];
	map<char,int> mymap;
	matrizAdy[0][0] = ' ';
	matrizValores.matriz[0][0] = ' ';
	
	list<char> vertices;
	for(int i = 0; i<nl; i++){
		vertices.push_back(65+i);
	}
	myGrafo.init();
	char m;
	int co = 1;
	for (list<char>::iterator it=vertices.begin(); it!=vertices.end(); ++it){
		m = *it;
		myGrafo.insertVertice(m);
		matrizAdy[co][0] = m;
		matrizAdy[0][co] = m;
		
		matrizValores.matriz[co][0] = m;
		matrizValores.matriz[0][co] = m;
		co++;
	}
	
	srand(time(NULL));
	for(int i = 1; i<=nl; i++){
		for(int j= 1; j<=nl; j++){
			int num = 48+rand()%(58-48);
			int numR = num-48;
			mymap.insert ( std::pair<char,int>(num,numR) );
			int p = mymap.at(num);
			if(p != 0 && (matrizAdy[i][0] != matrizAdy[0][j])){
				myGrafo.insertArista(myGrafo.getVertice(matrizAdy[i][0]),myGrafo.getVertice(matrizAdy[0][j]),p);
				matrizAdy[j][i] = 49;// ~ 1 = 49 ascii
				matrizValores.matriz[j][i] = num;
				matrizValores.matrizNumE[j-1][i-1] = numR;
			}else{
				matrizAdy[j][i] = 48;// ~ 0 = 48 ascii
				matrizValores.matriz[j][i] = 48;
				numR = 0;
				matrizValores.matrizNumE[j-1][i-1] = numR;
			}
		}
	}
	cout<<"Matriz de Adyasencia: \n";
	for(int i = 0; i<=nl; i++){
		for(int j= 0; j<=nl; j++){
			cout<<" "<<matrizAdy[j][i];
		}
		cout<<endl;
	}
	cout<<"Lista de Adyasencia: \n";
	myGrafo.listAdya();
	cout<<"Numero de Vertices: "<<myGrafo.size()<<endl;
	
	return GrMat{myGrafo, matrizValores};
}


//Función para crear una matriz y listata de adyacencia aleatoria que solo apunta a un nodo y ese nodo no apunta a nada
GrMat Grafo::crearMatrizYlistAdyAlSimple(Grafo myGrafo, int nl){
	ArrM matrizValores;
	matrizValores.nl = nl;
	
	char matrizAdy[MAX][MAX];
	/*En esta parte se crea la matriz de dimencinoes nlxnl*/
	map<char,int> mymap; // Aqui Estan los valores de las aristas 
	matrizAdy[0][0] = ' ';
	matrizValores.matriz[0][0] = ' ';
	/*Aqui todas la letras de los vertices las pasamos a una lista*/
	list<char> vertices;
	for(int i = 0; i<nl; i++){
		vertices.push_back(65+i);
	}
	/*En esta parte se incializa el grafo y se le insertan los vertices que estan en la lista
	 * tambien se agragan estos nombres a las columnas y filas de la matriz de adyacencia.*/
	myGrafo.init();
	char m;
	int co = 1;
	for (list<char>::iterator it=vertices.begin(); it!=vertices.end(); ++it){
		m = *it;
		myGrafo.insertVertice(m);
		matrizAdy[co][0] = m;
		matrizAdy[0][co] = m;
		
		matrizValores.matriz[co][0] = m;
		matrizValores.matriz[0][co] = m;
		co++;
	}
	/*Empezamos a agregar valores aleatorios a la matriz*/
	srand(time(NULL));
	for(int i = 1; i<=nl; i++){
		for(int j= 1; j<=nl; j++){
			int num = 48+rand()%(58-48);
			int numR = num-48;
			mymap.insert ( std::pair<char,int>(num,numR) );
			int p = mymap.at(num);
			if(p != 0 && (matrizAdy[i][0] != matrizAdy[0][j]) && (matrizAdy[i][j] == 48 && matrizAdy[i][j] == 48)){
				myGrafo.insertArista(myGrafo.getVertice(matrizAdy[i][0]),myGrafo.getVertice(matrizAdy[0][j]),p);
				matrizAdy[j][i] = 49;// ~ 1 = 49 ascii
				matrizValores.matriz[j][i] = num;
				matrizValores.matrizNumE[j-1][i-1] = numR;
			}else{
				matrizAdy[j][i] = 48;// ~ 0 = 48 ascii
				matrizValores.matriz[j][i] = 48;
				numR = 0;
				matrizValores.matrizNumE[j-1][i-1] = numR;
			}
		}
	}
	cout<<"Matriz de Adyasencia de Grafo simple: \n"<<endl;
	for(int i = 0; i<=nl; i++){
		for(int j= 0; j<=nl; j++){
			cout<<" "<<matrizAdy[j][i];
		}
		cout<<endl;
	}
	
	cout<<"Lista de Adyasencia de Grafo simple: \n"<<endl;
	myGrafo.listAdya();
	cout<<"Numero de Vertices: "<<myGrafo.size()<<endl;
	return GrMat{myGrafo, matrizValores};
}


//~ Función para imprimir valores de las aristas
void Grafo::iAristas(ArrM ma){
	cout<<"Matriz con valores de las aristas del Grafo: \n"<<endl;
	for(int i = 0; i<=ma.nl; i++){
		for(int j= 0; j<=ma.nl; j++){
			cout<<" "<<ma.matriz[j][i];
		}
		cout<<endl;
	}
}

//~ Función para imprimir valores de las aristas de forma entera
void Grafo::eAristas(ArrM ma){
	cout<<"Matriz con valores en tipo entero de las aristas del Grafo: \n"<<endl;
	for(int i = 0; i<=ma.nl-1; i++){
		for(int j= 0; j<=ma.nl-1; j++){
			cout<<" "<<ma.matrizNumE[j][i];
		}
		cout<<endl;
	}
}
//~ Función para recorrer el grafo en anchura
void Grafo::recAnchura(Vertice *origen){
	int band;
	int band2;
	Vertice* actual;
	queue<Vertice*> cola;
	list<Vertice*>lista;
	list<Vertice*>::iterator i;
	list<Vertice*>::iterator c;
	cola.push(origen);
	cout<< "Se recorrera desde el vertice " <<origen->nombre<<endl;
	while(!cola.empty()){
		band = 0;
		actual = cola.front();
		cola.pop();
		for(i = lista.begin(); i != lista.end(); i++){
			if(*i == actual){
				cout<<actual->nombre<<",";
				band = 1;
			}
			if(band == 0){
				cout<<actual->nombre<<",";
				lista.push_back(actual);
				Arista *aux;
				aux = actual->ady;
				while(aux != nullptr){
					band2 = 0;
					for(c = lista.begin();c != lista.end();c++){
						if(aux->ady == *c){
							band2 = 1;
						}
					}
					if(band2 == 0){
						cout<<actual->nombre<<",";
						cola.push(aux->ady);
					}
					aux = aux->sig;
				}
			}
		}
	}
}
