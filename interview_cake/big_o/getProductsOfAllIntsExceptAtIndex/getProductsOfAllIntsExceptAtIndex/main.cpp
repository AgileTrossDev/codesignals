//
//  main.cpp
//  getProductsOfAllIntsExceptAtIndex
//
//  Created by Scott Jackson on 3/31/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

typedef vector<int> working_t;

working_t getProductsOfAllIntsExceptAtIndex(working_t &input) {
    working_t results (input.size(),1);
    
    // Calculating the product except item at index can be written
    // to state that we are calcuklating the product of all ints
    // before index, multiplied by all ints after index.
    
    // Step 1: Calculate all Ints before each index
    int product_so_far = 1;
    for (size_t i=0; i<input.size(); i++) {
        results[i] = product_so_far;
        product_so_far *= input[i];
    }
    
    // Step 2: Find product of all elements after index,
    // and multiply by all elemnts before;
    product_so_far = 1;
    for (size_t i= input.size(); i-- !=0;) {
        cout << i << " " << results[i] << " * " << product_so_far << endl;
        results[i] = product_so_far * results[i];
        product_so_far *=input[i];
        
    }
    
    
    
    
    
    
    return results;
}

void disp(working_t &t) {
    cout << "VECTOR: ";
    for (int i =0; i<t.size();i++)
        cout << t[i] << " ";

    cout << endl;
}


void tc_1() {
    working_t t = {1,7,3,4};
    disp(t);
    working_t r= getProductsOfAllIntsExceptAtIndex(t);
    disp(r);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
