
#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <string>
#include "libreria.h"


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
	
	//CREO QUE LA FUNCION DE ACTIVACION DEBERIA SER UN MIEMBRO DE LA CLASE Perceptron
	
	//Incluye el bias
    vector<double> weights;

	//Retorna los pesos. Incluye el bias
    vector< double > getWeights() {
        return weights;
    }

    void aprender( string nombreArchivo , double tasaAprendizaje, int nEpocas,  double criterioFinalizacion )    {
	/*
		Por ahora no uso el criterioDeFinalizacion... hago un numero fijo de epocas.
	*/

        vector< vector <double > > archivoParseado = parseaCSV( nombreArchivo );

        int numeroDeLineas = archivoParseado.size();  //Cantidad de lineas del archivo.... numero de entrenamientos?
        int numeroDePesos = archivoParseado[0].size(); // CANTIDAD DE COLUMNAS DEL ARCHIVO - 1 (RESULTADO IDEAL) + 1 (EL BIAS ).

		/*
        cout << "Numero de pesos: " << numeroDePesos << endl;
        cout << "Numero de lineas del archivo: " << numeroDeLineas << endl;
        cout << "Hola" << endl;
		*/
     
        /*
              OLDWEIGHTS INICIALMENTE ... INCIAlIAZO TODOS LOS PESOS ALEATORIOS ENTRE ( -0.5 y 0.5 )
               POR AHORA EN 0 PARA PROBAR
				QUE ALGUIEN INVESTIGUE COMO CREAR LOS NUMEROS ALEATORIOS 
        */

		
        for( int i = 0; i < numeroDePesos; i++ )    {
            this->weights.push_back( 0.5  );
        }

        for( int e = 0; e < nEpocas; e++ ) {
			
            for(  int i = 0 ; i < numeroDeLineas; i++ )    {

                vector< double > x_i ( archivoParseado[ i ].begin(), --(archivoParseado[ i ].end() ) ); //PONE EN EL VECTOR TODAS LAS "COLUMNAS" DE LA LINEA SALVO EL RESULTADO DESEADO.
				
				x_i.insert( x_i.begin(), -1.0 ) ;// Le agrego este valor al principio de cada linea para poder incluir el bias en la sumatoria ( Poder realizar producto punto )
												// Poco veloz me parece habria que cambiarlo
				
				/*
					Para hacerlo mas general habria que recordar la forma de pasar funciones como parametros de funciones
					cosa de poder mandar funciones de activacaciones mas gral y no usar solo signo.
				*/
				
				double y_i = productoPunto( this->weights, x_i  ) > 0 ? 1 : -1;  // Si > 0 y_i = 1
                double y_di = *( --archivoParseado[i].end() ) ; // La salida "deseada" para la linea i

                double factorMultiplicativo = (tasaAprendizaje /2 ) * ( y_di - y_i );
                this->weights = sumaVectores( this->weights, multiplicacionPorEscalar( factorMultiplicativo, x_i ) );
            }
        }
    }
	
	// LO MISMO ACA TENDRIA QUE IR LA FUNCION DE ACTIVACION EN VEZ DE  -1 o 1
    double probarConUnaLinea( vector< double > datos )  {
		return ( productoPunto( vector< double > ( ++( weights.begin() ), weights.end() )  , datos )  - *weights.begin() ) > 0 ? 1 : - 1;
        //return productoPunto( this->weights, datos ) > 0 ? 1 : -1 ;
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


#endif // PERCEPTRON_H
