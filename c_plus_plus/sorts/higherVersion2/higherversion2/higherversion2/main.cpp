/*
You have two version strings composed of several non-negative decimal fields that
are separated by periods ("."). Both strings contain an equal number of numeric
fields. Return 1 if the first version is higher than the second version, -1 if
it is smaller, and 0 if the two versions are the same.

The syntax follows the regular semver (semantic versioning) ordering rules:

1.0.5 < 1.1.0 < 1.1.5 < 1.1.10 < 1.2.0 < 1.2.2
< 1.2.10 < 1.10.2 < 2.0.0 < 10.0.0

Example

    For ver1 = "1.2.2" and ver2 = "1.2.0", the output should be
    higherVersion2(ver1, ver2) = 1;

    For ver1 = "1.0.5" and ver2 = "1.1.0", the output should be
    higherVersion2(ver1, ver2) = -1;

    For ver1 = "1.0.5" and ver2 = "1.00.05", the output should be
    higherVersion2(ver1, ver2) = 0.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string ver1

    Correct version as a string.

    Guaranteed constraints:
    1 ≤ ver1.length ≤ 350.

    [input] string ver2

    Correct version as a string.

    Guaranteed constraints:
    1 ≤ ver2.length ≤ 350.

    [output] integer
        Return 1 if ver1 is higher than ver2, -1 if it's smaller, and 0 if the two versions are the same.



*/

#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

void build_v(std::string s, vector<int> &v) {
  size_t start = 0;
  size_t pos = s.find(".");
  std::string::size_type sz;
  while (pos != string::npos) {
     string tmp = s.substr(start,pos-start);
     int tmp2 = stoi(tmp,&sz);
     v.push_back(tmp2);
     //v.push_back(stoi(s.substr(start,pos-start-1))); 
     start = pos+1;
     pos = s.find(".",pos+1);
  }

  string tmp = s.substr(start,s.length()-start);
  int tmp2 = stoi(tmp,&sz);
  v.push_back(tmp2);


}



int higherVersion2(std::string ver1, std::string ver2) { 

  vector<int> v1,v2;
  build_v(ver1,v1);
  build_v(ver2,v2);

  for(int i = 0;i<v1.size();i++){
     if (v1[i] ==v2[i]) continue;
     return (v1[i] > v2[i]) ? 1 : (v1[i] < v2[i]) ? -1: 0;
  }

  return 0;
}




void tc_2() {

  std::string ver1= "1.0.5";
  std::string ver2= "1.1.0";
  int res = higherVersion2(ver1,ver2);
  cout << "RES: " << res << endl;

}    





void tc_1() {
  std::string ver1= "1.2.2";
  std::string ver2= "1.2.0";
  int res = higherVersion2(ver1,ver2);
  cout << "RES: " << res << endl;

}


int main (void) {
   tc_1();
   tc_2();

}
