#include <iostream>
#include <string>
#include "matrix.h"
#include "vector.h"

using namespace std;

vector_2d operator+ (vector_2d v1, vector_2d v2){

    if(v1.get_size() != v2.get_size()){
        cout<< "Error, different sizes of vectors";
        exit(0);
    }

    vector_2d result(v1.get_size(),"a");

    for(int i=0; i < v1.get_size(); i++){
       result.get_data()[i] += v2.get_data()[i];
    }

    return result;
}


int main()
{
   matrix A(4,6,"A");
   vector_2d v(6,"first vector");
   vector_2d u(6,"first vector");

   A.fill_matrix();
   v.fill_vector();
   u.fill_vector();

   A.print_matrix();
   v.print_vector();

   vector_2d c = v+u;
   c.set_id_vector("Summa");
   c.print_vector();

   vector_2d w(A.get_sizex());
   w.multiply(A,v);
   w.set_id_vector("multiplying result");
   w.print_vector();
    return 0;
}
