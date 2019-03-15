//
//  main.cpp
//  getPermutations
//
//  Created by Scott Jackson on 3/15/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::map;

typedef unordered_set<string> rec_t;
typedef map<string,rec_t> tracker_t;


void calc(string start_str, string inputString, tracker_t &memo) {

    cout<< start_str << " | " << inputString << endl;
    
    // We already calculated permutation for this input string
    if (memo.end() != memo.find(inputString)) return;
    
    if (inputString.length()<2) {
        // just one characeter, so do that quickly.
        memo[inputString].insert(inputString);
        return;
    }
    
    // Need to calculate permutations of inputString and add them to the memo
    for (int i =0; i < inputString.length(); i++ ){
        
        // Build sub-string we need to merge.
        string sub_str = inputString;
        sub_str.erase(i,1);
        cout << "NEW SUB: " << sub_str << endl;
        
        if (memo.end() ==  memo.find(sub_str)) calc(start_str+inputString[i], sub_str, memo);
        
        if (start_str == "" ) start_str = inputString;
        
        for (rec_t::iterator itr = memo[sub_str].begin(); itr != memo[sub_str].end(); itr++  ){
            memo[start_str].insert(inputString[i] + *itr);
    
        }
    }
    
}

unordered_set<string> getPermutations(const string& inputString)
{
    // generate all permutations of the input string
    tracker_t memo;
    calc("", inputString, memo);
    
    return memo[inputString];
}


void disp (rec_t &s ) {
    cout << "DISPLAYING SET: " << endl;
    for (rec_t::iterator itr= s.begin(); itr != s.end(); itr++)
        cout << *itr << endl;
}

void tc_1(){
    rec_t res = getPermutations("ab");
    disp(res);
}

void tc_2(){
    rec_t res = getPermutations("abc");
    disp(res);
}



int main(int argc, const char * argv[]) {

    tc_2();
  
    
    
    return 0;
}
