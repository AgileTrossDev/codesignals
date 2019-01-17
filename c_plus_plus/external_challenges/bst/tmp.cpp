#include <iostream>
#include <vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

int main(void) {

   vector<int> v = {5,4,3,2,1};

   std::sort(v.begin(),v.end());

   for (int i=0;i<v.size();i++)
     cout << v[i]<< endl;




}
