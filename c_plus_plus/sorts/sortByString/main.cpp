#include<map>
#include<iostream>


using std::map;
using std::cout;
using std::endl;
using std::string;

// ### SOLUTION ####
typedef map<char,int> m_t;


void build_map(string k, m_t &m) {
   for(int i = 0;i<k.length();i++)
      m[k[i]]= i;
}

int partition(string &s, m_t &m, int  l,int r) {
    int p = l;//(r-l)/2 + l;
    cout << s << endl;
    cout << "P: " << p << " " << s[p] << " " << m[s[p]] <<  endl;
    while(l<=r) {
       cout << " >" << l << ":" << r<< endl;
       while(m[s[l]] < m[s[p]]) l++;
       while(m[s[r]] > m[s[p]]) r--;
       cout << " >>" << l << ":" << r<< endl;
       if (l <=r) {
          char tmp = s[l];
          s[l] = s[r];
          s[r] = tmp;
          l++;
          r--;
       }
    }
    cout << s << endl;
    return p;
}
void my_sort(string &s, m_t &m, int l, int r) {
     if (l>=r) return;

     cout << "SORT: " << l << ":" << r << endl;
     int index = partition(s,m,l,r);

     cout << "L " << l << " " << index-1<< endl;
     my_sort(s,m,l,index-1);
     cout <<"R " << index << " " << r << endl;
     my_sort(s,m,index,r);
}


std::string sortByString(std::string s, std::string t) {
  m_t m;
  build_map(t,m);
  my_sort(s,m,0,s.size()-1);
  return s; 
}



void test(int i, string s, string t, string e) {
  string r = sortByString(s,t);
  cout << "TC " << i <<": " << r << "->" << (e==r) << endl;


}

void tc_1(){ 
   test(1,"weather", "therapyw", "theeraw");
}


int main(void) {

   tc_1();

}
