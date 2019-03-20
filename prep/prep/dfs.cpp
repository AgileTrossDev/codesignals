//
//  dfs.cpp
//  prep
//
//  Created by Scott Jackson on 3/18/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include "dfs.hpp"
#include <stack>
#include <iostream>
#include <map>
#include <vector>


using std::stack;
using std::cout;
using std::endl;
using std::map;
using std::vector;


namespace DFS {
    Vertices* Vertices::add_edge(int v, int w) {
        
        Vertices* next = new Vertices(v);
        Edges* edge = new Edges(next,w);
        edges.push_back(edge);
        
        return next;
    }


    void Vertices::add_edge(Vertices* v, int w) {
        
        if (!v) return;
        Edges* e = new Edges(v,w);
        edges.push_back(e);
        
    }

    void dfs_path(Vertices &src, Vertices &dest) {
        if (src.val == dest.val) cout << src.val << "->" << dest.val << endl;
        

        stack<Vertices*> working;
        map<int,Vertices*> tracker;
        Vertices* prev = &src;
        
        working.push(&src);
        
        
        while (!working.empty()){
            Vertices* cur = working.top();
            working.pop();
            
            if (cur->val == dest.val) {
                cout << "FOUND DEST" << endl;
                tracker[cur->val] = prev;
                break;
            }
            
            if (tracker.find(cur->val) == tracker.end()) {
                // New Node
                cout << "Visting new Node: " << cur->val << endl;
                tracker[cur->val] = prev;
                prev = cur;
                
                for (int i =0; i<cur->edges.size();i++ ) {
                    working.push(cur->edges[i]->dest);
                }
            }
        }
        
        cout << "Traversed" << endl;
        vector<Vertices*> result;
        result.push_back(&dest);
        
        Vertices* next = tracker[dest.val];
        
        while (next != &src) {
            
            if (next) {
                result.push_back(next);
                next = tracker[next->val];
            }
        }
        result.push_back(&src);
        std::reverse(result.begin(),result.end());
        
        for (int i =0; i <result.size(); i++)
            cout << result[i]->val << "->";
        
        cout << endl;
        
        
        
        
    }
}
