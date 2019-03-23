//
//  main.cpp
//  fillingBlocks
//
//  Created by Scott Jackson on 3/21/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description:
// You have a block with the dimensions 4 × n. Find the number of different
// ways you can fill this block with smaller blocks that have the dimensions 1 × 2.
// You are allowed to rotate the smaller blocks.

#include <iostream>

using std::cout;
using std::endl;


int fillingBlocks(int n) {
    
    if (n==1) return 1;
    if (n==5) return 5;
    
    
}

// --------------------------------------------------------
void disp_result(int n, int res, int exp) {
    cout << "N: " << n << " R: " << res << " E: " << exp << " GOOD: " << (res==exp) << endl;
}

void tc_2() {
    
    int n = 4;
    int res = fillingBlocks(n);
    int exp = 36.
    
    disp_result(n,res,exp);
}


void tc_1() {
    
    int n = 1;
    int res = fillingBlocks(n);
    int exp = 1;
    
    disp_result(n,res,exp);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
