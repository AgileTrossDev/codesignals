//
//  main.cpp
//  spot_x_3
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

using std::abs;

using std::string;
using std::max;
using std::min;

string solution(string &S, string &T) {
    // write your code in C++14 (g++ 6.2.0)
    
    // Early exit for already matching
    // or if impossible
    if (S==T) return "NOTHING";
    long tmp =S.length()-T.length();
    tmp = abs(tmp);
    if (  tmp > 1) return "IMPOSSIBLE";
    
    size_t i = 0, j =0;
    int corrections = 0;
    string action = "NOTHING";
    while (i <  S.length() && j < T.length()) {
        if (S[i] != T[j]) {
            // Attempt to correct
            corrections++;
            if (corrections>1) return "IMPOSSIBLE";
            
            if (tmp == 0 && S[i] == T[j+1] && S[i+1] == T[j]) {
                action = "SWAP ";
                action += S[i];
                action +=  ' ';
                action += S[i+1];
                i = i+2;
                j = j+2;
               // cout << "SWAPPING" << endl;
            } else if (tmp ==1 && S[i] == T[j+1]) {
                //cout << "INSERT" << endl;
                action = "INSERT ";
                action += T[j];
                j= j+1;
            } else if (tmp == 1 && S[i+1] == T[j]) {
               // cout << "DELETE" << endl;
                action = "DELETE ";
                action += S[i];
                i= i+1;
            } else {
                //cout << "WEIRD " << i << " " << j << " " << tmp <<  endl;
                return "IMPOSSIBLE";
            }
        } else {
            // Match, so move to next one
            i++;
            j++;
        }
    }
    
    if (corrections ==0 && S.length() < T.length()){
        action = "INSERT ";
        action += T.back();
    } else if  (corrections ==0 && S.length() > T.length()){
        action = "DELETE ";
        action += S.back();
    }
    
    
    return action;
    
    
}


void tc_1() {
    
    string s= "nice", t= "niece";
    string res = solution(s,t);
    
    cout << "TC 1: " << res << endl;
    
    
}


void tc_2() {
    
    string s= "form", t= "from";
    string res = solution(s,t);
    
    cout << "TC 2: " << res << endl;

}


void tc_3() {
    
    // Matching
    string s= "from", t= "from";
    string res = solution(s,t);
    cout << "TC 3: " << res << endl;
    
    
    // TWo swaps
    s= "rfmo";
    t= "from";
    res = solution(s,t);
    cout << "TC 4: " << res << endl;
    
    
    // Delete d
    s= "abcd";
    t= "abc";
    res = solution(s,t);
    cout << "TC 5: " << res << endl;
    
    // Insert d
    s= "abc";
    t= "abcd";
    res = solution(s,t);
    cout << "TC 6: " << res << endl;
    
    
    // Impossible
    s= "abc";
    t= "bacd";
    res = solution(s,t);
    cout << "TC 7: " << res << endl;
    
    // SWAP
    s= "abcd";
    t= "bacd";
    res = solution(s,t);
    cout << "TC 8: " << res << endl;
    
    
    // INSERT
    s= "bcd";
    t= "bacd";
    res = solution(s,t);
    cout << "TC 9: " << res << endl;
    
    // INSERT
    s= "bcda";
    t= "bacd";
    res = solution(s,t);
    cout << "TC 10: " << res << endl;
    
    
    // dELETE d
    s= "bcdad";
    t= "bcda";
    res = solution(s,t);
    cout << "TC 11: " << res << endl;
    
    // INSERT A
    s= "bcd";
    t= "bcda";
    res = solution(s,t);
    cout << "TC 12: " << res << endl;
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //tc_1();
    tc_2();
    //tc_3();
    return 0;
}
