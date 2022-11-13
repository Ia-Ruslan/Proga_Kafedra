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

    vector_2d result = v1;

    for(int i=0; i < v1.get_size(); i++){
       result.get_data()[i] -= v2.get_data()[i];
    }

    return result;
}

/*matrix operator- (matrix A, matrix B){
    matrix result(A.get_sizex(), A.get_sizey(), "result");
    for (int i=0; i<A.get_sizex(); i++){
        for (int j=0; j<A.get_sizey(); j++){
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}*/

/*matrix operator+ (matrix A, matrix B){
    matrix result(A.get_sizex(), A.get_sizey());
    for (int i=0; i<A.get_sizex(); i++){
        for (int j=0; j<A.get_sizey(); j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}*/

/*void set_E(matrix E){
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
}*/



int main()
{
    matrix A(3, 3,"A");
    vector_2d x_present(3, "starts with v_0");
    vector_2d b (3,"b");

    x_present.set_vector();
    x_present.print_vector();
    cout <<endl;

    A.set_A();
    A.print_matrix();
    cout <<endl;

    b.set_b();
    b.print_vector();
    cout <<endl;

    //vector_2d x_present = v_0;
    vector_2d x_next(x_present.get_size());
   
    double a = 0.1;
    int n = 5;
    vector_2d x(x_present.get_size());
    
   // matrix E(3,3,"E");
   // E.set_E();
   // matrix Iter(A.get_sizex(), A.get_sizey(), "iteration matrix");

    vector_2d xsi (x_present.get_size());

    while(n != 0){  //x_next = x_present + a(Ax_present - b) = (E - aA)x_present - ab

        x.multiply(A, x_present);
        x.print_vector();
       
        xsi = x - b;
        xsi.set_id_vector("xsi ");
        xsi.print_vector();

        x_next = x_present + xsi.mult_on_double(a); 
        x_next.set_id_vector(" interation ");
        x_next.print_vector();

        x_present = x_next;
        n--;
        cout << endl << endl;

    }

    x_present.set_id_vector("final result");
    cout << endl;
    x_present.print_vector();


    return 0;
}
