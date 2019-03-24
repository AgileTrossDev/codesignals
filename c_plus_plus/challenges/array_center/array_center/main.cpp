//
//  main.cpp
//  array_center
//
//  Created by Scott Jackson on 3/23/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
//include <stdlib.h>
#include <cmath>


using std::vector;
using std::cout;
using std::endl;
using std::min_element;
using std::accumulate;
using std::begin;
using std::end;


vector<int> arrayCenter(vector<int> a) {
    int min_a = *(min_element(begin(a), end(a)));
    float total_a = accumulate( a.begin(), a.end(), 0.0);
    float avg_a = total_a/a.size();
    
    cout << min_a << " " << avg_a << endl;
    
    int best_start = 0;
    int best_end = 0;
    int cur_start = 0;
    int cur_end = 0;
    
    vector<int> b  = {};
    
    
    int i =0;
    while (i<a.size() ) {
        
        cout << i << "->" << a[i] << " : "  << best_start << " " << best_end << " |" << (a[i] - avg_a) << "<" << min_a << " || " << avg_a << " "  << total_a <<  endl;
        
        

        if ( abs(a[i] - avg_a) <min_a) {
            cur_start = i;
            while (abs((a[i] - avg_a)) <min_a) {
                b.push_back(a[i]);
                i++;
            }
            cur_end =i;
            
            if (cur_end-cur_start > best_end-best_start){
                best_start = cur_start;
                best_end = cur_end;
            }
        } else {
           
        }
        i++;
        
    }
    
    cout << i << " " << best_start << " " << best_end << endl;
    
    //vector<int> b (a.begin()+best_start,a.begin()+best_end);
    return b;
}


void disp_vector(vector<int> &b) {
    cout << "VECTOR: ";
    for (int i =0; i<b.size();i++)
        cout << b[i] << " ";
    
    cout << endl;
    
}



void tc_3() {
    vector<int> input = {1, 3, 2, 1};
    vector<int> b =  arrayCenter(input);
    disp_vector(b);
}

void tc_2() {
    vector<int> input = {8, 3, 4, 5, 2, 8};
    vector<int> b =  arrayCenter(input);
    disp_vector(b);
}
void tc_1() {
    vector<int> input = {1,2,3,4,5,6,7};
    arrayCenter(input);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_2();
    tc_3();
    return 0;
}
