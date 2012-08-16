
#ifndef PERCETRON_H
#define PERCETRON_H

#include <vector>
#include <string>
#include "parseaCSV.cpp"
#include "funcionesVectoriales.cpp"


/*
int main()
{
    std::ifstream  data("plop.csv");

    std::string line;
    while(std::getline(data,line))
    {
       std::stringstream  lineStream(line);
       std::string        cell;
       while(std::getline(lineStream,cell,','))
       {
           // You have a cell!!!!
       }
    }
}*/

using namespace std;


class Perceptron    {
public:

    vector<double> weights;


    vector< double > getWeights() {
        return weights;
    }

    void aprender( string nombreArchivo , int epocas, int criterio,  double tasaDeAprendizaje )    {


        vector< vector <double > > archivoParseado = parseaCSV( nombreArchivo );

        int numeroDeLineas = archivoParseado.size();  //Cantidad de lineas del archivo.... numero de entrenamientos?
        int numeroDePesos = archivoParseado[0].size() - 1; // CANTIDAD DE COLUMNAS DEL ARCHIVO - 1 ... LA DE RESULTADO IDEAL

        cout << "Numero de pesos: " << numeroDePesos << endl;
        cout << "Numero de lineas del archivo: " << numeroDeLineas << endl;
        cout << "Hola" << endl;

        //vector< double> oldWeights;  // INICIALMENTE ALEATORIOS
              /*
              OLDWEIGHTS INICIALMENTE ... INCIAlIAZO TODOS LOS PESOS ALEATORIOS ENTRE ( -0.5 y 0.5 )
               POR AHORA EN 0 PARA PROBAR
              */


        for( int i = 0; i < numeroDePesos; i++ )    {
            //cout << "hola" << endl;
            this->weights.push_back( 0.5  );
            //cout << this->weights[i];

        }

        //cout << "hola" << endl;

                    /*
               vector<double> valoresDeseados; //ULTIMA COLUMNA DEL ARCHIVO PARSEADO


               for( int i = 0; i < numeroDeLineas; ++i )
                   valoresDesados.push_back( archivoParseado[i][ numeroDePesos ]);
        */


        for( int e = 0; e < epocas; e++ ) {

            for(  int i = 0 ; i < numeroDeLineas; i++ )    {

                vector< double > x_i ( archivoParseado[ i ].begin(), --(archivoParseado[ i ].end() ) ); //PONE EN EL VECTOR TODAS LAS "COLUMNAS" DE LA LINEA SALVO EL RESULTADO DESEADO.

                cout << x_i[0] << " ";
                cout << x_i[1] << endl;
                double y_i = productoPunto( this->weights, x_i  );

                double y_di = *( --archivoParseado[i].end() ) ; // La salida "deseada" para la linea i


                double factorMultiplicativo = (tasaDeAprendizaje /2 ) * ( y_di - y_i );

                this->weights = sumaVectores( this->weights, multiplicacionPorEscalar( factorMultiplicativo, x_i ) );


            }


            /*
           ASUMIENDO ALGEBRA

           vectorPesosNuevos = vectorPesosViejos + tasa/2 * (  valorDeseado( que esta en el archivo ) -    y ) * vectorXquesaqueDelArchivo )
             */
        }
    }

    double probarConUnaLinea( vector< double > datos )  {
        return productoPunto( weights , datos );
    }


    /*
vector<int> probar( string fileName )    {


   double acumulador;

   int cantidadCasosPrueba;



   for( int j = 0; j < cantidadCasosPrueba; j++ ) {

       for( int i = 0; i < weights.size(); i++ )    {

           acumulador += weigths[i] * casosPrueba[j][i] ;


       }

       resultados[ j ] = acumulador;

   }

   return resultados;
}
*/

};


#endif // PERCETRON_H
