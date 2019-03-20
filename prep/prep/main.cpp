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
#include "tries.hpp"
#include "dfs.hpp"
#include "bit_fun.hpp"


using std::vector;
using std::cout;
using std::endl;

/* *
// 0 1 3 4 5 6
// 1 2 3 4 5 10


// 1 5 6 25 100 101 102

// Test Cases
//  if putInt was not called yet
//  if called once
//  if called odd number of times
//  if called an even number of times
//  if sequential numbers
//  cluster set of numbers with an outlier (large and small)
//  Test case for negative numbers
class doMedian {
    void putInt(int n) {
        collection.push(n);
    }
    int getMedian() {
        
        if (collection.size()== 0) return ;
        
        int result =0;
        std::sort(collection.begin(), collection.end());
        
        if (collection.size() %2 ==0 ){
            // Average of the two medium.
            result = (collection[collection.size()/2] + collection[collection.size()/2+1]);
        } else {
            result = collection[collection.size()/2];
        }
        
        return result;
    }
    
    
    vector<int> collection;
}



*/


void tc_bit_fun_1() {
    
    int n =1;
    int r = move_left(n, 3);
    cout << "GOT: " << r << endl;
    
    
    r = move_left(n, 4);
    cout << "GOT: " << r << endl;
    
    
    
}

void tc_dfs_1() {
    DFS::Vertices v1(1);
    DFS::Vertices v2(2);
    DFS::Vertices v3(3);
    DFS::Vertices v4(4);
    DFS::Vertices v5(5);
    DFS::Vertices v6(6);
    DFS::Vertices v7(7);
    DFS::Vertices v8(8);
    
    v1.add_edge(&v2,10);
    v1.add_edge(&v3,20);
    v1.add_edge(&v4,5);
    
    v2.add_edge(&v5,41);
    
    v3.add_edge(&v5,29);
    v3.add_edge(&v6,60);
    
    v4.add_edge(&v6,45);
    v4.add_edge(&v7,50);
    
    v5.add_edge(&v8,5);
    v6.add_edge(&v8,5);
    v7.add_edge(&v8,5);
    
    cout << "GRAPH CREATED" << endl;
    
    DFS::dfs_path(v1,v8);
    
    
}


void tc_tries_1() {
    TriesNode * root = build_tries({"SCOTT", "SAM", "FRED", "SARA","FRANK","TOM","TODD", "ZED"});
    //root->disp();
    
    cout << "RESULT: " << is_a_word("SCOTT", root) << endl;
    cout << "RESULT: " << is_a_word("BURP", root) << endl;
}

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
    //tc_binary_tree_1();
    
    //tc_tries_1();
    //tc_dfs_1();
    
    tc_bit_fun_1();
    
    return 0;
}
