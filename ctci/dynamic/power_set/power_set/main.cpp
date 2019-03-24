//
//  main.cpp
//  power_set
//
//  Created by Scott Jackson on 3/23/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;
using std::cout;
using std::endl;

typedef set<int> rec_t;
typedef set<rec_t> output_t;
typedef set<int> input_t;

void solve(input_t &input, output_t &output) {
    
    rec_t empty_set = {};
    output.insert(empty_set);
  
    if (input.empty()) return;
    
    for (input_t::iterator input_itr = input.begin(); input_itr != input.end(); input_itr++) {
        int next_element = *input_itr;
        
        for (output_t::iterator output_itr = output.begin(); output_itr != output.end(); output_itr++) {
            rec_t tmp (*output_itr);
            tmp.insert(next_element);
            output.insert(tmp);
        }
        
        output.insert({next_element});
    }
}

void disp_output(output_t &output, int tc) {
    
    cout << "\n\nTEST CASE " << tc << ": (" << output.size() << ")" <<  endl;
    
    
    for (output_t::iterator output_itr = output.begin(); output_itr != output.end(); output_itr++) {
        cout << "{ ";
        for (rec_t::iterator rec_itr = (*output_itr).begin(); rec_itr != (*output_itr).end(); rec_itr++){
            cout << (*rec_itr) << ", ";
        }
        cout << "}" << endl;
        
        
        
    }
    
}


void tc_1() {
    input_t input = {1};
    output_t output;
    solve(input,output);
    disp_output(output,1);
}

void tc_2() {
    input_t input = {1,2};
    output_t output;
    solve(input,output);
    disp_output(output,2);
}



void tc_3() {
    input_t input = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    output_t output;
    solve(input,output);
    disp_output(output,3);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tc_1();
    
     tc_2();
    tc_3();
    return 0;
}
