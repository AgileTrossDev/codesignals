//
//  main.cpp
//  bfs_graph
//
//  Created by Scott Jackson on 12/16/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::vector;


// Node used to construct a graph, which is compromised
// of link list of Nodes.  Each nodes have pointers to
// their edges.
struct Node {
    Node(int i): val(i), left(0), right(0) {};
    void add_edge(Node * i) {
        edges.push_back(i);
    }
    
    void disp(void) {
        cout << " Children:";
        for (int i=0;i<edges.size();i++)
            cout << " " << edges[i]->val;
        cout << endl;
    }
    
    int val;
    vector<Node *> edges;
    Node * left;
    Node * right;
 
};

struct Graph {
    Graph() {};
    
    
    ~Graph() {
        Node * index = root;
        
        while (index) {
            Node * tmp = index;
            index = index->right;
            delete tmp;
            tmp = 0;
        }
    }
    
    Node * add_node(int i) {
        Node * ret = 0;
        if (end_index == 0) {
            // NOTE: this may create a dangling pointer
            root = new Node(i);
            end_index = root;
        } else {
            Node * left =find_node_insert_location(i);
            Node * new_node = new Node(i);
            insert_node_after(left,new_node);
        }
        
        // Roll end marker
        while (end_index->right) {
            end_index =  end_index->right;
        }
        
        return ret;
    }
    
    void add_edges(int i, std::vector<int> e) {
        for (int j =0; j<e.size();j++)
            add_edge(i,e[j]);
    }
    
    
    void add_edge(int  i, int e) {
        Node * node = find_node(i);
        Node * edge = find_node(e);
        node->add_edge(edge);
    }
    
    Node * find_node(int i){
        Node * index = root;
        while (index !=0 && index->val == i )
                index = index->right;
        
        return index;
        
        
    }
    
    Node * find_node_insert_location(int i) {
        // Return values point to the spot after
        // where the new value should be inserted
        // Duplicates are allowed.  This function
        // will return the last occurence of the
        // duplicate value. The last node
        // in the  chain will returned if the input
        // is the largest value in the chain.
        Node * index = root;
        while (index !=0 && index->val >= i )
            if (index->right != 0)
                index = index->right;
        
        return index;
        
    }
    
    void insert_node_after(Node * left, Node * new_node) {
        new_node->left =left;
        new_node->right = left->right;
        left->right = new_node;
        
        if (left->right)
            left->right->left = new_node;
        
    }
    
    void disp () {
        Node * index = root;
        
        while (index) {
            cout << "NODE: " << index->val ;
            index->disp();
            cout << endl;
            index = index->right;
        }
    }

    Node * root =0;
    Node * end_index =0;
};



Graph * build_graph(vector<int>input) {
    Graph * root = new Graph();
    
    for (vector<int>::iterator itr = input.begin();  itr!=input.end(); itr++){
        root->add_node(*itr);
        
    }
    return root;
}


void display_bfs() {
    
    
    
}

void build_graph() {
    
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
