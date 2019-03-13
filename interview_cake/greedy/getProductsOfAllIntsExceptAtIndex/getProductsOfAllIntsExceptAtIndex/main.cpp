//
//  main.cpp
//  getProductsOfAllIntsExceptAtIndex
//
//  Created by Scott Jackson on 3/13/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;


typedef vector<int> working_t;

vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{
    
    // Brute force is to find the product of every permutation
    // But there is a lot of reputation.
    //
    // By redefining the answer we are looking for we can seee
    // a way to breakdown the calculation.   We calulate the before
    // and after index products to form the corresponding results.
    //
    // We can greedily grow an answer by multiplying the last product
    // by the previous calculation.  THIS IS WHAT MAKES IT GREEDY I GUESS.
    //
    // We can stash these values in their own vector, however upon further
    // review we find that we can save space by removing the temp vectors.
    
    // make a vector with the products
    working_t result (intVector.size(),0);
    
    // Populate the before vector
    working_t before_vector (intVector.size(),1);
    for (int i = 0; i < intVector.size()-1; i++ ) {
        before_vector[i+1] = before_vector[i] * intVector[i];
        
        
    }
    
    int running_product = 1;
    for (int i =  intVector.size()-1;  i >= 0 ; i--) {
        
        result [i] = running_product  * before_vector[i];
        running_product = intVector[i] * running_product;
    }
    
    
    return result;
}


















int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
