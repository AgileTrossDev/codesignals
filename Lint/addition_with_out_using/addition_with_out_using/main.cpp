//
//  main.cpp
//  addition_with_out_using
//
//  Created by Scott Jackson on 3/29/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
using std::max;
using std::min;

int32_t solve (int32_t a, int32_t b) {
    int32_t res =0;
    int32_t mask =1;
    
    while (res < max(a,b)) {
        
        // TODO:
        // To handle negative numbers, find absolute value of negative
        // Track what the sign will be, by which is the largest value
        // Subtract max from min.
        // Adjust to negative if that is the case after calculation.
        
        if (a & mask && b & mask) {
            cout << "BOTH ON" << endl;
            // then we definitely carry,
            // the ecurrent digit in result
            // stays the same.
            mask = mask << 1;
            res = res | mask;
            
        } else if ((a & mask && mask & res) || (b & mask && mask & res)) {
            // one of these elements is causing us to roll
           
            res = res & ~mask;
            mask = mask << 1;
            res = res | mask;
            
            cout << "ONE IS ON WITH RESULT " << res << endl;
        } else  if (a & mask || b & mask) {
            
            res = res | mask;
            mask = mask << 1;
            
            cout << "ONE IS ON " << res << endl;
        } else {
            cout << "NO ACTION" << endl;
             mask = mask << 1;
        }
    }
    
    
    
    
    
    return res;
    
}

int32_t solve2(int32_t x, int32_t y) {
    
    
    
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry now contains common
        //set bits of x and y
        int32_t carry = x & y;
        
        // Sum of bits of x and y where at
        //least one of the bits is not set
        x = x ^ y;
        
        // Carry is shifted by one so that adding
        // it to x gives the required sum
        y = carry << 1;
    }
    return x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    cout << solve(-1,4) << endl;
    cout << solve2(-1,4) << endl;
     cout << solve2(-4,4) << endl;
     cout << solve2(1,4) << endl;
     cout << solve2(0,4) << endl;
    
    return 0;
}
