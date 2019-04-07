//
//  main.cpp
//  shortestPath
//
//  Created by Scott Jackson on 4/4/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>



using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;
using std::make_heap;
using std::pop_heap;
using std::stack;


struct Node  {
    Node (int v) : val(v) {};
    int val;
};


struct Edge{
    Edge (Node * b, int w) : dest(b), weight(w){};
    int weight;
    Node *dest;
    bool operator<(Edge other) const {
        return weight > other.weight;
    }

};


typedef vector<Edge> edges_t;
typedef unordered_map<Node*, edges_t> graph_t;
typedef unordered_map<Node*, int> dist_t;
typedef unordered_map<Node*, Node*> prev_t;
typedef stack<Node *> path_t;

void init_best_distances(edges_t  &best, Node * start){
    
    Edge  s(start, 0);
    best.push_back(s);
    
   
}

void disp_stack(path_t &path ) {
    if (path.empty()) return;
    
    Node * tmp = path.top();
    path.pop();
    disp_stack(path);
    cout << tmp->val << endl;
    
    
    
    
    
}

void shortestPath(graph_t &g, Node *s , Node *e, path_t &path){
    
    // Start a collection of edges
    // to be made into a heap that
    // decide which will be the best
    // node to visit  next
    edges_t distances;
    init_best_distances(distances,s);
    make_heap(distances.begin(), distances.end());
    
    // Tracks the best known distance to a particular node.
    dist_t best_dist;
    
    // Tracks the previous node in the best path.
    // Start Node initialized to NULL because
    // nothing should be behind it./
    prev_t prev_tracker;
    prev_tracker[s] = nullptr;
    
    while (best_dist.find(e) == best_dist.end() && !distances.empty()) {
        
        // Check if we already visited this node.
        if (prev_tracker.find(distances.front().dest) == prev_tracker.end()) {
        
            // Haven't visited it, and it is the next best move
            int cur_weight = distances.front().weight;
            Node * cur =  distances.front().dest;
            cout << "AT: " << cur->val << " with distance " << cur_weight << endl;
            
            // Loop over all the edges of the current Node
            for (int i =0; i < g[cur].size(); i++) {
                
                // Get the Child and Weight of the edge connection
                // and create a new edge with the total weight to
                // this child node
                Node * child = g[cur][i].dest;
                int local_weight =  g[cur][i].weight;
                
                // Add a new total edge calculation to the distance heap.
                Edge e(child, cur_weight+local_weight);
                distances.push_back(e);
                
                // Update the best known path to the node.
                best_dist[child] = cur_weight+local_weight;
                
                prev_tracker[child] = cur;
                
            }
        }
        
        // Now pop off the top of the stack.
        // NOTE: pop_heap partiions the element to remove
        //       by placing it at the end of the stack.
        pop_heap(distances.begin(),distances.end());
        distances.pop_back();
    }
    
    
    Node * index = e;
    path.push(e);
    
    while (path.top() != s) {
        index=prev_tracker[index];
        path.push(index);
    }
    

    disp_stack(path);
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
