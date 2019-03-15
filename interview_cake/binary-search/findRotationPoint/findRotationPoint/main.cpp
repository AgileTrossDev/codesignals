//
//  main.cpp
//  findRotationPoint
//
//  Created by Scott Jackson on 3/13/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::string;

size_t findRotationPoint(const vector<string>& words)
{
    // find the rotation point in the array
    size_t flr = 0;
    size_t cel = words.size();
    
    if (words.size() <= 1) return 0;
    
    while (flr < cel) {
        
        // Find mid-point
        size_t mid_index=  flr+((cel-flr)/2);
        
        // Check to see if we have a match, by looking at the element
        // before.  If it is greater then we found it.  Or if there is
        // only 1 element, then we found it.
        if (mid_index == 0 ||  words[mid_index-1] > words[mid_index]) return mid_index;
        
        // Adjust flr and cel accordingly.   If the mid is less then the flr,
        // then the pivot must be in left half, lese it is on the right half
        if ( words[mid_index] < words[flr])
            cel = mid_index;
        else
            flr = mid_index;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
