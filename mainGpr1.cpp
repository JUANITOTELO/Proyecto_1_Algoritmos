#include "pr1Grafos.hpp"
#include <list>

int main(){
	Grafo myGrafo;
	list<char> vertices;
	for(int i = 0; i<26; i++){
		vertices.push_back(65+i);
	}
	myGrafo.init();
	char m;
	myGrafo.insertVertice('1');
	int co = 2;
	for (list<char>::iterator it=vertices.begin(); it!=vertices.end(); ++it){
		m = *it;
		myGrafo.insertVertice(m);
		myGrafo.insertArista(myGrafo.getVertice('1'),myGrafo.getVertice(m), 10+co);
		co++;
	}
	
	myGrafo.listAdya();
	cout<<"Numero de Vertices: "<<myGrafo.size()<<endl;
	cout<<"Grafo eliminado."<<endl;
	myGrafo.anular();
	myGrafo.listAdya();
	return 0;
}

