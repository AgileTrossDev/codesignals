//
//  main.cpp
//  shortest_path
//
//  Created by Scott Jackson on 4/1/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description: Given a directed graph, find the shortest path between two nodes if one exists.

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::stack;

typedef vector<int> edges_t;
typedef vector<edges_t> matrix_t;
typedef queue<int> tracker_t;
typedef stack<int> result_t;

tracker_t solve (int a, int b, matrix_t &m) {
    cout << "SOLVING: " <<  a << "->" << b << endl;
    tracker_t shortest_path;
    
    if (a==b){
        shortest_path.push(a);
        return shortest_path;
    }
    
    
    tracker_t working;
    edges_t prev(m.size(),-1);
    working.push(a);
    
    while (!working.empty() && prev[b] == -1) {
        int cur = working.front();
        working.pop();
        
        for (int i = 0; i<m[cur].size();i++ ) {
            if (prev[m[cur][i]] != -1) continue;
            prev[m[cur][i]] = cur;
            if (b== prev[m[cur][i]]) break;
            working.push(m[cur][i]);
        }
    }
    
    if (prev[b] == -1){
        cout << "NO PATH FOUND" << endl;
        return shortest_path;
    }
    
    int cur = b;
    result_t results;
    results.push(cur);

    while (cur != a) {
        cur = prev[cur];
        results.push(cur);
    }

    while(!results.empty()) {
        shortest_path.push(results.top());
        results.pop();
    }
    
    return shortest_path;
}


matrix_t build_input_1() {
    matrix_t matrix = { { },    // 0
                        {2,3},  // 1
                        {5},
                        {},     // 3
                        {1,3},  // 4
                        {4} };  // 5
    return matrix;
}

void disp(tracker_t p) {
    
    cout << "RESULT: ";
    if (p.empty()) cout << " * NONE * " << endl;
    while (!p.empty()) {
        cout << p.front() << " ";
        p.pop();
    }
    cout << endl;
    
}

void tc_1() {
    matrix_t m = build_input_1();

    tracker_t res1 = solve(2,3,m );
    disp(res1);
    
    
    tracker_t res2 = solve(1,3,m );
    disp(res2);
    
    
    tracker_t res3 = solve(0,3,m );
    disp(res3);
    
    tracker_t res4 = solve(3,3,m );
    disp(res4);
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    
    return 0;
}
