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

void swap(string &s, size_t &l, size_t &r) {
    //cout << "SWAPPING: " << l << " " << s[l] << " " << r << " " << s[r] << endl;
    char tmp = s[l];
    s[l] = s[r];
    s[r] = tmp;
}


size_t partition(string &s, m_t &m, size_t  l, size_t r) {
    char p = m[s[(l+r)/2]];
    
    cout << "P: " << p << " " << l << "-" << r << " " << ((l+r)/2) <<endl;
    
    while( l <= r ) {
        cout << " L-> " << l << " " << r  << " " << s << endl;
        
        while(m[s[l]] < p) l++;
        while(m[s[r]] > p) r--;
        cout << ">>>> " << l << " " << r << endl;
        if (l <= r) {
            swap(s,l,r);
            l++;
            r--;
        }
    }
    return l;
}

void my_sort(string &s, m_t &m, size_t l, size_t r) {
    
    //cout << "MY SORT: " << l << " " << r << endl;
    
    if (l>=r || s.empty()) return;
    
    size_t index = partition(s,m,l,r);
    
    cout << ">> S: " << s <<  " " << index << endl;
    
    if (l<r) {
        my_sort(s,m,l,index-1);
        my_sort(s,m,index,r);
    }
}


std::string sortByString(std::string s, std::string t) {
  m_t m;
  build_map(t,m);
  my_sort(s,m,0,s.size()-1);
  return s; 
}

// ##### TESTS ######

void test(int i, string s, string t, string e) {
  string r = sortByString(s,t);
  cout << "TC " << i <<": " << r << "->" << (e==r) << endl;
}


void tc_4(){
     test(4,"kusfiaaqjr", "qsfiaurjk", "qsfiaaurjk");
}

void tc_3(){
     test(3,"sheep", "pseh", "pseeh");
}

void tc_2(){
    test(2,"good", "odg", "oodg");
}

void tc_1(){ 
   test(1,"weather", "therapyw", "theeraw");
}


void tc_0b(){
    test(1,"weather", "aehrtw", "aeehrtw");
}


void tc_0a() {
    m_t m;
    string s ="weather";
    string k = "aehrtw";
    build_map(k,m);
    size_t l = 0;
    size_t r = 6;
    size_t b = partition(s, m, l, r);
    cout << "R: " << b << " " << s << endl;
    

    b = partition(s, m, l, b-1);
    cout << "R: " << b << " " << s << endl;
    
    
    
    
}
void tc_0() {
    m_t m;
    string s ="weather";
    build_map(s,m);
    
    for (m_t::iterator itr = m.begin();itr !=m.end(); itr++)
        cout << itr->first << " " << itr->second << endl;
    
    size_t a = 0;
    size_t b = 6;
    cout << s << endl;
    swap(s,a,b);
    cout << s << endl;
    
    
}
// ### MAIN ###
int main(void) {
    //tc_0a();
    //tc_1();
    //tc_2();
    //tc_3();
    tc_4();
}
