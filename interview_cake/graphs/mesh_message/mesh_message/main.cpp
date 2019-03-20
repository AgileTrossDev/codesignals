//
//  main.cpp
//  mesh_message
//
//  Created by Scott Jackson on 3/17/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::queue;
using std::unordered_map;
using std::invalid_argument;

typedef queue<string> tracker_t;
typedef unordered_map<string,string> back_tracking_t;

vector<string> getPath(const unordered_map<string, vector<string>>& graph,
                       const string& startNode, const string& endNode)
{
    // find the shortest route in the network between the two users
    tracker_t tracker;
    tracker.push(startNode);
    
    back_tracking_t b_tracker;
    b_tracker[startNode] = startNode;
    string prev = startNode;
    bool found = (startNode == endNode) ;
    if (graph.find(endNode) == graph.end() || graph.find(startNode) == graph.end())
        throw invalid_argument("POOP");
    
    while (!tracker.empty() && !found) {
        
        string cur = tracker.front();
        tracker.pop();
        
        for (size_t i=0; i < graph.at(cur).size(); i++) {
            string pot = graph.at(cur)[i];
            if (b_tracker.find(pot) != b_tracker.end()) continue;
            b_tracker[pot] = cur;
            
            tracker.push(pot);
            
            if (pot == endNode)   {
                found = true;
                break;
            }
        }
    }
    
    string cur =endNode;
    vector<string> result;
    
    if (found) {
        while (cur != startNode){
            result.push_back(cur);
            cur = b_tracker[cur];
        }
        result.push_back(startNode);
        std::reverse(result.begin(),result.end());
    } else if (tracker.empty()) {
        //throw invalid_argument("POOP");
    }
    return  result;
}


unordered_map<string, vector<string>> getNetwork()
{
    return unordered_map<string, vector<string>> {
        { "a", {"b", "c", "d"} },
        { "b", {"a", "d"} },
        { "c", {"a", "e"} },
        { "d", {"a", "b"} },
        { "e", {"c"} },
        { "f", {"g"} },
        { "g", {"f"} }
    };
}

void disp(vector<string> &v) {
    cout << "VECTOR: ";
    for (int i =0; i< v.size(); i++) {
        cout << v[i] <<" ";
    }
    cout << endl;
}


void tc_1() {
    
    vector<string> res = getPath(getNetwork(), "a", "e");
    disp(res);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
