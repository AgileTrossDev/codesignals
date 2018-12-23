//
//  main.cpp
//  graph_distance
//
// Description:
// You have a connected directed graph that has positive weights in the adjacency matrix g. The graph
// is represented as a square matrix, where g[i][j] is the weight of the edge (i, j), or -1 if there is
// no such edge.
//
// Given g and the index of a start vertex s, find the minimal distances between the start vertex s and
// each of the vertices of the graph.
//
//  Created by Scott Jackson on 12/15/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//



#include <iostream>
#include <vector>
#include <stack>


using std::vector;
using std::cout;
using std::endl;
using std::stack;
using std::min;


typedef vector<int> output_t;
typedef vector<vector<int> > graph_t;
typedef stack<int> path_t;
typedef vector<bool> visited_t;

bool update_o(output_t &o, int v, int cnt) {
    if (o[v] == -1 || o[v]>= cnt) {
        o[v] = cnt;
        return true;
    }
    return false;
}


// Inputs
//  g  - graph being traversed
//  o  - output representing the min distance to each node
//  d  - current distance on the path
//  v  - marks which nodes have been visisted on this path.
//  p  - stack of the current path, top element is the parent
void traverse(graph_t &g, output_t &o, int d,
              visited_t &v, path_t &p ){
    
    //cout << "TOP: " << p.top()  << " DEPTH: " << d << endl;
    
    if (!p.empty()) {
        // Visiting this node now
        v[p.top()] = true;
        
        // Check to see if this path is the best so far
        if (update_o(o,p.top(),d)) {
            
            // Path to this node is the best so far,
            // so lets dive to the children
            for (int i = 0; i < g[p.top()].size();i++){
                if (g[p.top()][i] >-1 && v[i] == false) {
                    int new_depth = d + g[p.top()][i];
                    //cout << "P: " <<p.top() << " C: "  << i  << " of " << g[p.top()].size()  << " ND: " << new_depth << endl;
                    p.push(i);
                    traverse(g,o,new_depth,v,p);
                }
            }
        }
        
        // Everything with this node is complete
        v[p.top()] = false;
        p.pop();
    }
}

output_t graphDistances(graph_t g, int s) {
    output_t o(g.size(), -1);
    visited_t  v(g.size(), false);
    path_t p;
    p.push(s);
    
    int d = 0;
    
    traverse(g,o,d,v,p);

    

    return o;
    
    
}


void disp(output_t &o) {
    cout << "OUTPUT :";
    for (output_t::iterator  i= o.begin(); i != o.end(); i++)
        cout << *i << " ";
    cout << endl;
}

void test_case_1() {
    graph_t g = {{-1,3,2},
                {2,-1,0},
                {-1,0,-1}};
    int s =  0;
    output_t o = graphDistances(g,s);
    disp(o);
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test_case_1();
    return 0;
}
