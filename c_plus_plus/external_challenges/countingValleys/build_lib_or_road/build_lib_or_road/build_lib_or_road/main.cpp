//
//  main.cpp
//  build_lib_or_road
//
//  Created by Scott Jackson on 1/6/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using std::vector;
using std::stack;
using std::cout;
using std::set;
using std::endl;

typedef  vector<vector<int>> input_t;
typedef stack<int> tracker_t;

// Transforms cities into an adjency vector
void build_adj_vector(vector<vector<int>> &cities, input_t &adj) {
    
    for (int i = 0 ; i<cities.size(); i++) {
        int c1 = cities[i][0];
        int c2 = cities[i][1];
        
        // Bidirectional connection
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
}

// DFS potential road network and return min number of roads to repair
int exec_util(tracker_t &tracker, input_t &input, vector<bool> &visited) {
    int cnt =0;
    while (!tracker.empty()) {
        int src = tracker.top();
        tracker.pop();
        if (visited[src] == true) continue;
        visited[src] = true;
        
        // Check all possible destinations from this city
        for (int i =0; i<input[src].size();i++) {
            int dest = input[src][i];
            if (visited[dest] == true) continue;
            
            // City is unconnected, so it needs a road
            cnt++;
            //visited[dest] = true;
            tracker.push(dest);
        }
    }
    return cnt;
    
}


// Complete the roadsAndLibraries function below.
long attempt_1(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    
    // Check if the cost to build library in every city is
    // less than best case scenario of building roads to
    // every city, plus a single library
    if ( (c_lib * n) < ( (c_road * (n - 1)) + c_lib) )  return (c_lib * n);
    
    // It's not, so we need to build a minimum road map to determine the best
    // deal.
    vector<bool> visited(n,false);
    long lib_cnt = 0;
    int roads_built = 0;
    input_t input(n);
    build_adj_vector(cities, input);
    
    // Begin traversing over all unvisited cities,
    // to see how many roads are needed to connect
    // the them.
    tracker_t tracker;
    for (int i=0; i<n; i++){
        if (visited[i] == true) continue;
        tracker.push(i);
        
        roads_built = roads_built + exec_util(tracker, input, visited);
        //cout << "CITY: " << i << " R: " << roads_built << endl;
        
        // Cluster complete./
        lib_cnt++;
        
        // Check if a complete network has been built
        if (roads_built == n-1) break;
    }
    
    //cout << "ROADS: " << roads_built << " LIBS: " << lib_cnt << endl;
    //if ( (c_lib * n) < ( (c_road*roads_built) + c_lib*lib_cnt))  return c_lib*n;
    return (lib_cnt * c_lib + roads_built*c_road);
    
}

long attempt_2 (int n, int c_lib, int c_road, vector<vector<int>> cities) {
    
    // Check if the cost to build library in every city is
    // less than best case scenario of building roads to
    // every city, plus a single library
    if ( (c_lib * n) < ( (c_road * (n - 1)) + c_lib) )  return (c_lib*n);
    
    // It's not, so we need to build a minimum road map to determine the best
    // deal.
    vector<bool> visited(n,false);
    int roads_built = 0;
    
    for (int i=0; i <cities.size(); i++ ){
        int c1 = cities[i][0];
        int c2 = cities[i][1];
        if (visited[c1] == true && visited[c2] == true) continue;
        roads_built++;
        visited[c1] = true;
        visited[c2] = true;
    }
    
    // At this point we have rebuilt all the necessary roads.
    // We need N-1 to be fully connected
    long lib_cnt = n -roads_built;
    //cout << "ROADS: " << roads_built << " LC: " << lib_cnt << endl;
    
    if ( (c_lib * n) < ( (c_road*roads_built) + c_lib*lib_cnt))  return c_lib*n;
    return (lib_cnt * c_lib + roads_built*c_road);
    
    
    
}



// Complete the roadsAndLibraries function below.
long roadsAndLibrariesa(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    
    // Check if the cost to build library in every city is
    // less than best case scenario of building roads to
    // every city, plus a single library
    if (c_lib<  c_road) return  (c_lib * n);
    //cout << "HERE" << endl;
    
    // It's not, so we need to build a minimum road map to determine the best
    // deal.
    vector<bool> visited(n,false);
    long lib_cnt = 0;
    long roads_built = 0;
    input_t input(n);
    build_adj_vector(cities,input);
    
    // Begin traversing over all unvisited cities,
    // to see how many roads are needed to connect
    // the them.
    tracker_t tracker;
    for (int i=0; i<n; i++){
        if (visited[i] == true) continue;
        tracker.push(i);
        visited[i] = true;
        
        cout << "LOOPING: " << i << " " << lib_cnt << " " << roads_built <<  endl;
        
        // Add all unvisted cities
        for(int j = 0; j < input[i].size(); j++){
            int dest = input[i][j];
            if (visited[dest] == true) continue;
            tracker.push(dest);
        }
        
        
        // Build library for zone
        lib_cnt++;
        
        // Connect rest of the network
        while(!tracker.empty()) {
            // Find next unvisited city
            int cur = tracker.top();
            //cout << "WORKING:  " << cur <<endl;
            tracker.pop();
            if (visited[cur] == true) continue;
            roads_built++;
            
            visited[cur] = true;
            
            
            for(int x =0; x<input[cur].size();x++){
                int dest = input[cur][x];
                if (visited[dest] == true) continue;
                
                //cout << "2nd GEN CONNECTION: " << dest << endl;
                tracker.push(dest);
                
            }
            
           
        }
    }
    
    cout << "ROADS: " << roads_built << " LIBS: " << lib_cnt << endl;
    //if ( (c_lib * n) < ( (c_road*roads_built) + c_lib*lib_cnt))  return c_lib*n;
    
    // Return the Lib Cost
    //cout << "Unconnected: " << visited.size() - visited_cnt << endl;
    //lib_cnt = lib_cnt + visited.size() - visited_cnt;
    
    //long res =(lib_cnt * c_lib + roads_built * c_road )
    return 0;
    
}



long dfs(long index,int clib, int cpath, vector<bool> &visited, input_t &adj, bool flag = false){
    long cost = 0;
    if(flag == true ){
        cost += clib;
    }else {
        cost += cpath;
    }
    
    // Visted this place
    visited[index] = true;
    
    // Visit the adjecent cities
    for(int i = 0 ; i < adj[index].size() ; i ++){
        long vertex = adj[index][i];
        if(!visited[vertex]){
            cost += dfs(vertex,clib,cpath,visited,adj);
        }
    }
    return cost;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
   
    if(c_lib <= c_road){ return ((long)n * c_lib); }
    
    input_t adj(n+1);
    build_adj_vector(cities,adj);
    
    vector<bool> visited(n+1,false);
    long cost = 0;
    for(int i = 1 ;i <= n ; i ++) {
        if(visited[i] == false){
            cost+= dfs(i,c_lib,c_road,visited,adj, true);
        
        }
    }
    
    
    
    return cost;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    input_t cities { {1,2}, {1,3}, {1,4} };
    int n = 5;
    int c_lib = 6;
    int c_road  = 1;
    long res = 0;
     res = roadsAndLibraries( n,  c_lib,  c_road,  cities);
    
    cout << "1 RESULT: " << res << endl;
    
    
    // the number of cities, number of roads, cost of a library and cost of a road.
    input_t cities_2 { {1,2}, {3,1}, {2,3} };
    n = 3;
    c_lib =  2;
    c_road  = 1;
    res = roadsAndLibraries( n,  c_lib,  c_road,  cities_2);
    
    cout << "2 RESULT: " << res << endl;
    
    
 
    
    

    input_t cities_3 { {1,3}, {3,4}, {2,4},{1,2},{2,3},{5,6} };
    n = 6;
    c_lib =  2;
    c_road = 5;
    res = roadsAndLibraries( n,  c_lib,  c_road,  cities_3);
    
    cout << "3 RESULT: " << res << endl;
   
    
    input_t cities_4 { {1,3}, {3,4}, {2,4},{1,2},{2,3},{5,6} };
    n = 7;
    c_lib =  5;
    c_road = 2;
    res = roadsAndLibraries( n,  c_lib,  c_road,  cities_4);
    cout << "4 RESULT: " << res << endl;

    
    input_t cities_5 { {1,2}, {1,3}, {1,4} };
    n = 5;
    c_lib =  6;
    c_road = 1;
    res = roadsAndLibraries( n,  c_lib,  c_road,  cities_5);
    
    cout << "5 RESULT: " << res << endl;

    
    
    return 0;
}
