#include <iostream>

#include <map>

using std::cout;
using std::map;
using std::endl;

typedef map<int,int> tracker_t;


int util(int n, tracker_t &t) {
  if (n <= 0) return 0;
  if (t.end() == t.find(n)) t[n] = (util(n-1,t) + util(n-2,t) + util(n-3,t));
  return t[n];
}

int three_step(int n) {
   tracker_t t;
   t[0] = 0;
   t[1] = 1;
   t[2] = 2;
   t[3] = 4;
   return util(n,t);

}


void exec(int n) {
  int r = three_step(n);
  cout << "N: " << n << " R: " << r << endl; 

}

int main(void) {
    exec(0);
    exec(1);
    exec(2);
    exec(3);
    exec(4);
    exec(5);


}
