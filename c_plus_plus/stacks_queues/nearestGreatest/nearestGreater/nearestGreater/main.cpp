//
//  main.cpp
//  nearestGreater
//
//  Created by Scott Jackson on 12/28/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;


std::vector<int> nearestGreater(std::vector<int> s) {
    
    std::vector<int> ret(s.size(), -1);
    std::stack<int> tracker;
    
    // for each element in the input sequence:
    for (int i = 0; i<s.size(); i++ ) {
        
        while(!tracker.empty() && s[tracker.top()] < s[i]) {
            if (ret[tracker.top()] == -1) {
                // cout << " R INIT: " << tracker.top() << " to " << i << endl;
                ret[tracker.top()] = i; // Left Side wasn't set
            } else if ( (tracker.top() - ret[tracker.top()]) >= (i - tracker.top() +1 )) {
                ret[tracker.top()] = i; // Right side is best
                // cout << " RU: " << tracker.top() << " to " << i << endl;
            }// else Left side has been set is the berst.
            
            tracker.pop();
        }
        
        if (!tracker.empty() &&  ret[i] <tracker.top()) {
            // We found the nearest greatest on left side.
            if( s[i] != s[tracker.top()] ) {
                ret[i] = tracker.top();
                // cout << " INIT : " << i<< " to " << tracker.top()  << endl;
            } else {
                ret[i] = ret[tracker.top()];
            }
        }
        
        
        tracker.push(i);
        
    }
    // cout << "Tracker: " << tracker.size() << endl;
    /* while (!tracker.empty()){
     ret[tracker.top()] = -1;
     tracker.pop() ;
     }
     */
    return ret;
    
    
}

// *****************
// * Test Helpers  *
// *****************
bool compare( std::vector<int>  &a,  std::vector<int> &b) {
    if (a.size() != b.size() ) return false;
    for(int i=0;i<a.size();i++)
        if (a[i] != b[i]) return false;
    
    return true;
    
}

void disp( std::vector<int>  &a) {
    for(int i=0;i<a.size();i++)
        cout << a[i] <<  " ";
    
    cout << endl;
    
    
    
}


// *****************
// * Test Cases    *
// *****************
void test_case_1() {
    std::vector<int> input = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, -1, 4, 7, 8, 9, -1};
    
    std::vector<int> result = nearestGreater(input);
    
    if (!compare(result,expected)) {
        cout << "Test 1 Failed" << endl;
        
        cout << "Expected and Actual" << endl;
        disp(expected);
        disp(result);
        
    } else {
        cout << "TEST CASE 1: PASSES" << endl;
    }
    
    cout << "TEST CASE 1 COMPLETE" << endl;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test_case_1();
    return 0;
}
