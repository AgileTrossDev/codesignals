#include<iostream>
#include<utility>
#include<map>

using std::map;
using std::pair;
using std::cout;
using std::endl;

typedef pair<int,int> loc_t;
typedef map<loc_t,int> m_t;

int main (void) {
  loc_t a(1,2);


  m_t m;
  m.insert(make_pair(a,5));
  m.insert(make_pair(loc_t(5,5),11 ));
  cout << m[a] << endl; 
  cout << m[loc_t(5,5)] << endl;
  



}
