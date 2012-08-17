#include <string>
#include <vector>

#include "Perceptron.h"

using namespace std;

int main()
{
    /*
    string nombreArchivo = "/home/esteban/Documents/fafa.csv";

    vector< vector <double > > archivoParseado = parseaCSV( nombreArchivo );
    archivoParseado[5][5];
    cout << archivoParseado[1][2];
    */

    Perceptron perceptron = Perceptron ();
	
	//ACA VA LA DIRECCION DEL ARCHIVO .CSV , HAY QUE CAMBIARLA EN CADA PC....

    perceptron.aprender( "/home/esteban/Documents/Facultad/IA/ProyectoQt/ProyectoQt/xor.csv", 0.1,10000, 10000);

    vector< double > linea;
	
    linea.push_back(0.9);
	linea.push_back(0.9);
	
    cout << perceptron.probarConUnaLinea( linea );

    return 0;
}

