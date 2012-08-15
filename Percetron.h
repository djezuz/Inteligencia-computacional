#ifndef PERCETRON_H
#define PERCETRON_H



/*int main()
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





double productoPunto( vector< double > x, vector< double> y )    {
   acumulador = 0
   for( int i = 0 ; i < x.size(); i++ )    {

       acumulador = x[i] +y[i]
   }

}

double sumaVectores( vector< double> x, vector< double =


class Perceptron    {

vector<double> weights;

void aprender( string fileName ,int numeroVariables, int epocas, int criterio,  double tasa )    {
   /*

       ACA SE LEE EL ARCHIVO

   */

   /*
       INCIAlIAZO TODOS LOS PESOS ALEATORIOS ENTRE ( -0.5 y 0.5 )
   */


   vector< double> oldWeights;
   vector<double> newWeigths;

   for( int i = 0; i < epocas; i++ ) {
       for(  int j = 0 , j < numeroEntrenamientos; j++ )    {
                   y = productoPunto( weigths, x )
       }
       /*
           ASUMIENDO ALGEBRA

           vectorPesosNuevos = vectorPesosViejos + tasa/2 * (  valorDeseado( que esta en el archivo ) -    y ) * vectorXquesaqueDelArchivo )

           vectorPesosViejos = vectorPesosNuevos;
       */
       newWeights = sum( oldWeigths,


   }

}



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

};


#endif // PERCETRON_H
