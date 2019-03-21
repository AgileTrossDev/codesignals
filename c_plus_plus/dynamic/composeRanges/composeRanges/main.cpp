//
//  main.cpp
//  composeRanges
//
//  Created by Scott Jackson on 3/21/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
//
// Description:
// Given a sorted integer array that does not contain
// any duplicates, return a summary of the number ranges
// it contains.
//
// Lessons Learned:
//  - Seriously..... always remember to check the input
//  - Not really sure why this is a dynamic problem, brute force is N
//  - Use stringstreams to build up results easily.

#include <iostream>
#include <vector>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

typedef vector<int> input_t;
typedef vector<string> output_t;

std::vector<std::string> composeRanges(std::vector<int> nums) {
    
    output_t res;
    
    int cur_start = nums[0];
    int cur_exp = nums[0]+1;
    
    for (int i=1;i<nums.size();i++) {
       
        if (nums[i] != cur_exp) {
            ostringstream rec;
            rec << cur_start;
            if (cur_start != cur_exp-1) {
                rec << "->" << (cur_exp-1);
            }
           
            res.push_back(rec.str());
            cur_start = nums[i];
        
            
        }
        cur_exp = nums[i]+1;
        
    }
    
    ostringstream rec;
    rec << cur_start;
    if (cur_start != cur_exp-1) {
        rec << "->" << (cur_exp-1);
    }
  
    res.push_back(rec.str());
   
    return res;
}

void check_result(output_t &res, output_t &exp){
    
    if (res.size() != exp.size()) {
        cout << "Result Size: " << res.size() << " Expected: " << exp.size() << endl;
        
        cout << "RESULT: ";
        for (int i=0;i<res.size(); i++) cout << res[i] << " ";
        cout << endl;
        
        
        cout << "Expected: ";
        for (int i=0;i<exp.size(); i++) cout << exp[i] << " ";
        cout << endl;
    }
    
    
    for (int i=0;i<res.size(); i++) {
        if (res[i] != exp[i]) {
            cout << "Mismatch at Record: " << i << " R: |" << res[i] << "| E:" << exp[i] << endl;
        } else {
            cout << "REC " << i << ": GOOD" << endl;
        }
        
        
    }
    
    
}



void tc_1() {
    input_t nums = {-1, 0, 1, 2, 6, 7, 9};
    output_t res = composeRanges(nums);
    output_t exp = {"-1->2", "6->7", "9"};
    
    check_result(res,exp);
    
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
