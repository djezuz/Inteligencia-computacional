#include "parseaCSV.cpp"


int main()
{
    string nombreArchivo = "/home/esteban/Documents/fafa.csv";

    vector< vector <double > > archivoParseado = parseaCSV( nombreArchivo );
    archivoParseado[5][5];
    cout << archivoParseado[1][2];
    return 0;
}

