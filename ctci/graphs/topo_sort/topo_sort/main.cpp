//
//  main.cpp
//  topo_sort
//
//  Created by Scott Jackson on 3/31/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::map;
using std::make_heap;
using std::pop_heap;

class Node;

typedef vector<Node*> links_t;
typedef map<int, links_t> matrix_t;
typedef queue<int> result_t;

struct Node {
    Node(int v): val(v),incoming(0){};
    int val;
    int incoming;
};

bool comp_incoming (Node* &a,Node* & b) {
    return a->incoming > b->incoming;
    
}

links_t build_matrix(matrix_t &m) {
    
    links_t nodes (11,nullptr);
    for (int i =0;i<11;i++) nodes[i] = new Node(i);
    
    
    m[0].push_back(nodes[1]);
    
    m[1].push_back(nodes[2]);
    m[1].push_back(nodes[3]);
    m[1].push_back(nodes[5]);
    m[1].push_back(nodes[7]);
    
    m[2].push_back(nodes[4]);
    m[2].push_back(nodes[6]);
    
    m[4].push_back(nodes[9]);
    
    m[5].push_back(nodes[10]);
    
    m[6].push_back(nodes[8]);
    
    m[7].push_back(nodes[2]);
    
    m[8].push_back(nodes[9]);
    
    m[10].push_back(nodes[4]);
    m[10].push_back(nodes[6]);
    
    return nodes;
}

void update_incoming(links_t & nodes, matrix_t &m) {
    
    for (matrix_t::iterator itr = m.begin(); itr!=m.end(); itr++) {
        
        for (int i=0; i<itr->second.size(); i++){
            nodes[itr->second[i]->val]->incoming = nodes[itr->second[i]->val]->incoming+1;
        }
        
    }
    
}

void disp_incoming(links_t & nodes){
    for (int i =0;i<nodes.size();i++)
        cout << i << ": " << nodes[i]->incoming << endl;
}

void process_node(Node * cur, matrix_t &m) {
    cout << cur->val << " is being processed." << endl;
    for (int i=0; i<m[cur->val].size();i++) {
        cout << "REMOVING INCOMING TO: " <<  m[cur->val][i]->val << endl;
        m[cur->val][i]->incoming =  m[cur->val][i]->incoming- 1;
    }
}


result_t topo_sort(links_t & nodes, matrix_t &m){
    result_t results;
    
    update_incoming(nodes,m);
    disp_incoming(nodes);
    
    
    while (!nodes.empty()) {
        make_heap(nodes.begin(),nodes.end(),comp_incoming);
        
        Node * cur = nodes.front();
        cout << "CUR: " << cur->val << " " << cur->incoming <<  endl;
        if (cur->incoming != 0) {

            cout << "ERROR: Cycle in graph.  TODO: Raise exception" << endl;
            results.push(-1);
            return results;
        }
        
        pop_heap (nodes.begin(),nodes.end());
        nodes.pop_back();
        
        process_node(cur, m);
        results.push(cur->val);
        
        
        
    }
    
    
    
    return results;
}

void disp_results(result_t &res){
    
    cout << "RESULTS: ";
    while(!res.empty()){
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;
    
}

void tc_1() {
    matrix_t m;
    links_t links = build_matrix(m);
    
    result_t res = topo_sort(links,m);
    disp_results(res);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
