#include <iostream>
#include <string>

using namespace std;


#ifndef VECTOR_H
#define VECTOR_H



class matrix;

class vector_2d{
private:
   int size;
   string id;
   double* data;

public:
   vector_2d(int size, std::string id  = "unknown");
   void print_vector();
   void set_id_vector(string id);
   int get_size();
   void fill_vector();
   double* get_data();
   //void set_data(int i, double x);

   friend class matrix;
   friend vector_2d& operator+(vector_2d v1);
   void multiply(matrix& m, vector_2d v);

   /*~vector_2d(){
       delete [](data);
   }*/
};


#endif







