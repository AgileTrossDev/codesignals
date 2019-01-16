//
//  main.cpp
//  bfs_shortest_reach
//
//  Created by Scott Jackson on 1/9/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
public:
    vector<vector<int>> edges;
    Graph(int n) {
        edges.resize(n+1);
    }
    
    void add_edge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    vector<int> shortest_reach(int start) {
        
        // Holds the distance to each node,
        // by default set to -1 because
        // we don't know if any is connected.
        // The starting location is set to zero.
        vector<int> result(edges.size(),-1);
        result[start] = 0;
        
        // Queue for the BFS. Seed with the start node
        queue<int> tracker;
        tracker.push(start);
        
        // Tracks the visited Nodes.
        vector<bool> visited(edges.size(), false);
        
        // Process all connected nodes.  tracker will
        // be empty when there are no more connected nodes.
        while (!tracker.empty()) {
            
            // Get next node
            int cur = tracker.front();
            tracker.pop();
            
            // See if there is any reason why not to process it.
            if (visited[cur]) continue;
            visited[cur] = true;
            
            // Now calc distance to edges, and add them to the queue
            // for futuring processing
            for (int i =0; i < edges[cur].size(); i++ ) {
                result[edges[cur][i]] = result[cur] +6;
                tracker.push(edges[cur][i]);
            }
        }
        
        result.erase(result.begin() + start);
        result.erase(result.begin());
        return result;
    }
    
};


void disp(vector<int> &result){
    
    for (int i = 0; i <result.size(); i++) {
        cout << result[i] << " ";
        
    }
    cout << endl;
    
    
}

void test_case_1() {
    Graph g(4);
    
    g.add_edge(1,2);
    g.add_edge(1,3);
               
    vector<int> result = g.shortest_reach(1);
    
    cout << "Test Complete " << endl;
    disp(result);
              
   
}

void test_case_2() {
    Graph g(3);
    g.add_edge(2,3);
    vector<int> result = g.shortest_reach(2);
    
    cout << "Test Complete " << endl;
    disp(result);
    
    
}

void test_case_3() {
    Graph g(7);
    
    g.add_edge(1,2);
     g.add_edge(1,3);
     g.add_edge(3,4);
     g.add_edge(2,5);
    
    vector<int> result = g.shortest_reach(2);
    
    cout << "Test Complete " << endl;
    disp(result);
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test_case_1();
    test_case_2();
    test_case_3();
    return 0;
}
