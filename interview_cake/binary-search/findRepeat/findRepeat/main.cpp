//
//  main.cpp
//  findRepeat
//
//  Created by Scott Jackson on 3/13/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


typedef vector<unsigned int> input_t;


unsigned int findRepeat(const vector<unsigned int>& theVector)
{
    // find a number that appears more than once
    size_t flr = 0, cel = theVector.size()-1;
    
    
    while (flr<cel) {
        size_t mid = flr + (cel-flr);
        
        cout << mid << endl;
        if (  theVector[mid] == theVector[mid-1]
            || (mid <= theVector.size()-1< theVector[mid] == theVector[mid+1]))
            return theVector[mid];
        
        
        if (mid == theVector[mid]-1)
            flr = mid;
        else
            cel = mid;
    }
    
    return 0;
}

void tc_1() {
    input_t v = {1,1};
    
    unsigned int res = findRepeat(v);
    
    cout << "RESULT: " <<  res << endl;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
