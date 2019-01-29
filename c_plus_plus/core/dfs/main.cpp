#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


struct Node {
   Node(int v): val(v){};


   Node * add_new_edge(int v) {
     Node * dest = new Node(v);
     edges.push_back(dest);
     return dest;
   }


   void connect_to_dest(Node* dest) {
     edges.push_back(dest);
   }

   int val;
   vector<Node*> edges;
  


};

struct Graph {
  vector<Node*> nodes;

  Node* add_node(int v) {
      Node * n = new Node(v);
      nodes.push_back(n);
      return n;

  }
  void add_node(Node * n) {
      nodes.push_back(n);
  } 
  

  Node* find_node(int v) {
    for (int i=0;i<nodes.size();i++) {
         if (nodes[i].val == v) return nodes[*];
    }
  }

  void connect(int i, int j) {
      Node * src = find_node(i);
      Node * dest = find_node(j);
      src->connect_to_dest(dest);    
 
 
  }


};


vector<Node*> adj_list_t;


void test_case_1() {
    Graph g;
    
    
    Node * index = g.add_node(0);
    g.add_node(index->add_new_edge(1));
    g.add_node(index->add_new_edge(2));
    

    g.connect(1,2);
    g.connect(2,0);
    g.add_node(root->add_new_edge(3));
   

}

int main(void) {

  test_case_1();


}
