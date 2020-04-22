#include "pr1Grafos.hpp"

int main(){
	Grafo myGrafo;
	GrMat GyM;
	int nl = 25;
	//myGrafo.crearMatrizYlistAdyAl(myGrafo, nl);
	GyM = myGrafo.crearMatrizYlistAdyAlSimple(myGrafo, nl);
	cout<<endl;
	myGrafo = GyM.g;
	myGrafo.iAristas(GyM.m);
	cout<<"Eliminado grafo.. "<<endl;
	myGrafo.anular();
	return 0;
}
