#include <iostream>


using std::cout;
using std::endl;



int main(void) {

  int a = 5;
  cout << a << endl;
  cout << (a++) << endl;
  cout << a << endl;
  cout << ++a << endl;
  cout << a << endl;


  int b = 5;
  int c = 6;

  cout << b << " " << c << endl;
  cout << ++b + ++c << endl;
  cout << b << " " << c << endl;
  cout << b++ + c++ << endl; 
  cout << b << " " << c  << endl;
  cout << b++ + ++c << " " << b << " " << c << endl;
  cout << b << " " << c << endl; 

}
