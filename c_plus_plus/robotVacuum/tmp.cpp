#include<iostream>

using std::endl;
using std::cout;

struct B {
 int x;
 int y;
 int c[4];
 B(int ix,int iy) {
   x = ix;
   y = iy;
   c = {0,1,2,3};
 }

};



int main(void) {
  B b(0,0);
  b.x = 1;
  b.y = 2;

}
