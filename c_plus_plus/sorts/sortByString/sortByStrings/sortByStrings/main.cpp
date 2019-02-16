#include<map>
#include<iostream>


using std::map;
using std::cout;
using std::endl;
using std::string;

// ### SOLUTION ####

std::string sortByString(std::string s, std::string t) {
    map<char,int> tracker;
    
    for (int i =0;  i<s.length(); i++){
        map<char,int>::iterator itr = tracker.find(s[i]);
        if (itr == tracker.end())
            tracker[s[i]] = 1;
        else
            tracker[s[i]] = tracker[s[i]] +1;
    }
    
    string result = "";
    
    
    for (int i=0; i < t.length(); i++) {
        if (tracker.end() == tracker.find(t[i])) continue;
        for (int j = 0; j < tracker[t[i]];j++)
            result.push_back(t[i]);
    }
    
    return result;
    
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
