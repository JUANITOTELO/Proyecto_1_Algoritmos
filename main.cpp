#include "Grafos.hpp"

int main(){
	saludos Saludo;
	Grafo myGrafo;
	GrMat GyM;
	char v1;
	char v2;
	map<char,int> mymap;
	map<char, int>::iterator it;
	int nl;
	cout<<BOLDWHITE<<"Ingrese el nÚmero de vertices para generar un grafo aleatrorio: "<<RESET<<BOLDGREEN;
	cin>>nl;
	cout<<RESET;
	//~ GyM = myGrafo.crearMatrizYlistAdyAl(myGrafo, nl);
	GyM = myGrafo.crearMLUnid(myGrafo, nl);
	cout<<endl;
	//~ GyM = myGrafo.crearMatrizYlistAdyAlSimple(myGrafo, nl);
	//~ cout<<endl;
	myGrafo = GyM.g;
	//~ myGrafo.eAristas(GyM.m);
	int opcion;

    do
    {
        printf( "\x1b[31m" "\n   1. Mostrar matriz de adyacencia.""\x1b[0m" );
        printf( "\x1b[32m" "\n   2. Mostrar lista de adyacencia.""\x1b[0m" );
        printf( "\x1b[34m" "\n   3. Mostrar matriz con pesos de aristas." "\x1b[0m");
        printf( "\x1b[35m" "\n   4. Algoritmo Dijsktra.""\x1b[0m" );
        printf( "\033[33m" "\n   5. Salir""\x1b[0m" );
        printf( "\033[1m\033[37m" "\n\n   Introduzca opción (1-5): ""\x1b[0m" );
        cout<<BOLDGREEN;
        scanf( "%d", &opcion );
		cout<<RESET;


        switch ( opcion )
        {
            case 1: printf("\x1b[31m" "\nimprimiendo... " "\x1b[0m");
					myGrafo.iMatrizDeAdy(GyM.m);
					cout<<BOLDWHITE <<"Numero de Vertices: "<< RESET<< BOLDYELLOW <<myGrafo.size()<< RESET <<endl;
                    break;

            case 2:printf( "\x1b[32m" "\nimprimiendo... ""\x1b[0m");
					myGrafo.listAdya();
					cout<<BOLDWHITE <<"Numero de Vertices: "<< RESET<< BOLDYELLOW <<myGrafo.size()<< RESET <<endl;
                    break;
                    
            case 3: printf( "\x1b[34m" "\nimprimiendo... ""\x1b[0m" );
					myGrafo.iAristas(GyM.m);
					cout<<BOLDWHITE <<"Numero de Vertices: "<< RESET<< BOLDYELLOW <<myGrafo.size()<< RESET <<endl;
                    break;

            case 4:printf( "\x1b[35m" "\ncamino mas corto... ""\x1b[0m" );
					cout<<endl<<"    Ingrese el origen:"<<endl;
					cout<<"    ";
					cin>>v1;
					cout<<"    Ingrese el destino:"<<endl;
					cout<<"    ";
					cin>>v2;
					if(v1>v2){
						myGrafo.Dijkstra(v2, v1);
					}else{
						myGrafo.Dijkstra(v1, v2);
					}
                    cout<<BOLDWHITE <<"Numero de Vertices: "<< RESET<< BOLDYELLOW <<myGrafo.size()<< RESET <<endl;
                    break;

         }
         std::cout << std::endl;


    } while ( opcion != 5);
    myGrafo.anular();
	return 0;
}
