#include "pr1Grafos.hpp"
#include <list>
#include <stdlib.h>
#include <time.h>
#include <map>
#define MAX 100
void crearMatrizYlistAdyAlSimple(Grafo myGrafo, int nl){
		char matrizAdy[MAX][MAX];
	map<char,int> mymap;
	matrizAdy[0][0] = ' ';
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
		co++;
	}
	
	srand(time(NULL));
	for(int i = 1; i<=nl; i++){
		for(int j= 1; j<=nl; j++){
			int num = 48+rand()%(58-48);
			mymap.insert ( std::pair<char,int>(num,num-48) );
			int p = mymap.at(num);
			if(p != 0 && (matrizAdy[i][0] != matrizAdy[0][j]) && (matrizAdy[i][j] == 48 && matrizAdy[i][j] == 48)){
				myGrafo.insertArista(myGrafo.getVertice(matrizAdy[i][0]),myGrafo.getVertice(matrizAdy[0][j]),p);
				matrizAdy[j][i] = 49;// ~ 1 = 49 ascii
			}else{
				matrizAdy[j][i] = 48;// ~ 0 = 48 ascii
			}
		}
	}
	cout<<"Matriz de Adyasencia de Grafo simple: \n";
	for(int i = 0; i<=nl; i++){
		for(int j= 0; j<=nl; j++){
			cout<<" "<<matrizAdy[j][i];
		}
		cout<<endl;
	}
	cout<<"Lista de Adyasencia de Grafo simple: \n";
	myGrafo.listAdya();
	cout<<"Numero de Vertices: "<<myGrafo.size()<<endl;
	cout<<"Grafo eliminado."<<endl;
	myGrafo.anular();
	myGrafo.listAdya();
}

void crearMatrizYlistAdyAl(Grafo myGrafo, int nl){
	char matrizAdy[MAX][MAX];
	map<char,int> mymap;
	matrizAdy[0][0] = ' ';
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
		co++;
	}
	
	srand(time(NULL));
	for(int i = 1; i<=nl; i++){
		for(int j= 1; j<=nl; j++){
			int num = 48+rand()%(58-48);
			mymap.insert ( std::pair<char,int>(num,num-48) );
			int p = mymap.at(num);
			if(p != 0){
				myGrafo.insertArista(myGrafo.getVertice(matrizAdy[i][0]),myGrafo.getVertice(matrizAdy[0][j]),p);
			}
			if(p==0){
				matrizAdy[j][i] = 48;// ~ 0 = 48 ascii
			}else{
				matrizAdy[j][i] = 49;// ~ 1 = 49 ascii
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
	cout<<"Grafo eliminado."<<endl;
	myGrafo.anular();
	myGrafo.listAdya();
}

int main(){
	Grafo myGrafo;
	int nl = 6;//~ nl es numero de vertices(nodos)
	//~ crearMatrizYlistAdyAl(myGrafo, nl);
	crearMatrizYlistAdyAlSimple(myGrafo, nl);
	return 0;
}
