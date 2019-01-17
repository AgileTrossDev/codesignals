#include<iostream>
using std::cout;
using std::endl;

void d(int i) { cout << i << endl;}
int main() {  
   int i =0;
   d(i);
   d(i++);
   d(i);
   d(++i);
   d(i);
 

}
