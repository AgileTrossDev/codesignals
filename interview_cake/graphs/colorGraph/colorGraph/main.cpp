//
//  main.cpp
//  colorGraph
//
//  Created by Scott Jackson on 3/17/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using std::unordered_set;
using std::vector;
using std::queue;
using std::string;
using std::cout;
using std::endl;
using std::logic_error;
using std::invalid_argument;

class GraphNode;

typedef vector<GraphNode*> graph_t;
typedef queue<GraphNode*> tracker_t;
typedef unordered_set<GraphNode*> neighbors_t;
typedef unordered_set<string> colors_t;

class GraphNode {
private:
    string label_;
    unordered_set<GraphNode*> neighbors_;
    string color_;
    
public:
    GraphNode(const string& label) : label_(label), neighbors_(), color_() {}
    
    const string& getLabel() const { return label_; }
    const unordered_set<GraphNode*> getNeighbors() const { return neighbors_; }
    void addNeighbor(GraphNode& neighbor) { neighbors_.insert(&neighbor); }
    bool hasColor() const { return !color_.empty(); }
    
    const string& getColor() const {
        if (hasColor())
            return color_;
        else
            throw logic_error("GraphNode is not marked with color");
    }
    
    void setColor(const string& color) { color_ = color; }
};

void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors) {
    // create a valid coloring for the graph
    
    // Prime queue for BFS of graph
    tracker_t tracker;
    tracker.push(graph[0]);
    
    // While queue is not empty....
    while(!tracker.empty()) {
        
        // Get next node
        GraphNode* cur = tracker.front();
        tracker.pop();
        
        // Gather surrounding colors and add it's neighbors to the queue
        colors_t used_colors;
    
        neighbors_t neighbors = cur->getNeighbors();
        //cout << "CURRENT NODE: " << cur->getLabel() << " HAS " <<  neighbors.size() << " neighbors" << endl;
        for (neighbors_t::iterator itr = neighbors.begin(); itr != neighbors.end(); itr++) {
            GraphNode* neighbor = *itr;
            if (cur == neighbor) throw invalid_argument("BURP");
            //cout << "LOOP" << endl;
            if (neighbor->hasColor()) {
                used_colors.insert(neighbor->getColor());
            } else {
               //cout << "TRACKING: " << neighbor->getLabel() << endl;
                tracker.push(neighbor); // unvisited
            }
        }
        
        int color_index = 0;
        while (used_colors.end() != used_colors.find(colors[color_index])) {color_index++;}
        cur->setColor(colors[color_index]);
        
        if (tracker.empty()) {
            for (int i =1; i< graph.size();i++)
                if (!graph[i]->hasColor()){
                    tracker.push(graph[i]);
                    break;
                }
        }
        
    }
}


void disp (graph_t & g) {
    
    for (int i = 0; i < g.size(); i++) {
        cout << g[i]->getLabel();
        
        if (g[i]->hasColor()) cout << " (" << i << "): " << g[i]->getColor() << " -> ";
        
        neighbors_t neighbors = g[i]->getNeighbors();
        for (neighbors_t::iterator itr = neighbors.begin(); itr != neighbors.end();itr++) {
            if ((*itr)->hasColor()) cout << ((*itr)->getColor()) << " ";
        }
        cout << endl;
        
    }
    
    
}


void tc_1() {
    
    GraphNode * nodeA = new GraphNode("A");
    GraphNode * nodeB = new GraphNode("B");
    GraphNode * nodeC = new GraphNode("C");
    GraphNode * nodeD = new GraphNode("D");
    
    nodeA->addNeighbor(*nodeB);
    nodeB->addNeighbor(*nodeA);
    nodeB->addNeighbor(*nodeC);
    nodeC->addNeighbor(*nodeB);
    nodeC->addNeighbor(*nodeD);
    nodeD->addNeighbor(*nodeC);
    
    vector<GraphNode*> graph = {nodeA,nodeB,nodeC,nodeD};
    vector<string> colors = {"RED", "GREEN", "BLUE" , "YELLOW", "ORANGE"};
    colorGraph(graph,colors);
    
    cout << "COMPLETE...displaying..." << endl;
    disp(graph);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
