#include "matrix.h"


matrix::matrix (int sizex, int sizey, string id = "unknown")
{
    this->id = id;
    this->sizex = sizex;
    this->sizey = sizey;

   data = new double* [sizex];
    for (int i=0; i<sizex; i++){
        data[i]= new double [sizey];
    }

    for(int i=0; i<sizex; i++){
        for(int j=0; j<sizey; j++){
            data[i][j] = 0;
        }
    }
};

void matrix:: print_matrix()
{
    cout << id <<" "<< endl;
    cout << "sizex = " << sizex << "   " << "sizey = " << sizey << endl;
    for(int i=0; i< sizex; i++){
        for(int j=0; j< sizey; j++){
            cout << data[i][j] << " ";
        }
    cout << endl;
    }
};

int matrix:: get_sizex(){
    return sizex;
}

int matrix:: get_sizey(){
    return sizey;
}

double** matrix:: get_data(){
    return data;
}

void matrix:: fill_matrix(){
    for(int i=0; i<sizex; i++){
       for(int j=0; j<sizey; j++){
           data[i][j] = 1;
       }
    }
}

void matrix:: set_id_matrix(string id){
    this-> id = id;
}
