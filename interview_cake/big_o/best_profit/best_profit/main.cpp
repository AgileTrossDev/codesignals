//
//  main.cpp
//  best_profit
//
//  Created by Scott Jackson on 3/31/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
//  Description: Find best buy and sell times in a sequence of values.  Buy low and sell high.
//
// Lessons Learned
//   - Recogonize this is a sliding window pattern
//   - Draw up edge cases
//   - Hand define nominal solution.
//   - Hand define edge cases.
//   - Write out rules of what conditions occur when using performing calculations....
//            *  Greatest value should always be after lowest value
//            *  OR - the smallest loss will always be between two adjacent nodes
//   - Write out by hand.
//   - track differences 


#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::min;

typedef vector<int> input_t;

int solve(input_t & input) {
    
    int best = INT_MIN;
    size_t cur = 0;
    size_t tail = 0;
    
    size_t highest =  0 ;
    size_t lowest = 0;
    cur++;
    
    while (cur <input.size()) {
        
        // Find the next highest value
        while (cur <input.size() && input[highest]>input[cur]) {
            best = max(best, input[cur]-input[cur-1]);
            cur++;
        }
        
        
        // Only update if we truely have a valid highest value
        if (cur < input.size()) highest =  (input[cur] > input[highest]) ? cur : highest;
        
        // Find the lowest value in the range to the highest value
        while (tail <cur) {
            lowest = (input[lowest] < input[tail]) ? lowest : tail;
            tail++;
        }
        
        
        // Only update the best case when the highest is after the lowest,
        // if not, we did not encounter a positive best.
        if (highest>lowest) best = max(best,input[highest]- input[lowest]);
        cur++;
    }
    
    
    return best;
}

void tc_3(){
    cout << "TEST CASE 3 " << endl;
    input_t input = {20, 18, 16, 14, 10, 9, 7,21};
    
    int res = solve(input);
    cout << "TC 3: " << res << endl;
    
    
}



void tc_2(){
    cout << "TEST CASE 2 " << endl;
    input_t input = {20, 18, 16, 14, 10, 9, 7};
    
    int res = solve(input);
    cout << "TC 2: " << res << endl;
    
    
}


void tc_1(){
    cout << "TEST CASE 1 " << endl;
    input_t input = {10, 7, 5, 8, 11, 9};
    
    int res = solve(input);
    cout << "TC 1: " << res << endl;
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    tc_2();
    tc_3();
    return 0;
}
