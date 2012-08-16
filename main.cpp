#include <string>
#include <vector>

#include "Percetron.cpp"

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

    perceptron.aprender( "/home/esteban/Documents/Facultad/IA/or.csv", 1, 100, 0.1 );

    vector <double > weights = perceptron.getWeights();

    cout << weights[0] << endl;
    cout << weights[1] << endl;


    vector< double > linea;
    linea.push_back(1);
    linea.push_back(1);
    cout << perceptron.probarConUnaLinea( linea );


    return 0;
}

