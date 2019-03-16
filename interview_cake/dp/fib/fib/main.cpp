//
//  main.cpp
//  fib
//
//  Created by Scott Jackson on 3/16/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

// Lessons Learned....
//   - Fib inheritantly has an overlapping sub-problems.
//   - Drawing the call branches will show duplicate work.
//   - So a memo could work to remove duplicate work
//   - Building up from the bottom avoids the need for memo and space cost


int fib(int n)
{
    
    // edge case: negative index
    if (n < 0) {
        throw std::invalid_argument(
                               "Index was negative."
                               " No such thing as a negative index in a series.");
    }
    
    
    // compute the nth Fibonacci number
    if (n== 0  || n == 1) return n;
    int n2 = 0;
    int n1 = 1;
    int x = 2;
    
    
    while (x != n ) {
        int tmp = n1;
        n1 = n1 + n2;
        n2 = tmp;
        x++;
    }
    
    
    
    
    
    return n2+n1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
