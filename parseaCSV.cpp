#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;



/*
template <class T>
bool from_string(T& t,  const std::string& s, std::ios_base& (*f)(std::ios_base&))
{
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}
*/


//TRANSFORMA ( O INTENTA ) TRANSFORMAR UN STRING A UN DOUBLE */

double stringToDouble( string s )   {

    double d;
    istringstream stream( s );
    stream >> d;

    return d;
}


//CONVIERTE UN ARREGLO QUE TIENE NUMEROS COMO STRING A UN ARREGLO CON NUMEROS DOUBLE

vector< double > convertStringsToDoubles( vector<string> strings )    {
    vector< double> doubles;

    vector<string>::iterator i = strings.begin();

    for( ; i != strings.end(); ++i )   {
        doubles.push_back( stringToDouble( *i ) );
    }

    return doubles;
}

//DESCOMPONE UN STRING Y LOS VA  PONIENDO EN UN ARREGLO CON TIPO STRING

vector<string> parseStringStrings( const string& s, const string& f ) {
    /*
        S I.
      PROBLEMA... ME DEVUELVE UN VECTOR DE STRING EN VEZ DE DOUBLES PERO AL MENOS LO PONE EN ARREGLO
    */

    vector<string> temp;
    if ( f.empty() ) {
        temp.push_back( s );
        return temp;
    }
    typedef string::const_iterator iter;
    const iter::difference_type f_size( distance( f.begin(), f.end() ) );
    iter i( s.begin() );
    for ( iter pos; ( pos = search( i , s.end(), f.begin(), f.end() ) ) != s.end(); ) {
        temp.push_back( string( i, pos ) );
        advance( pos, f_size );
        i = pos;
    }
    temp.push_back( string( i, s.end() ) );
    return temp;
}

//PONE LOS NUMEROS DE UN STRING SEPARADOS POR , EN UN ARREGLO DE DOUBLE

vector< double > parseStringDoubles( const string &s, const string & f )  {


    return convertStringsToDoubles( parseStringStrings(s,","));
}

/*
  LEE EL ARCHIVO .CSV EN LA DIRECCION QUE RECIBE COMO PARAMETRO
  PODRIA EXPLOTAR SI EL ARCHIVO NO EXISTIESE O SI NO TIENE EL FORMATO APROPIADO ( NI PROBE )
  PARECE QUE SI ESTA BIEN FUNCIONA.


  PROBLEMAS CONOCIDOS:

  TIENE QUE TENER UN ENTER DE MAS EL .CSV SI NO, NO LEE LA ULTIMA LINEA.
*/

vector< vector< double > >  parseaCSV( string nombreArchivo )  {

    ifstream archivo( nombreArchivo.c_str() );

    string linea;


    getline (archivo, linea);


    vector< vector< double > > archivoParseado;

    while( !archivo.eof() ) 	{

        if( linea.empty() ) // POR SI EL ARCHIVO TIENE ENTERS DE MAS AL FINAL...
            break;
        vector< double > lineaParseada = parseStringDoubles( linea,  ",");
        archivoParseado.push_back( lineaParseada );
        getline (archivo, linea);
        cout << linea << endl;
    }

    archivo.close();

    return archivoParseado;
}
