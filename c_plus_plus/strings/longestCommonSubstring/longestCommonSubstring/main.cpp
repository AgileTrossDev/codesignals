//
//  main.cpp
//  longestCommonSubstring
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description:
// Given two strings, s and t, find the length of their longest common substring.


#include <iostream>
using std::string;
using std::endl;
using std::cout;
using std::max;


int longestCommonSubstring(std::string s, std::string t) {
    
        // Create a table to store lengths of longest common suffixes of
        // substrings.   Note that LCSuff[i][j] contains length of longest
        // common suffix of s[0..i-1] and t[0..j-1]. The first row and
        // first column entries have no logical meaning, they are used only
        // for simplicity of program
        int LCSuff[s.length()+1][t.length()+1];
    
        // Stores length of the longest common substring
        int result = 0;
        
        // Following steps build LCSuff in bottom up fashion.
        for (int row=0; row<=s.length(); row++) {
            for (int col=0; col<=t.length(); col++) {
                if (row == 0 || col == 0)
                    LCSuff[row][col] = 0;
                else if (s[row-1] == t[col-1]) {
                    cout << s[row-1] << " match at: " << (row-1) << "->" << (col-1) << endl;
                    LCSuff[row][col] = LCSuff[row-1][col-1] + 1;
                    result = max(result, LCSuff[row][col]);
                }
                else LCSuff[row][col] = 0;
            }
        }
        return result;
}


void tc_1() {
    int res = longestCommonSubstring("abc","abcd");
    cout << "TC 1: " << res << endl;
}

void tc_2() {
    int res = longestCommonSubstring("bcd","abcd");
    cout << "TC 2: " << res << endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_2();
    return 0;
}
