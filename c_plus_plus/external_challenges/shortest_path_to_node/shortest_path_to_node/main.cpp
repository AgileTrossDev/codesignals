//
//  main.cpp
//  shortest_path_to_node
//
//  Created by Scott Jackson on 1/7/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> adj_t;



void build_adj(adj_t &adj, vector<int> &graph_from, vector<int> &graph_to) {
    for (int i =0 ; i< graph_from.size();i++) {
        cout << i << endl;
        adj[graph_from[i]-1].push_back(graph_to[i]-1);
    }
    
    for (int i =0 ; i<adj.size();i++) {
        cout << "ADJ: " << i << " -> ";
        for (int j = 0; j< adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    
}



/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 * g_nodes: an integer, the number of nodes
 * g_from: an array of integers, the start nodes for each edge
 * g_to: an array of integers, the end nodes for each edge
 * ids: an array of integers, the color id per node
 * val: an integer, the id of the color to match
 *
 */
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    adj_t adj(graph_nodes);
    build_adj(adj, graph_from, graph_to);
    
    // Start queue for BFS
    queue<long> tracker;
    vector<bool> visited(graph_nodes+1);
    vector<int> distance(graph_nodes+1);
    //vector<long> prev_id(graph_nodes,-1);
    
    // Find the start node
    int start =0;
    while (start < ids.size()) {
        if (ids[start] == val) {
            cout << "S LOC: " << start <<endl;
            tracker.push(start);
            distance[start] = 0;
        }
        start++;
    }
    //if (start >= ids.size()) return -1;
    //start++;
    
    // Init search starting location and distance.
    //distance[start] = 0;
    //tracker.push(start);
    long adj_node = -1;
    
    // Loop until all nodes have been searched or we find the match.
    while (!tracker.empty()) {
        cout << "TOP: " << tracker.front() << endl;
        long current =tracker.front();
        // Check all adjacent nodes.
        for (int i=0; i < adj[current].size() ; i++) {
            adj_node = adj[current][i];
            cout << "CHECKING: " << adj_node << endl;
            
            // Skip if we have visited it already
            if (visited[adj_node] == true) continue;
            visited[adj_node] = true;
            
            // Update distance to this node
            distance[adj_node] = distance[current];
            
            // Check if we are at the destination
            if (ids[adj_node] == val) return distance[adj_node];
            
            // Push it onto the queue and continue the search.
            tracker.push(adj_node);
            
        }
        
        tracker.pop();
        
        
        
    }
    
    return -1;
    
}


void test_case_1() {
    vector<int> graph_from = {4,1,1,4};
    vector<int> graph_to = {3,2,3,2};
    vector<long> ids= {1, 2, 1, 1};
    int val = 1;
    int graph_nodes = 4;
    int result = findShortest( graph_nodes, graph_from,  graph_to,  ids,  val);
    
    cout << "TEST 1: " << result << endl;
    
    
    
}


void test_case_2() {
    vector<int> graph_from = {5,1,1,2,3};
    vector<int> graph_to =   {4,2,3,4,5};
    vector<long> ids= {1, 2, 3, 3, 2};
    int val = 2;
    int graph_nodes = 5;
    int result = findShortest( graph_nodes, graph_from,  graph_to,  ids,  val);
    
    cout << "TEST 2: " << result << endl;
    
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //test_case_1();
    test_case_2();
    
    return 0;
}
