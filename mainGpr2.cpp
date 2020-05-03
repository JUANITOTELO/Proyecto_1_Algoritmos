#include "pr1Grafos.hpp"

int main(){
	Grafo myGrafo;
	GrMat GyM;
	int nl = 10;
	GyM = myGrafo.crearMatrizYlistAdyAl(myGrafo, nl);
	cout<<endl;
	//~ GyM = myGrafo.crearMatrizYlistAdyAlSimple(myGrafo, nl);
	//~ cout<<endl;
	myGrafo = GyM.g;
	//~ myGrafo.iAristas(GyM.m);
	//~ cout<<endl;
	//~ myGrafo.eAristas(GyM.m);
	//~ myGrafo.recAnchura(myGrafo.getVertice('A'));
	
	cout<< RED <<"Eliminado grafo.. \n"<< RESET <<endl;
	
	myGrafo.anular();
	return 0;
}
