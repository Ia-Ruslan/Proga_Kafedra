#include <iostream>
#include <string>
#ifndef MATRIX_H
#define MATRIX_H


using namespace std;

class matrix{
private:
   int sizex;
   int sizey;
   double** data;

   std::string id;

public:
   matrix(int sizex, int sizey, string id);
   void print_matrix();
   void set_id_matrix(string id);
   int get_sizex();
   int get_sizey();
   double** get_data();
   void fill_matrix();
   void double_multiply(double a);
   void set_A();

   //friend matrix& operator-(matrix A);
   //friend matrix& operator+(matrix A);

   ~matrix(){
      for(int i=0; i<sizex; i++){
          delete [](data[i]);
      }
    delete [](data);
   }
};

#endif
