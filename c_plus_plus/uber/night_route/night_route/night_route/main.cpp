//
//  main.cpp
//  night_route
//
//  Created by Scott Jackson on 1/28/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
#include<map>

using std::vector;
using std::queue;
using std::priority_queue;
using std::map;
using std::cout;
using std::endl;

// Holds shortest path to city
struct CitySp{
    CitySp(int c,int s):city(c), sp(s) {};
    int city;
    int sp ;
    
    bool operator<(CitySp other) const {
        return sp > other.sp;
    }
};

typedef std::priority_queue<CitySp, std::vector<CitySp>> pq_t;
typedef std::vector<std::vector<int>> graph_t;

void update_queue(pq_t &q, int c, int w) {
    CitySp rec(c,w);
    q.push(rec);
}


int nightRoute(std::vector<std::vector<int>> city) {
    
    // Tracks the known shortest distance to each city.
    vector<int> sp(city.size(),INT_MAX);
    
    // Maps back shortest link to the city
    map<int,int> parent;
    
    // Picks shortest ditance
    pq_t q;
    
    // 0 effot for starting location
    sp[0]= 0;
    parent[0]=0;
   
    update_queue(q,0,0);
    
    // Process until we reach the destination
    while (!q.empty()) {
        // Check the next closest city
        CitySp cur = q.top();
        q.pop();
        if (cur.city==city.size()-1) break;
        
        
        // Haven't reached destination, so update
        // any short pathes to any adjacent nodes
        for(int i=0; i < city[cur.city].size(); i++){
            
            // Check to see if there is an actual path
            if (city[cur.city][i] == -1) continue;
            
            // Find distance to city i from current city
            int poss = sp[cur.city] + city[cur.city][i];
            
            // Check to see if it is the smallest path.
            if (poss < sp[i]) {
                update_queue(q,i,poss);
                sp[i] = poss;
                parent[i] = cur.city;
            }
        }
        
    }
    return sp[city.size()-1];
}


void test_case_1() {
    graph_t g = { { -1, 5, 20},
                  { 21, -1, 10},
        {-1, 1, -1}};
    
    int res = nightRoute(g);
    
    cout << "TC 1: " << res << endl;
    
}

int main(void) {
    
    test_case_1();
    
    
}
