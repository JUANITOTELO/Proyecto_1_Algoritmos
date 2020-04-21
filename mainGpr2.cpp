#include "pr1Grafos.hpp"

int main(){
	Grafo myGrafo;
	int nl = 15;//~ nl es numero de vertices(nodos)
	//myGrafo.crearMatrizYlistAdyAl(myGrafo, nl);
	myGrafo.crearMatrizYlistAdyAlSimple(myGrafo, nl);
	cout<<endl;
	return 0;
}
