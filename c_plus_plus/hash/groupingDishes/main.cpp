#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;


typedef vector<int> vi_t;


int main(void) {
  cout << "START" << endl;

  string a = "ABC";
  string b = "BCA";

  cout << (a==a) << (a<b) << (a>b) << endl;



  vi_t v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.push_back(4);

  vi_t::iterator i = v.begin();

  i++;
  i++;

  v.insert(i,5);

  for (i=v.begin();i<v.end();++i)
   cout << (*i) << " ";


  cout << endl;
  

  

  cout << "END" << endl;

}
