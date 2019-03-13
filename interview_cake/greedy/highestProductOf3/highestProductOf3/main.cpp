//
//  main.cpp
//  highestProductOf3
//
//  Created by Scott Jackson on 3/12/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;
using std::invalid_argument;

typedef vector<int> input_t;

// calculate the highest product of three numbers
int highestProductOf3(const vector<int>& vectorOfInts)
{
    // Check Input
    if (vectorOfInts.size() < 3) throw invalid_argument("Less than 3 items!");
    
    // We are going to track the two smallest negative number
    // and two largest positive numbers
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN;
    
    // Hold onto Max Product or two elements
    int mp = INT_MIN;
    
    // Track the 3rd largest value.
    int third = INT_MIN;
    
    // Loop over input and update state as necessary
    for (int i  = 0 ; i < vectorOfInts.size(); i++ ) {
        
        int val = vectorOfInts[i];
        
       // cout << "VAL: " <<  val << " Max1: "  << max1 << " Max2: " << max2 << " MP: " << mp << " 3rd: " << third << endl;
        
        if (val < 0  && min1 == INT_MAX) {
            // Set first min value
            min1 = val;
        } else if (val < 0 && min2 == INT_MAX) {
            // Set second min valu and possibly the mp
            min2 = val;
            mp = max(min1*min2,mp);
        } else if (val >= 0 && max1 == INT_MIN) {
            // set first max value
            max1 = val;
        } else if (val >= 0 && max2 == INT_MIN) {
            // set second max value and possibily mp
            max2 = val;
            mp = max(mp,max1*max2);
            cout << "SETTING MP" << endl;
        } else if ( min(min1,min2) * val > mp) {
            // val changes mp
            
            third = max(third, max(min1,min2));
            
            if (min2 < min1)
                min1 = val;
            else
                min2 = val;
            
            mp = min1 * min2;
            
        } else if (max2 != INT_MIN && max(max1,max2) * val > mp) {
            third = min(max1,max2);
            
            if (max2 < max1)
                max2 = val;
            else
                max1 = val;
            
            mp = max1 * max2;
        } else {
            // two largest accounted for, so set the third
            cout << "SETTING 3rd " << val << " " << third <<  endl;
            third= max(val,third);
            cout << "Mmmm: " << third << endl;
        }
    }
    
    if (min1*min2 == mp) third = max(third,max(max1,max2));
    
    cout << "MP: " << mp << " 3rd: " << third << endl;
   
    return (mp*third);
}


void tc_3() {
    input_t input = {-5, 4, 8, 2, 3};
    int res = highestProductOf3(input);
    
    cout << "RESULT: " << res << endl;
    
    
}



void tc_4(){
    input_t input = {-10, 1, 3, 2, -10};
    int res = highestProductOf3(input);
    
    cout << "RESULT: " << res << endl;
}

void tc_5() {
    
    
    input_t input = {-5, -1, -3, -2};
    int res = highestProductOf3(input);
    
    cout << "RESULT: " << res << endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tc_5();
    
    return 0;
}
