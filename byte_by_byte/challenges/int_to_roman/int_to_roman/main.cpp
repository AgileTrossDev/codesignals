//
//  main.cpp
//  int_to_roman
//
//  Created by Scott Jackson on 4/4/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;


typedef unordered_map<int, string> look_up_t;
typedef vector<int>  digits_t;



look_up_t look_up {
    {1 , "I"},
    {4 , "IV"},
    {5 , "V"},
    {9 , "IX"},
    {10 , "X"},
    {40 , "XL"},
    {50 , "L"},
    {90 , "XC"},
    {100 , "C"},
    {400 , "CD"},
    {500 , "D"},
    {900, "CM"},
    {1000 , "M"}
};
string integerToRoman(int n ) {
    digits_t order {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    
    
    
    string res = "";
    int i = 0;
    while (n  > 0 ) {
        //cout << "N: " << n <<  " " << order[i] << endl;
        if (order[i] <= n) {
        
            n = n- order[i];
            res += look_up[order[i]];
        } else {
            i++;
        }
        
    }
   
    
    
    return res;
}


void exec(int n, string exp) {
    
    string res = integerToRoman(n);
    
    cout << "N: " << n << " RES: " << res << " EXP: " << exp << endl;
}

void tc_1() {
    
    
    exec(1,"I");
    exec(4,"IV");
    exec(49,"XLIX");
    exec(999,"CMXCIX");
    
    
   
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
