#include <iostream>


using std::cout;
using std::endl;
using std::min;
using std::max;

int main (void) {
  cout << "START" << endl;
  int a = 1;
  int b = 2;
  int c = 1;

  cout << min(a,b) << " " << max(a,b) << " " <<  min(a,c) << " " << max(a,c) << endl;
  cout << "END" << endl;


}
