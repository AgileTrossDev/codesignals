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
   
    
    // Find value to pivot around
    size_t p = m[s[(l+r)/2]];
    
    cout << "P: " << p << " " << l << "-" << r << " | Mid: " << ((l+r)/2) << " Char: " << (s[(l+r)/2]) <<endl;
    
    while( l < r ) {
        //cout << " L-> " << l << " " << r  << " " << s << endl;
        
        // Find elements to swap on either side of partition.
        while(m[s[l]] < p) {
          //  cout << m[s[l]] << " " << p <<  " " << l << endl;
            l++;
        }
        while(m[s[r]] > p) r--;
        
       // cout << ">>>> " << l << " " << r << endl;
        
        if(l>=r) return r;   // No elements to swap
        swap(s,l,r);
        l++;
       
    }
   
    return r;
}

void my_sort(string &s, m_t &m, size_t l, size_t r) {
    
    //cout << "MY SORT: " << l << " " << r << endl;
    
    if (l>=r || s.empty()) return;
    
    size_t index = partition(s,m,l,r);
    
    cout << ">> S: " << s <<  " " << index << endl;
    
    my_sort(s,m,l,index);
    my_sort(s,m,index+1,r);
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
    
    
    b = partition(s, m, l, b);
    cout << "R: " << b << " " << s << endl;
    
    b = partition(s, m, b+1, 5);
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
    tc_0b();
    //tc_1();
    //tc_2();
    //tc_3();
    //tc_4();
}
