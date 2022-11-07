#include "vector.h"
#include "matrix.h"

using namespace std;

vector_2d::vector_2d (int size, std::string id){
  this -> size = size;
  this -> id = id;

  data = new double [size];
  for (int i=0; i<size; i++){
      data[i] = 0;
  }
}

void vector_2d:: fill_vector(){
    for(int i=0; i<size; i++){
      data[i] = 1;
    }
}

int vector_2d:: get_size(){
   return size;
}

double* vector_2d:: get_data(){
    return data;
};

void vector_2d:: set_id_vector(string id){
    this->id = id;
}

void vector_2d:: print_vector(){
   cout << id << " " << "size = " << size << endl;
   for (int i=0; i<size; i++){
       cout << data[i] << endl;
   }
}

/*void vector_2d:: multiply_on_number(double a){
   for(int i=0; i<size; i++){
    data[i] = a * data[i];
   }
}*/


void vector_2d:: multiply(matrix& m, vector_2d v)
{
    if (m.get_sizey() != v.get_size())
    {
        cout<< "Error, different sizes";
        exit(0);
    }

    //vector_2d result (m.get_sizey());

    for(int i=0; i<m.get_sizex(); i++){
       double res = 0;
       for(int j=0; j<m.get_sizey(); j++){
           res += m.get_data()[i][j]* v.get_data()[j];
           //cout << " " << res;
       }
       //cout << res << endl;
       data[i] = res;
       //cout << result.data[i] << endl;
    }
}

void vector_2d:: mult_on_double(vector_2d v, double a){
    for(int i=0; i<size; i++){
        v.data[i] = a* v.data[i];
    }
}