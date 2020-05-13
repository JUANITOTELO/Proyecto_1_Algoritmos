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
	cout<<BOLDMAGENTA<<aux->nombre<<RESET<<" ";
	return nullptr;
}

void Grafo::insertVertice(char nombre){
	Vertice *nuevo = new Vertice;
	nuevo->nombre = nombre;
	nuevo->sig = nullptr;
	nuevo->ady = nullptr;
	nuevo->sumaV = INFINITY;
	
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
				cout<< GREEN <<"-"<< BOLDGREEN <<arAux->peso << RESET << GREEN <<"->"<< RESET <<arAux->ady->nombre;
				arAux = arAux->sig;
			}
			verAux = verAux->sig;
			cout<<endl;
		}
	}
}

//~ Función para recorrer el grafo 
MpV Grafo::recordFMmenor(Vertice *origen){
	Vertice *veAux;
	Arista *arAux;
	MpV aux;
	veAux = origen;
	arAux = veAux->ady;
	map<char,int> myminmap;
	map<char,int> myminmap2;
	map<char,int>::iterator it;
	int k = 0;
	int min = arAux->peso;
	char n = origen->nombre;
	char na;
	if(origen == nullptr){
		cout<<"esta vacio";
	}
	while(arAux != nullptr){
		if(arAux->peso <= min){
			na = arAux->ady->nombre;
			min = arAux->peso;
			myminmap.insert(pair<char,int>(na,min));
			//~ cout<<BOLDCYAN<<n<<RESET<<"-"<<BOLDYELLOW<<arAux->peso<<RESET<<">"<<BOLDGREEN<<na<<RESET<<" ";
			k += 1;
		}
			arAux = arAux->sig;
	}
	
	cout<<endl;
	int auxAnt = myminmap.begin()->second;
	for (it = myminmap.begin(); it != myminmap.end(); ++it){
		if(auxAnt > it->second){
			auxAnt = it->second;
		}
	}
	for (it = myminmap.begin(); it != myminmap.end(); ++it){
		if(auxAnt == it->second){
			myminmap2.insert(pair<char,int>(it->first, it->second));
		}
	}

	aux.Proc = n;
	aux.valores = myminmap2;
	cout<<endl;
	return aux;
}

MpV Grafo::recordFP(Vertice *origen){
	Vertice *veAux;
	Arista *arAux;
	MpV aux;
	veAux = origen;
	arAux = veAux->ady;
	map<char,int> myminmap;
	int k = 0;
	int min = arAux->peso;
	char n = origen->nombre;
	char na;
	if(origen == nullptr){
		cout<<"esta vacio";
	}else{
		while(arAux != nullptr){
		
			na = arAux->ady->nombre;
			min = arAux->peso;
			myminmap.insert(pair<char,int>(na,min));
			aux.sPesos = arAux->ady->sumaV;
			//~ cout<<BOLDCYAN<<n<<RESET<<"-"<<BOLDYELLOW<<arAux->peso<<RESET<<">"<<BOLDGREEN<<na<<RESET<<" ";
			k += 1;
			arAux = arAux->sig;
		}
	}
	
	aux.Proc = n;
	aux.valores = myminmap;
	cout<<endl;
	return aux;

}

char Grafo::dijkstra(Vertice *origen, Vertice *destino){
	MpV filas[MAX];
	map<char,int> mymap;
	map<char, int>::iterator it;
	list<char> visitados;
	list<char> noVisitados;
	int auxSPesos[MAX];
	int suma = 0;
	int nl = size();
	
	for(char n = 65; n < 65+nl; n++){
		if(n == 65){
			filas[n-65] = reCorsF(n);
			mymap = filas[n-65].valores;
			it = mymap.begin();
			filas[n-65].sPesos = 0;
			cout<<BOLDCYAN<<filas[n-65].Proc<<" " << filas[n-65].sPesos <<RESET<<endl;
			visitados.push_back(filas[n-65].Proc);
			for (it=mymap.begin(); it!=mymap.end(); ++it)
				cout << BOLDMAGENTA <<it->first <<RESET << BOLDGREEN << " => " << RESET << BOLDYELLOW <<it->second << RESET << '\n';
			auxSPesos[n-65] = filas[n-65].sPesos;
		}else{
		filas[n-65] = reCorsF(n);
		mymap = filas[n-65].valores;
		cout<<BOLDCYAN<<filas[n-65].Proc<<" " << filas[n-65].sPesos <<RESET<<endl;
		noVisitados.push_back(filas[n-65].Proc);
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			cout << BOLDMAGENTA <<it->first <<RESET << BOLDGREEN << " => " << RESET << BOLDYELLOW <<it->second << RESET << '\n';
		}
		auxSPesos[n-65] = filas[n-65].sPesos;
	}

	//~ noVisitados.pop_front();
	//~ filas[0].sPesos = 0;
	//~ cout << "noVisitados contains:";
	for (std::list<char>::iterator it=noVisitados.begin(); it!=noVisitados.end(); ++it)
		std::cout << ' ' << *it;
	
	cout<<endl;
	
	for(int n = 0; n < nl; n++){
		cout<<filas[n].Proc<<endl;
			for (it=filas[n].valores.begin(); it!=filas[n].valores.end(); ++it){
				suma = filas[n].sPesos + it->second;
				if(suma < auxSPesos[it->first-65]){
					auxSPesos[it->first-65] = suma;
					filas[it->first-65].sPesos = suma;
					//~ cout<<suma<<endl;
					
				}
				cout<<BOLDCYAN<<filas[it->first-65].Proc<<" " << filas[it->first-65].sPesos <<RESET<<endl;
			}
	}
	
	
	//~ cout<<endl;
	//~ it = filas[1].valores.begin();
	//~ for(int i = 66; i < 65+nl; i++){
		//~ filas[i].sPesos = it->second;
		//~ cout<< it->first << filas[i].sPesos <<" ";
		//~ it++;
	//~ } 
	cout<<endl;
	
	return 'A';
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
			cout<<RED<<"Los vertices no estan conectados."<<RESET<<endl;
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
	cout<< BOLDWHITE <<"Matriz de Adyacencia: \n" << RESET;
	for(int i = 0; i<=nl; i++){
		for(int j= 0; j<=nl; j++){
			if(matrizAdy[j][i] == '0'){
				cout<<" "<< RED <<matrizAdy[j][i]<< RESET;
			}else{
				cout<<" "<<matrizAdy[j][i];
			}
		}
		cout<<endl;
	}
	cout<< BOLDWHITE <<"Lista de Adyacencia: \n"<< RESET;
	myGrafo.listAdya();
	cout<< BOLDWHITE <<"Numero de Vertices: "<< BOLDYELLOW <<myGrafo.size()<< RESET <<endl;
	
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
			mymap.insert ( pair<char,int>(num,numR) );
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
	cout<< BOLDWHITE <<"Matriz de Adyacencia de Grafo simple: \n"<< RESET <<endl;
	for(int i = 0; i<=nl; i++){
		for(int j= 0; j<=nl; j++){
			if(matrizAdy[j][i] == '0'){
				cout<<" "<< RED <<matrizAdy[j][i]<< RESET;
			}else{
				cout<<" "<<matrizAdy[j][i];
			}
		}
		cout<<endl;
	}
	cout<< BOLDWHITE <<"Lista de Adyacencia de Grafo simple: \n"<< RESET <<endl;
	myGrafo.listAdya();
	cout<<BOLDWHITE <<"Numero de Vertices: "<< RESET<< BOLDYELLOW <<myGrafo.size()<< RESET <<endl;
	return GrMat{myGrafo, matrizValores};
}

//~ Función para crear un grafo unidireccional
GrMat Grafo::crearMLUnid(Grafo myGrafo, int nl){
	ArrM matrizValores;
	matrizValores.nl = nl;
	char matrizAdy[MAX][MAX];
	
	/*En esta parte se crea la matriz de dimenciones nlxnl*/
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
				if(i == nl && j == 1){
					//~ myGrafo.insertArista(myGrafo.getVertice(matrizAdy[i][0]),myGrafo.getVertice(matrizAdy[0][j]),0});
					//~ myGrafo.insertArista(myGrafo.getVertice(matrizAdy[j][0]),myGrafo.getVertice(matrizAdy[0][i]),0);
					matrizAdy[j][i] = matrizAdy[i][j] = 48;// ~ 1 = 49 ascii
					matrizValores.matriz[j][i] = matrizValores.matriz[i][j] = '0';
					matrizValores.matrizNumE[j-1][i-1] = matrizValores.matrizNumE[i-1][j-1] = 0;
				}else{
					myGrafo.insertArista(myGrafo.getVertice(matrizAdy[i][0]),myGrafo.getVertice(matrizAdy[0][j]),p);
					myGrafo.insertArista(myGrafo.getVertice(matrizAdy[j][0]),myGrafo.getVertice(matrizAdy[0][i]),p);
					matrizAdy[j][i] = matrizAdy[i][j] = 49;// ~ 1 = 49 ascii
					matrizValores.matriz[j][i] = matrizValores.matriz[i][j] = num;
					matrizValores.matrizNumE[j-1][i-1] = matrizValores.matrizNumE[i-1][j-1] = numR;
				}
			}else{
				matrizAdy[j][i] = matrizAdy[i][j] = 48;// ~ 0 = 48 ascii
				matrizValores.matriz[j][i] = matrizValores.matriz[i][j] = 48;
				numR = 0;
				matrizValores.matrizNumE[j-1][i-1] = matrizValores.matrizNumE[i-1][j-1] = numR;
			}
		}
	}
	/*Se agregaran valores a la matriz y al grafo en la ubicación de AB = BA
	int num = 48+rand()%(58-48);
	int numR = num-48;
	myGrafo.insertArista(myGrafo.getVertice(matrizAdy[i][0]),myGrafo.getVertice(matrizAdy[0][j]),num);
	matrizAdy[1][2] = matrizAdy[2][1] = num;
	*/
	cout<< BOLDWHITE <<"Matriz de Adyacencia de Grafo simple: \n"<< RESET <<endl;
	for(int i = 0; i<=nl; i++){
		for(int j= 0; j<=nl; j++){
			if(matrizAdy[j][i] == '0'){
				cout<<" "<< RED <<matrizAdy[j][i]<< RESET;
			}else{
				cout<<" "<<matrizAdy[j][i];
			}
		}
		cout<<endl;
	}
	cout<< BOLDWHITE <<"Lista de Adyacencia de Grafo simple: \n"<< RESET <<endl;
	myGrafo.listAdya();
	cout<<BOLDWHITE <<"Numero de Vertices: "<< RESET<< BOLDYELLOW <<myGrafo.size()<< RESET <<endl;
	return GrMat{myGrafo, matrizValores};
}


//~ Función para imprimir valores de las aristas
void Grafo::iAristas(ArrM ma){
	cout<< BOLDWHITE <<"Matriz con valores de las aristas del Grafo: \n"<< RESET <<endl;
	for(int i = 0; i<=ma.nl; i++){
		for(int j= 0; j<=ma.nl; j++){
			if(ma.matriz[j][i] == '0'){
				cout<<" "<< RED<<ma.matriz[j][i]<< RESET;
			}else{
				cout<<" "<< ma.matriz[j][i];
			}
		}
		cout<<endl;
	}
	cout<<endl;
}

//~ Función para imprimir valores de las aristas de forma entera
void Grafo::eAristas(ArrM ma){
	cout<< BOLDWHITE <<"Matriz con valores en tipo entero de las aristas del Grafo: \n"<<RESET<<endl;
	for(int i = 0; i<=ma.nl-1; i++){
		for(int j= 0; j<=ma.nl-1; j++){
			if(ma.matrizNumE[j][i] == 0){
				cout<<" "<< RED << ma.matrizNumE[j][i] << RESET;
			}else{
				cout<<" "<< ma.matrizNumE[j][i];
			}
		}
		cout<<endl;
	}
	cout<<endl;
}

//~ Función para recorrer la fila con el nombre que recibe
MpV Grafo::reCorsFM(char nombre){
	return recordFMmenor(getVertice(nombre));
}

char Grafo::Dijkstra(char origen, char fin){
	return dijkstra(getVertice(origen), getVertice(fin));
}

MpV Grafo::reCorsF(char nombre){
	return recordFP(getVertice(nombre));
}


void Grafo::anular(){
	cout<< BOLDRED <<"Eliminado grafo.. \n"<< RESET <<endl;
	Vertice *aux;
	while(h != nullptr){
		aux = h;
		h = h->sig;
		delete (aux);
	}
}

