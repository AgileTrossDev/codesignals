//
//  main.cpp
//  prep
//
//  Created by Scott Jackson on 3/14/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

#include "binary_search.hpp"
#include "quick_sort.hpp"
#include "binary_tree.hpp"


using std::vector;
using std::cout;
using std::endl;


void disp_vector(vector<int> &v){
    cout << "VECTOR: " << " ";
    for (int i = 0; i < v.size();i++) {
        cout << v[i] << " ";
    }
    
    cout << endl;
}


void tc_binary_tree_1() {
    BinaryTree tree;
    
    
    for (int i =0;i<11;i++) {
        tree.add_node(i);
    }
    tree.disp();
}

void tc_quick_sort_1() {
    vector<int> v = {4,2,7,0,3,1,5,6,9,8,10};
    disp_vector(v);
    quick_sort(v);
    disp_vector(v);
}


void tc_binary_search_1() {
    
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    
    int res = 0;
    
    res = binary_search(v,5);
    cout << "BS.1: " << (res == 4) << endl;
    
    res = binary_search(v,1);
    cout << "BS.2: " << (res == 0) << endl;
    
    res = binary_search(v,10);
    cout << "BS.3: " << (res == 9) << " " << res << endl;
    
    res = binary_search(v,15);
    cout << "BS.4: " << (res == -1) << " " << res << endl;
    
    res = binary_search({1,2},1);
     cout << "BS.5: " << (res == 0) << " " << res << endl;
    
    res = binary_search({1},1);
    cout << "BS.6: " << (res == 0) << " " << res << endl;
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //tc_binary_search_1();
    //tc_quick_sort_1();
    tc_binary_tree_1();
    
    return 0;
}
