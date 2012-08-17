#ifndef LIBRERIA_H
#define LIBRERIA_H

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cstdlib>

double stringToDouble( string s );


//TRANSFORMA ( O INTENTA ) TRANSFORMAR UN STRING A UN DOUBLE */



//CONVIERTE UN ARREGLO QUE TIENE NUMEROS COMO STRING A UN ARREGLO CON NUMEROS DOUBLE

vector< double > convertStringsToDoubles( vector<string> strings );
//DESCOMPONE UN STRING Y LOS VA  PONIENDO EN UN ARREGLO CON TIPO STRING

vector<string> parseStringStrings( const string& s, const string& f );

//PONE LOS NUMEROS DE UN STRING SEPARADOS POR , EN UN ARREGLO DE DOUBLE

vector< double > parseStringDoubles( const string &s, const string & f );

/*
  LEE EL ARCHIVO .CSV EN LA DIRECCION QUE RECIBE COMO PARAMETRO
  PODRIA EXPLOTAR SI EL ARCHIVO NO EXISTIESE O SI NO TIENE EL FORMATO APROPIADO ( NI PROBE )
  PARECE QUE SI ESTA BIEN FUNCIONA.


  PROBLEMAS CONOCIDOS:

  TIENE QUE TENER UN ENTER DE MAS EL .CSV SI NO, NO LEE LA ULTIMA LINEA.
*/

vector< vector< double > >  parseaCSV( string nombreArchivo ) ;






// u . v = c

double productoPunto( vector< double > u, vector< double> v );
// u + v = w
vector< double >  sumaVectores( vector< double> u, vector< double > v );


// a v = w

vector< double > multiplicacionPorEscalar( double a, vector< double > v );

// u - v = w
vector< double >  restaVectores( vector< double> u, vector< double > v ) ;

#endif
