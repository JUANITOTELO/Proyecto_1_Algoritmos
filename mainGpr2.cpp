#include "pr1Grafos.hpp"

int main(){
	Grafo myGrafo;
	int nl = 15;//~ nl es numero de vertices(nodos)
	//myGrafo.crearMatrizYlistAdyAl(myGrafo, nl);
	myGrafo = myGrafo.crearMatrizYlistAdyAlSimple(myGrafo, nl);
	cout<<endl;
	cout<<"Eliminado grafo.. "<<endl;
	myGrafo.anular();
	return 0;
}
