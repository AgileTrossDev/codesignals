//
//  main.cpp
//  find_median
//
// Given that integers are read from a data stream. Find median of elements read so for in efficient way.
// Making it clear, when the input size is odd, we take the middle element of sorted data. If the input
// size is even, we pick average of middle two elements in sorted stream.
//
//  Created by Scott Jackson on 12/26/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

typedef vector<int>  stream_t;


struct Node {
    Node(int v)  : val(v), left(nullptr), right(nullptr) {};
    
    
    int val;
    Node *left;
    Node  * right;
    
    
};


int insert_sort_to_find_median(int val, bool reset = false) {
    static stream_t list;
    if (reset) list.clear();
    
    // Insert into list
    if (list.empty() || val > list.back()) {
        list.push_back(val);
    }  else {
        stream_t::iterator index = list.begin();
        while (*index < val) { index++; }
        
        // Find median
        //for (int i=0;i<list.size();i++) cout << i << ": " << list[i] << endl;
        list.insert(index, val);
     
    }
    
    
    // Find median
    for (int i=0;i<list.size();i++) cout << i << ": " << list[i] << endl;
    
    int ret_val = 0;
    if (list.size() ==2)
        ret_val = list[0];
    else if (list.size()%2 ==0)
        ret_val = ((list[list.size()/2] + list[list.size()/2-1])/2);
    else
        ret_val = list[list.size()/2];
    
    
    return ret_val;
    
    
}


int median_by_heap(int v, Node * &heap) {
    if (heap == nullptr) {
        heap = new Node(v);
        return v;
    }
    
    
    
    
}



void test_case_1() {
    
    stream_t input = { 5, 15, 1, 3,6,7,8,10,2};
    
    
    for (int i=0; i<input.size(); i++) {
        int med = insert_sort_to_find_median( input[i]);
        cout << "MEDIAN: " << med << endl;
    }
    
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    test_case_1();
    return 0;
}
