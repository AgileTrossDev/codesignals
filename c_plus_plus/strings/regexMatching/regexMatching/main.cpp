//
//  main.cpp
//  regexMatching
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description:
// Given a pattern string and a test string, your task is to
// implement regex substring matching. If pattern is preceded
// by a ^, the pattern, excluding the ^, will be matched with
// the starting position of the test string. If pattern is
// followed by a $, the pattern, excluding the $, will be
// matched with the ending position of the test string. If
// no such markers are present, check whether pattern is a
// substring of test, regardless of its position.


#include <iostream>
using std::string;
using std::cout;
using std::endl;


bool regexMatching(std::string pattern, std::string test) {
    //cout  << pattern.substr(0,pattern.length()-1) << " " << test.substr((test.length())-(pattern.length()-1),pattern.length()-1) << endl;
    
    // Pattern checking
    if (pattern[0] == '^')
        return pattern.substr(1,pattern.length()-1) == test.substr(0,pattern.length()-1);
    else if (pattern.back() == '$')
        return pattern.substr(0,pattern.length()-1) == test.substr(test.length()-(pattern.length()-1),pattern.length()-1);
    
    int i = 0;
    while (i < test.length() ){
        
        while (i < test.length() && pattern[0] != test[i] ) i++;
        
        if (i < test.length() && pattern[0] == test[i]) {
            int j = 0;
            while (j< pattern.length() && test[i++] == pattern[j++]) {}
            
            if (j == pattern.length() && test[i-1] == pattern[j-1]) return true;
            
            //i++;
            
        }
    }
    
    
    return false;
}

// -----------------------
void check_results(int c, bool act, bool exp) {
    cout << "TC " << c <<": ACT: " << act << " EXP: " << exp << " -> " << (act==exp) << endl;
    
}

void tc_1(){
    string pat = "^code";
    string test = "codesignal";
    check_results(1,regexMatching(pat,test),true);
}


void tc_2() {
    string pat = "nal$";
    string test = "codesignal";
    check_results(2,regexMatching(pat,test),true);
}

void tc_3() {
    string pat = "hello";
    string test = "world";
    check_results(3,regexMatching(pat,test),false);
}

void tc_4() {
    
    
    string pat ="^gdkhafglsdgaflsdhyfighdsflkjgclksdhgsdjflglsdkfhglkshdfbldkjshfggsfdkastkuyryuewbcbfocyr";
    string test="gdkhafglsdgaflsdhyfighdsflkjgclksdhgsdjflglsdkfhglkshdfbldkjshfggsfdkastkuyryuewbcbfocyrgakjhfgkjsdagfkldasgkfjlhguireyyitfebfghjdgld";
    
    check_results(4,regexMatching(pat,test),true);
}


void tc_5() {
    
    
    string pat ="gdkhafglsdgaflsdhyfighdsflkjgclksdhgsdjflglsdkfhglkshdfbldkjshfggsfdkastkuyryuewbcbfocyr";
    string test="gdkhafglsdgaflsdhyfighdsflkjgclksdhgsdjflglsdkfhglkshdfbldkjshfggsfdkastkuyryuewbcbfocyrgakjhfgkjsdagfkldasgkfjlhguireyyitfebfghjdgld";
    
    check_results(5,regexMatching(pat,test),true);
}


void tc_6() {
    
    
    string pat ="kjgclksdhgsdjflglsdkfhglkshdfbldkjshfggsfdkastkuyryuewbcbfocyr";
    string test="gdkhafglsdgaflsdhyfighdsflkjgclksdhgsdjflglsdkfhglkshdfbldkjshfggsfdkastkuyryuewbcbfocyrgakjhfgkjsdagfkldasgkfjlhguireyyitfebfghjdgld";
    
    check_results(5,regexMatching(pat,test),true);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    tc_2();
    tc_3();
    tc_4();
    tc_5();
    tc_6();
    return 0;
}
