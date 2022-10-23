#include <iostream>
using namespace std;

class matrix{
private:
   int sizex;
   int sizey;
   double** data;

   std::string id;

public:
   matrix(int sizex, int sizey, string id);
   void printing();
   void set_id(string id);


  /* matrix* operator+ (matrix B){

   return C;
   };*/


   ~matrix()
   {
      for(int i=0; i<sizex; i++){
          delete [](data[i]);
      }
    delete [](data);
   }
};

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
            data[i][j] = i+j;
        }
    }
};

void matrix:: printing()
{
    cout << id <<" "<< endl;
    for(int i=0; i< sizex; i++){
        for(int j=0; j< sizey; j++){
            cout << data[i][j] << " ";
        }
    cout << endl;    
    }
};


int main()
{
   matrix A(2,3,"first array");
   matrix B(4,4,"second array");

   B.printing();
   A.printing();

    return 0;
}
