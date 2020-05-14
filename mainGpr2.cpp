#include "pr1Grafos.hpp"

int main(){
	saludos Saludo;
	Grafo myGrafo;
	GrMat GyM;
	MpV filas[MAX];
	map<char,int> mymap;
	map<char, int>::iterator it;
	int nl = 13;
	//~ GyM = myGrafo.crearMatrizYlistAdyAl(myGrafo, nl);
	GyM = myGrafo.crearMLUnid(myGrafo, nl);
	cout<<endl;
	//~ GyM = myGrafo.crearMatrizYlistAdyAlSimple(myGrafo, nl);
	//~ cout<<endl;
	myGrafo = GyM.g;
	myGrafo.iAristas(GyM.m);
	myGrafo.Dijkstra('A', 'M');
	//~ for(char n = 65; n < 65+nl; n++){
		//~ filas[n-65] = myGrafo.reCorsF(n);
		//~ mymap = filas[n-65].valores;
		//~ cout<<BOLDCYAN<<filas[n-65].Proc<<RESET<<endl;
		//~ for (it=mymap.begin(); it!=mymap.end(); ++it)
			//~ cout << BOLDMAGENTA <<it->first <<RESET << BOLDGREEN << " => " << RESET << BOLDYELLOW <<it->second << RESET << '\n';
	//~ }

	//~ myGrafo.eAristas(GyM.m);
	myGrafo.anular();
	
	//~ int opcion;

    //~ do
    //~ {
        //~ printf( "\x1b[31m" "\n   1. mostrar matriz de adyacencia.""\x1b[0m" );
        //~ printf( "\x1b[32m" "\n   2. mostrar lista de adyacencia.""\x1b[0m" );
        //~ printf( "\x1b[34m" "\n   3. mostrar matriz con pesos de aristas." "\x1b[0m");
        //~ printf( "\x1b[35m" "\n   4. algoritmo""\x1b[0m" );
        //~ printf( "\033[33m" "\n   5. salir""\x1b[0m" );
        //~ printf( "\033[1m\033[37m" "\n\n   Introduzca opcion (1-4): ""\x1b[0m" );
        //~ scanf( "%d", &opcion );



        //~ switch ( opcion )
        //~ {
            //~ case 1: printf("\x1b[31m" "\n   imprimiendo... " "\x1b[0m");
					
                    //~ printf("\n    aca ponemos la funcion");
                    //~ break;

            //~ case 2:printf( "\x1b[32m" "\n   imprimiendo... ""\x1b[0m");
                    //~ printf("\n    aca ponemos la funcion");

                    //~ break;
            //~ case 3: printf( "\x1b[34m" "\n   imprimiendo... ""\x1b[0m" );
                    //~ printf("\n    aca ponemos la funcion");
                    //~ break;

            //~ case 4:printf( "\x1b[35m" "\n   camino mas corto... ""\x1b[0m" );
                    //~ printf("\n    aca ponemos la funcion");

         //~ }
         //~ std::cout << std::endl;


    //~ } while ( opcion != 5);
	return 0;
}
