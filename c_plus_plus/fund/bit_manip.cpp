#include <iostream>

using std::cout;
using std::endl;

void d (int a ) {
   cout<<a <<endl;

}
int main(void) {
   int a =1;
   d(a);

   a= a << 1;
   d(a);
   a= a << 1;
   d(a);
   

   a=1;
   d(a);
   a= a << 2;
   d(a);
   
   a = a >> 3;
   d(a);
   a = a ^ 8;
   d(a);

   a= ~a;
   d(a);

   


}
