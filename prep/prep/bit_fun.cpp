//
//  bit_fun.cpp
//  prep
//
//  Created by Scott Jackson on 3/18/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include "bit_fun.hpp"
#include <iostream>
using std::cout;
using std::endl;


int move_left(unsigned int n, int shift) {
    cout << "Original: " << n << " ";
    cout << "Shift left " << shift << "spaces ";
    
    int m = n<<shift;
    cout << "Result: " << m << endl;
    
    return m;
}
