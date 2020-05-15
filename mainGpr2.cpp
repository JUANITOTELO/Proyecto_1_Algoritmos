#include "pr1Grafos.hpp"

int main(){
	saludos Saludo;
	Grafo myGrafo;
	GrMat GyM;
	MpV filas[MAX];
	char v1;
	char v2;
	map<char,int> mymap;
	map<char, int>::iterator it;
	int nl = 26;
	//~ GyM = myGrafo.crearMatrizYlistAdyAl(myGrafo, nl);
	GyM = myGrafo.crearMLUnid(myGrafo, nl);
	cout<<endl;
	//~ GyM = myGrafo.crearMatrizYlistAdyAlSimple(myGrafo, nl);
	//~ cout<<endl;
	myGrafo = GyM.g;
	myGrafo.iAristas(GyM.m);
	//~ myGrafo.eAristas(GyM.m);
	
	int opcion;

    do
    {
        printf( "\x1b[31m" "\n   1. mostrar matriz de adyacencia.""\x1b[0m" );
        printf( "\x1b[32m" "\n   2. mostrar lista de adyacencia.""\x1b[0m" );
        printf( "\x1b[34m" "\n   3. mostrar matriz con pesos de aristas." "\x1b[0m");
        printf( "\x1b[35m" "\n   4. algoritmo Dijsktra.""\x1b[0m" );
        printf( "\033[33m" "\n   5. salir""\x1b[0m" );
        printf( "\033[1m\033[37m" "\n\n   Introduzca opcion (1-4): ""\x1b[0m" );
        scanf( "%d", &opcion );



        switch ( opcion )
        {
            case 1: printf("\x1b[31m" "\n   imprimiendo... " "\x1b[0m");
					
                    printf("\n    aca ponemos la funcion");
                    break;

            case 2:printf( "\x1b[32m" "\n   imprimiendo... ""\x1b[0m");
                    printf("\n    aca ponemos la funcion");

                    break;
            case 3: printf( "\x1b[34m" "\n   imprimiendo... ""\x1b[0m" );
                    printf("\n    aca ponemos la funcion");
                    break;

            case 4:printf( "\x1b[35m" "\n   camino mas corto... ""\x1b[0m" );
					cout<<endl<<"    Ingrese el origen:"<<endl;
					cin>>v1;
					cout<<"    Ingrese el destino:"<<endl;
					cin>>v2;
					if(v1>v2){
						myGrafo.Dijkstra(v2, v1);
					}else{
						myGrafo.Dijkstra(v1, v2);
					}
                    
                    break;

         }
         std::cout << std::endl;


    } while ( opcion != 5);
    myGrafo.anular();
	return 0;
}
