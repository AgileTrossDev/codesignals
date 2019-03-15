//
//  binary_search.cpp
//  prep
//
//  Created by Scott Jackson on 3/14/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include "binary_search.hpp"
#include<iostream>


using std::vector;
using std::cout;
using std::endl;


// Binary Search
// Floor represents first uncheck canditate
// Ceiling represents the last uncheck canditate
//
// Lessons:
//   - make sure we find the mid-point correctly.  Avoid over runs.
//   - Loop until floor passes ceiling....we can search a range of 1.
//   - If not found, then the next mid_index should not be part of the search
//   - Need to ask about what  should be returned if val not part of vector
//   - Need to catch case of empty vector.

int binary_search(vector<int> v, int val, size_t flr, size_t cel) {
   
    while (flr<=cel) {
        size_t mid_index = flr + (cel-flr)/2;
        
        if (v[mid_index] == val)
            return mid_index;
        else if (v[mid_index] > val)
            cel = mid_index-1;
        else
            flr = mid_index +1;
    }
    
    return -1;
    
}

int binary_search(vector<int> v, int val) {
    return  binary_search(v, val, 0, v.size()-1);
}
