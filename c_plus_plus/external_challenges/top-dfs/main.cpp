#include <vector>
#include <stack>
#include <iostream>

using std::vector;
using std::stack;
using std::cout;
using std::endl;

struct Node {
   Node(int v): val(v) {};
   int val;
};


struct Graph {
   Graph():v_cnt(-1) {};
   
   // Attributes
   vector<Node*> vert;
   vector<vector<int> > edge_connections;
   int v_cnt;

   int add_node(int v) {
      Node * tmp  = new Node(v);
      v_cnt++;
      vert.push_back(tmp);
      vector<int> edges;
      edge_connections.push_back(edges);
      return v_cnt;
   } 

   void connect_nodes(int id_1, int id_2) {
     edge_connections[id_1].push_back(id_2);
   }
   

   void top_sort_util(int id, stack<int> &tracking,vector<bool> &visited) {
      visited[id] = true;
      for (int i =0; i< edge_connections[id].size(); i++) {
          if (!visited[edge_connections[id][i]]) {
           top_sort_util(edge_connections[id][i],tracking,visited);
          }
      } 
 
      tracking.push(id);
   }

   void top_sort() {
     stack<int> tracking;
     vector<bool> visited(vert.size(),false);

     for(int i=0; i< vert.size();i++) {
         if (!visited[i]) {top_sort_util(i,tracking,visited);}
     }

     while (!tracking.empty()) {
	cout << vert[tracking.top()]->val << endl;
        tracking.pop();
     }
   }
};


int main(void) {
  Graph g;
  for(int i=0;i<6;i++){
    g.add_node(i);
  }
  g.connect_nodes(5,0);
  g.connect_nodes(4,0);
  g.connect_nodes(5,2);
  g.connect_nodes(2,3);
  g.connect_nodes(3,1);
  g.connect_nodes(4,1);

  g.top_sort();

}
