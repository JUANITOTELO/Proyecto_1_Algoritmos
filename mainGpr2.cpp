#include "pr1Grafos.hpp"

int main(){
	Grafo myGrafo;
	GrMat GyM;
	MpV filas[MAX];
	map<char,int> mymap;
	map<char, int>::iterator it;
	int nl = 6;
	//~ GyM = myGrafo.crearMatrizYlistAdyAl(myGrafo, nl);
	GyM = myGrafo.crearMLUnid(myGrafo, nl);
	cout<<endl;
	//~ GyM = myGrafo.crearMatrizYlistAdyAlSimple(myGrafo, nl);
	//~ cout<<endl;
	myGrafo = GyM.g;
	myGrafo.iAristas(GyM.m);
	myGrafo.Dijkstra('A', 'E');
	//~ for(char n = 65; n < 65+nl; n++){
		//~ filas[n-65] = myGrafo.reCorsF(n);
		//~ mymap = filas[n-65].valores;
		//~ cout<<BOLDCYAN<<filas[n-65].Proc<<RESET<<endl;
		//~ for (it=mymap.begin(); it!=mymap.end(); ++it)
			//~ cout << BOLDMAGENTA <<it->first <<RESET << BOLDGREEN << " => " << RESET << BOLDYELLOW <<it->second << RESET << '\n';
	//~ }

	//~ myGrafo.eAristas(GyM.m);
	myGrafo.anular();
	return 0;
}
