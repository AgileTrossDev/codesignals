// Given a String of length S, reverse the whole string without reversing
// the individual words in it. Words are separated by dots.


#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

string reverse(string s){
     string o = "";
     size_t index =0;
     stack<string> stk;

     size_t next = s.find(".");

     while(index < s.length()){
       if (next == string::npos) next = s.length();
       string tmp = s.substr(index,next-index);
       stk.push(tmp);
       index = next+1;
       next = s.find(".",index);
     }
     
     while (!stk.empty()){
         o += stk.top();
         stk.pop();
         if(!stk.empty()) o.push_back('.');
     }
     return o;
}


void tc_1(){
  string i = "i.like.this.program.very.much";
  cout << "INPUT: " << i << endl;
  string o = reverse(i);
  cout << "OUTPUT: " << o << endl;

}


int main(void) {
   tc_1();



}
