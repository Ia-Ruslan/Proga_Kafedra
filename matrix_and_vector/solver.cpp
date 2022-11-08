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


vector_2d operator- (vector_2d v1, vector_2d v2){

    if(v1.get_size() != v2.get_size()){
        cout<< "Error, different sizes of vectors";
        exit(0);
    }

    vector_2d result(v1.get_size(),"a");

    for(int i=0; i < v1.get_size(); i++){
       result.get_data()[i] -= v2.get_data()[i];
    }

    return result;
}

vector_2d operator- (matrix A, matrix B){
    matrix result(A.get_sizex(), A.get_sizey());
    for (int i=0; i<A.get_sizex(); i++){
        for (int j=0; j<A.get_sizey(); j++){
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

void set_E(matrix E){
    for (int i=0; i<A.get_sizex(); i++){
        for (int j=0; j<A.get_sizey(); j++){
            if (i == j){
                E[i][j] = 1;
            }
            else{
                E[i][j]=0;
            }
        }
    }
}


int main()
{
    matrix A(3, 3,"A");
    vector_2d v_0(3, "first approximation");
    vector_2d b (3,"b");

    vector_2d x_next(v_0.get_size());
    vector_2d x_present = v_0;
   
    double a = 0.1;
    int n = 10;
    vector_2d x(v_0.get_size());
    
    matrix E(3,3,"E");
    matrix Iter(A.get_sizex(), A.get_sizey(), "iteration matrix");

    Iter = E - A.double_multiply(a);

    while(n != 0){  //x_next = x_present + a(Ax_present - b) = (E - aA)x_present - ab

        x.multiply(A, x_present);
        x = x-b;
        x.mult_on_double(x, a);

        x_next = x_present + x;
        
        x_next.print_vector();
        x_present = x_next;
        n--;
    }


    return 0;
}
