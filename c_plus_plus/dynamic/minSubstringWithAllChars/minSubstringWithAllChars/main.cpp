//
//  main.cpp
//  minSubstringWithAllChars
//
//  Created by Scott Jackson on 3/17/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
//  Description:
//  Code Signals - Interview Prep
//  You have two strings, s and t. The string t contains only unique elements.
//  Find and return the minimum consecutive substring of s that contains all
//  of the elements from t.
//
//  It's guaranteed that the answer exists. If there are several answers, return
//  the one which starts from the smallest index.
//
// Lessons Learned:
//   - Never give up - this one hung me up for a while even though I knew the principle
//   - Use Sets to determine if you have a complete winow.
//   - If it appears too complicated, then it probably is too complicated.
//   - Break-up into sub-problems and create functions for each sub-problem if you are stumped.
//   - Test each sub-problem function to make sure your assumptions are correct.



#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::unordered_set;
using std::endl;
using std::cout;

typedef unordered_map<char,int> tracker_t;
typedef unordered_set<char> c_tracker_t;

bool is_valid(char c, string &t) { return (!(t.find(c) == string::npos)); }



// NOTE: Assume a window of t always exists within s
void find_first_window(string &s, string &t, size_t &start, size_t &tail, tracker_t& tracker ) {
    // Build set made up of char in t to help find to complete window
    
    // Init trackers
    c_tracker_t c_tracker;
    for (int j=0;j<t.length();j++) {
        c_tracker.insert(t[j]);
        tracker[t[j]] =0;
    }
    
    
    size_t i = 0;
    
    while (!c_tracker.empty()) {
        if (is_valid(s[i],t)) {
            tracker[s[i]]++;
            if (c_tracker.size() == t.length()) start = i;
            c_tracker.erase(s[i]);
        }
        i++;
    }
    tail = i-1;
    
    
}

bool slide_window(string &s, string &t, size_t &start, size_t &tail, tracker_t& tracker) {
    
    tracker[s[start]]--;
    
    if (0 == tracker[s[start]]) {
        // Need to find replacement for the first character
        while (tail < s.length() && s[tail] != s[start]) {
            tail++;
            if (is_valid(s[tail],t))  tracker[s[tail]]++;
        }
        if (tail>=s.length()) return false;
    }
    
    start++;
    while (!is_valid(s[start],t) && tracker[start] != 1){
        if ( is_valid(s[start],t) && tracker[start]>1) tracker[start]--;
        start++;
    }
    
    
    return true;
}

std::string minSubstringWithAllChars(string s, string t) {
    
    // Input Check
    if (t.size() == 1 || t.empty()) return t;
    
    // First sub Problem:  Find first window
    size_t best_start=0, best_tail=INT_MAX;
    size_t cur_start=0 , cur_tail = 0;
    

    tracker_t tracker;
    
    
    find_first_window(s, t, cur_start, cur_tail,  tracker );
    best_start = cur_start;
    best_tail = cur_tail;
    
    while (slide_window(s, t, cur_start, cur_tail,  tracker)) {
        if (cur_tail-cur_start < best_tail-best_start) {
            best_start =cur_start;
            best_tail = cur_tail;
           // cout << "NEW WINDOW: " << best_start << "-" << best_tail << endl;
        }
    }
    
   

    return s.substr(best_start,(best_tail-best_start)+1);
}

//----------------------------------------------------




void tc_5(){
    cout << "\n\nTC5\n" << endl;
    //          012345678901234567890123
    string s = "nsqlgcrmaqeuqkfwupplrojnhldulpuzkwutacgn";
    string t = "ljqgo";
    string e = "gcrmaqeuqkfwupplroj";
    
    string r= minSubstringWithAllChars(s,t);
    
    cout << "RESULT: \nr: " << r <<  "\ne: " << e  << "\nM: "  << (e==r) << "\nrL: " << r.length() << "\neL: " << e.length() << endl;
    
}


void tc_4(){
    
    //          0123456789012
    string s = "abccbacabbcaabcbcaacbacbacbbcabacba";
    string t = "";
    string e = "abc";
    
    string r= minSubstringWithAllChars(s,t);
    
    cout << "RESULT: " << r << endl;
    
}
void tc_3(){
    
    //          0123456789012
    string s = "abccbacabbcaabcbcaacbacbacbbcabacba";
    string t = "a";
    string e = "abc";
    
    string r= minSubstringWithAllChars(s,t);
    
    cout << "RESULT: " << r << endl;
    
}

void tc_2(){
    
    //          0123456789012
    string s = "abccbacabbcaabcbcaacbacbacbbcabacba";
    string t = "abc";
    string e = "abc";

    string r= minSubstringWithAllChars(s,t);
    
    cout << "RESULT: " << r << endl;
    
}
void tc_1(){
    cout << "\n\nTC1\n" << endl;
    //          0123456789012
    string s = "adobecodebanc";
    string t = "abc";
    string e = "banc";
    
    string r= minSubstringWithAllChars(s,t);
    
    cout << "RESULT: \nr: " << r <<  "\ne: " << e  << "\nM: "  << (e==r) << "\nrL: " << r.length() << "\neL: " << e.length() << endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    //tc_2();
    //tc_3();
    //tc_4();
    tc_5();
    return 0;
}
