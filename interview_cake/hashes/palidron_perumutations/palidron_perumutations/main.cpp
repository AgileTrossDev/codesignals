//
//  main.cpp
//  palidron_perumutations
//
//  Created by Scott Jackson on 3/11/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>

using std::map;
using std::cout;
using std::endl;
using std::string;
using std::set;


typedef map <char,int> tracker_t;


// Answer one
bool hasPalindromePermutation(const string& str)
{
    // check if any permutation of the input is a palindrome
    set<char> tracker;
    
    for(int i = 0; i<str.length(); i++) {
        if (tracker.end() ==  tracker.find(str[i]))
            tracker.insert(str[i]);
        else
            tracker.erase(str[i]);
    }
    
    if (str.length()%2 == 0 && tracker.empty()) return true;
    else if (str.length()%2 == 1 && tracker.size() == 1 ) return true;
    
    
    return false;
}


// ANSWER TWO:
int tacker_update(char c, tracker_t & t) {
    if (t.end() == t.find(c)) t[c] = 0;
    t[c] = t[c]+1;
    return  (t[c]%2 == 0) ? -1 : 1;
}

bool is_palindrome(string input) {
    bool retval = false;
    tracker_t  tracker;
    int odd_cnt = 0;
    
    for (int i = 0; i < input.length(); i++)
        odd_cnt += tacker_update(input[i], tracker);
    
    if ( (input.length()%2 == 0 && odd_cnt ==0) || (input.length()%2 == 1 && odd_cnt==1 ))
        retval = true;
    
    return retval;
}


void exec(int n, string input, bool expected) {
    bool result = is_palindrome(input);
    
    cout << "TC " << n << " " << (expected == result) << endl;
 
    
    
}


void tc_1(){
    
    exec(1, "aabcbcd", true);
    exec(2, "aabccbdd", true);
    exec(3, "aabcd", false);
    exec(4,"aabbcd", false);
    exec(5, "", true);
    exec(6, "a", true);

    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
