#include <iostream>
using namespace std;

class vector{
  int size;
  std::string id;
  double* data;

public:
  vector(int size, std::string id);
  void print();
  void set_id(std::string id);
};

vector::vector (int size, std::string id = "unknown") {
  this->size = size;
  this->id = id;

  data = new double [size];
  for (int i=0; i<size; i++){
      data[i] = 1.02;
}

}

void vector :: print(){
    cout<< id << " "<< size << endl;
    for (int i=0; i<size; i++){
    cout << i << " " << data[i] << endl;
}

}


int main(){
  int i;
  vector v1(10, "first vector");
  vector v2(9, "second vector");

  v1.print();
  v2.print();

  v2.set_id("I have changed it!");

  cout << "Hi!" << endl;
  return 0;
};
