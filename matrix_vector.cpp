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
   void print_matrix();
   void set_id_matrix(string id);
   int get_sizex();
   int get_sizey();
   double** get_data(); 
   void fill_matrix();

   ~matrix(){
      for(int i=0; i<sizex; i++){
          delete [](data[i]);
      }
    delete [](data);
   }
};


class vector_2d{
private:   
   int size;
   string id;
   double* data;

public:
   vector_2d(int size, string id);
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

vector_2d::vector_2d (int size, string id = "unknown"){
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

/*void vector_2d:: set_data(int i, double x){
    data[i] = x;
}*/


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

vector_2d operator+ (vector_2d v1, vector_2d v2){
    
    if(v1.get_size() != v2.get_size()){
        cout<< "Error, different sizes of vectors";
        exit(0);
    }

    vector_2d result (v1.get_size());

    for(int i=0; i < v1.get_size(); i++){
       result.get_data()[i] += v2.get_data()[i];
    }

    return result;
}


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
