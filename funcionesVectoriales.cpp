#include <vector>

using namespace std;


// u . v = c

double productoPunto( vector< double > u, vector< double> v )    {
   double acumulador = 0;

   if( u.size() != v.size() ) {
       /*
         SI SON DISTINTOS HABRIA QUE HACER ALGO PARA QUE NO LO HAGA
         TIRAR EXCEPCION NO SE
       */

       cout << "Tamaño distinto" << endl;
   }

   vector< double >::iterator i = u.begin();
   vector< double >::iterator j = v.begin();

   while( i != u.end() )    {
       acumulador += (*i) * (*j);
       ++i;
       ++j;
   }

   return acumulador;
}

// u + v = w
vector< double >  sumaVectores( vector< double> u, vector< double > v )    {
    if( u.size() != v.size() ) {
        /*
          SI SON DISTINTOS HABRIA QUE HACER ALGO PARA QUE NO LO HAGA
          TIRAR EXCEPCION NO SE
        */
        cout << "Tamaño distinto" << endl;
    }


    vector< double > w;

    vector< double >::iterator i = u.begin();
    vector< double >::iterator j = v.begin();

    while( i != u.end() )    {
      w.push_back(  *i + *j );
        ++i;
        ++j;
    }

    return w;
}


// a v = w

vector< double > multiplicacionPorEscalar( double a, vector< double > v ) {

    vector< double >::iterator i = v.begin();

    while( i != v.end() )   {
        *i *= a;
        ++i;
    }

    return v;
}

// u - v = w
vector< double >  restaVectores( vector< double> u, vector< double > v )    {
    if( u.size() != v.size() ) {


        /*
          SI SON DISTINTOS HABRIA QUE HACER ALGO PARA QUE NO LO HAGA
          TIRAR EXCEPCION NO SE
        */
    }


    vector< double > w;

    vector< double >::iterator i = u.begin();
    vector< double >::iterator j = v.begin();

    while( i != u.end() )    {
        w.push_back( *i - *j );
        ++i;
        ++j;
    }

    return w;
}
