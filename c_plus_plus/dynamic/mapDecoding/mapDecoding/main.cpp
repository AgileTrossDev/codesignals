//
//  main.cpp
//  mapDecoding
//
//  Created by Scott Jackson on 3/21/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description:
// A top secret message containing uppercase letters from 'A' to 'Z' has been encoded
// as numbers using the following mapping:
//
// 'A' -> 1
// 'B' -> 2
//  ...
// 'Z' -> 26
//
// You are an FBI agent and you need to determine the total number of ways that the message can be decoded.
//
// Since the answer could be very large, take it modulo 109 + 7.
//
// Lessons Learned:
//   - If you think DP is the approach, look at all 3 approaches (Top-Down,Bottom-Up, Memo). Choose
//     the one with the least amount of calls.
//
//   - As always check the input
//
//   - modulo of 10^9+7 was required to keep values packed in INT.
//


#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;




bool is_valid(string &msg, int start, int digits) {
    if (start+digits > msg.length() || digits>2 || start<0) return false;
    
    if (digits == 1 and msg[start] != '0') return true;
    if (digits == 1 and msg[start] == '0') return false;
    
    string number = msg.substr(start,digits);
    int  num = atoi(number.c_str());
    
    return (num > 9 && num<=26);
    
}

int mapDecoding(std::string msg) {
  
    // Input check
    if (!is_valid(msg,0,1) && !is_valid(msg,0,2)) return 0;
    
    // Track count for bottom-up approach
    vector<int> tracker (msg.length(),0);
    
    // Seed initial state
    if (is_valid(msg,0,1)) tracker[0]++;
    if (is_valid(msg,0,2)) tracker[1]++;
    if (is_valid(msg,1,1)) tracker[1]++;
    
    int m = 1000000007;
    
    // Build up answer from bottom.
    int i =2;
    while (i<msg.length()) {
        if (is_valid(msg,i, 1))  tracker[i] = tracker[i-1]%m;
        if (is_valid(msg,i-1, 2)) tracker[i] = (tracker[i] + tracker[i-2])%m;
        if (!is_valid(msg,i,1) && !is_valid(msg,i-1,2)) return 0;
        i++;
    }
    
    return tracker[msg.length()-1];
}



void tc_1() {
    string msg = "123";
    int exp =3;
    int res = mapDecoding(msg);
    
    cout << "RES: " << res << " EXP: " << exp << " GOOD: " << (res==exp) << endl;
    
}


void tc_0() {
    //           01234567890
    string msg ="1230101";

    cout << (is_valid(msg, 2, 1)) << endl;   // 3  YES
    cout << (is_valid(msg, 2, 2)) << endl;   // 30 NO
    cout << (is_valid(msg, 1, 1)) << endl;   // 2  YES
    cout << (is_valid(msg, 1, 2)) << endl;   // 23 YES
    cout << (is_valid(msg, 3, 1)) << endl;   // 0  NO
    cout << (is_valid(msg, 3, 2)) << endl;   // 01 NO
    cout << (is_valid(msg, 0, 2)) << endl;   // 12 YES
    
    cout << "EXTENDED" << endl;
    cout << (is_valid(msg, 3, 1)) << endl;  // 0  NO
    cout << (is_valid(msg, 3, 2)) << endl;  // 01 NO
    cout << (is_valid(msg, 4, 1)) << endl;  // 1  YES
    cout << (is_valid(msg, 4, 2)) << endl;  // 10 YES
    cout << (is_valid(msg, 5, 1)) << endl;  // 0  NO
    cout << (is_valid(msg, 5, 2)) << endl;  // 01 NO
    cout << (is_valid(msg, 6, 1)) << endl;  // 1  YES
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //tc_0();
    tc_1();
    return 0;
}
