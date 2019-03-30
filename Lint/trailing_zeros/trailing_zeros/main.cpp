//
//  main.cpp
//  trailing_zeros
//
//  Created by Scott Jackson on 3/29/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;


unsigned long long factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int solve(int n) {
    unsigned long long fact = factorial(n);
    int cnt =0;
    
    cout << fact %10 << endl;
    while (!(fact %10)) {
        cout << fact<< endl;
        fact = fact /10;
        
        cnt++;
        
    }
    
    
    
    
    return cnt;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    cout << solve(11) << endl;
    cout << solve(10) << endl;
    return 0;
}
