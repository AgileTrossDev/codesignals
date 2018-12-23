//
//  main.cpp
//  dfs_graph
//
// Write a function to print the depth first traversal for a undirected graph from a given source s.
//
// Input:
// The task is to complete the function DFS which takes 3 arguments an integer denoting the starting
// node (s) of the dfs travel , a  graph (g)  and an array of visited nodes (vis)  which are
// initially all set to false.
//
// There are multiple test cases. For each test case, this method will be called individually.
//
// Output:
// The function should print the depth first traversal for the graph from the given source.
//
//  Created by Scott Jackson on 12/14/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;

typedef vector<int> output_t;
typedef vector<vector<int> > graph_t;
typedef vector<bool> visited_t;
typedef stack<int> tracker_t;


void traverse_graph(graph_t &g, visited_t &v,output_t &o,tracker_t &t){
    if (!t.empty()) {
    
        int cur = t.top();
        t.pop();
        
        if (v[cur] == false){
            v[cur] = true;
            o.push_back(cur);
            for (int i =0; i< g[cur].size(); i++){
                t.push(g[cur][i]);
            }
        }
    
        traverse_graph(g,v,o,t);
        
    }
    
}

output_t dfs_graph(int s,  graph_t &g) {
    visited_t v(g.size(),false);
    output_t o;
    tracker_t t;
    t.push(s);
    traverse_graph(g,v,o,t);
    return o;
}


void disp(output_t o) {
    cout <<"OUTPUT (" << o.size() << "): ";
    for (int i =0; i <o.size(); i++)
        cout << o[i] << " ";
    
    
    cout << endl;
    
    
}

bool test_case_1() {
    
    graph_t g {{1,2,3,4}, {}, {}, {5}, {}, {}};
    output_t o = dfs_graph(0,g);
    disp(o);
    return o[0]==0 && o[1]==4 && o[2]==3 && o[3]==5 && o[4]==2  && o[5]==1;
    
}


int main(int argc, const char * argv[]) {

    bool res =test_case_1();
    cout << "TEST CASE 1: " << res << endl;
    
    return 0;
}
