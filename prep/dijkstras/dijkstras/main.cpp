//
//  main.cpp
//  dijkstras
//
//  Created by Scott Jackson on 3/27/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::make_heap;
using std::pop_heap;
using std::set;

class Node;


struct Edge {
    Edge(Node * d, int w): dest(d), weight(w){};
    Node * dest;
    int weight;
    
};

struct Distance {
    Distance(int n, int d): node_key(n), dist(d){};
    int node_key;
    int dist;
    
    bool operator <(const Distance & other) const
    {
        return node_key < other.node_key;
    }
    
    bool operator >(const Distance & other) const
    {
        return node_key > other.node_key;
    }
    
};

struct Node {
    Node(int k, int v): key(k), val(v){};
    
    void add_edge(Node* e, int w ) { edges[e->key] = new Edge(e,w); }
    
    int val;
    int key;
    map<int,Edge*> edges;
    
};

typedef vector<Node*>  matrix_t;
typedef set<int> visited_t;
typedef vector<Distance> distances_t;

void init_distances (distances_t &d, matrix_t &m) {
    for (size_t i =0;i<m.size();i++){
        Distance tmp(m[i]->key,INT_MAX);
        d.push_back(tmp);
    }
}

struct comp{
    bool operator()(const Distance& a,const Distance & b) const{
        return a.dist>b.dist;
    }
};

void heapify(distances_t &d) {
    
    // using make_heap() to transform vector into
    // a min heap
    make_heap(d.begin(),d.end(),comp());
    
}


Distance pop_next(distances_t &d) {
    make_heap(d.begin(),d.end(),comp());
    Distance tmp = d.front();
    pop_heap (d.begin(),d.end(),comp());
    d.pop_back();
    return tmp;
}

bool have_visited(visited_t &visited, int key){
    return  (visited.end() != visited.find(key));
}


int solve(matrix_t &m, int s, int e){
    
    cout << "Calculating shortest path from Node " << s << " to " << e << endl;
    
    // Initialize visited
    visited_t visited;
    
    // Distance vector
    distances_t distances;
    map<int, int> tracking;
    
    // Set initial state;
    Distance tmp (m[s]->key, 0);
    distances.push_back(tmp);
    
    while (!have_visited(visited,e)) {
        Distance cur = pop_next(distances);
        
        if (have_visited(visited,cur.node_key)) continue;
        
        // Mark as visited
        visited.insert(cur.node_key);
        
        // Stash best possible distance
        tracking[cur.node_key] =cur.dist;
        
        // For each edge, update distance
        for (map<int,Edge*>::iterator itr = m[cur.node_key]->edges.begin(); itr != m[cur.node_key]->edges.end();itr++){
            
            // Don't need to include destinations we have visited because
            // if we have been there, we would have already found the
            // shortest route.
            if (have_visited(visited,itr->second->dest->key)) continue;
            
            // Create a new distance to the destination of the edge with the
            // combined wait to the best distance to current location plus
            // the weight of the edge
            Distance d (itr->second->dest->key, cur.dist + itr->second->weight);
            distances.push_back(d);
            
        }
        
    }
    
    
    
    
    
    
    return tracking[e];
    
    
}

matrix_t create_matrix() {
    matrix_t matrix;
    for(int i = 0; i< 10;i++) matrix.push_back(new Node(i,i));
    
    cout << "MATRIX SIZE: " << matrix.size() << endl;;
    
    matrix[0]->add_edge(matrix[9],100);
    matrix[0]->add_edge(matrix[4],25);
    matrix[0]->add_edge(matrix[7],70);
    matrix[0]->add_edge(matrix[1],1);
    
    matrix[1]->add_edge(matrix[2],1);
    matrix[1]->add_edge(matrix[5],5);
    matrix[1]->add_edge(matrix[3],2);
    
    matrix[2]->add_edge(matrix[3],1);
    matrix[2]->add_edge(matrix[4],3);

    matrix[3]->add_edge(matrix[4],1);
    
    matrix[4]->add_edge(matrix[5],1);
    
    matrix[6]->add_edge(matrix[7],1);
    matrix[6]->add_edge(matrix[7],5);
    
    matrix[8]->add_edge(matrix[9],1);
    
    matrix[9]->add_edge(matrix[1],1);
    

    return matrix;
}
matrix_t create_matrix_1() {
    matrix_t matrix;
    for(int i = 0; i< 4;i++) matrix.push_back(new Node(i,i));
    
    cout << "MATRIX SIZE: " << matrix.size() << endl;;
    
    matrix[0]->add_edge(matrix[1],25);
    matrix[0]->add_edge(matrix[2],100);
    matrix[1]->add_edge(matrix[2],25);
    matrix[2]->add_edge(matrix[3],25);
    matrix[0]->add_edge(matrix[3],74);
  
    return matrix;
}




void tc_1() {
    matrix_t m = create_matrix();
    
    int res = solve(m,0,9);
    
    cout << "TC 1: " << res << endl;
    
    
}

void tc_2() {
    matrix_t m = create_matrix_1();
    
    int res = solve(m,0,3);
    
    cout << "TC 2: " << res << endl;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tc_2();
    
    return 0;
}
