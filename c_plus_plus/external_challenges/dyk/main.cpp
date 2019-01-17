#include<vector>
#include<map>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;

void path_find(int start, int finish, vector<int> &cost, vector<int> &prev, vector<bool> &visited, vector<vector<int> > &edges) {
   visited[start] = true;

   if (start==finish) return;

   for (int i=0;i<edges[start].size();i++) {
     cost[edges[start][i]] = cost[start] + edge[start][i];
   }


}


int main(void) {
    // Verticies and Edges
    int nodes = 11;
    vector<vector<int> > edges;

    // Init Matrix
    for(int i = 0; i < nodes; i++) {
        vector<int> tmp(nodes,0);
        edges.push_back(tmp);
    }

    edges[0][1] = 5;
    edges[0][3] = 4;
    edges[0][2] = 3;
    edges[1][4] = 2;
    edges[2][5] = 9;
    edges[3][4] = 1;
    edges[3][7] = 7;
    edges[3][5] = 8;
    edges[4][6] = 3;
    edges[5][6] = 4;
    edges[6][8] = 6;
    edges[7][9] = 3;
    edges[8][10] = 2;
    edges[9][10] = 1;

    vector<int> cost(nodes,INT_MAX);
    vector<int> prev(nodes,-1);
    vector<bool> visited(nodes,false);

    int start= 0;
    int finish =0;
    
    cost[start] = 0; 

    path_find(start,finish, cost, prev,visited);



}
