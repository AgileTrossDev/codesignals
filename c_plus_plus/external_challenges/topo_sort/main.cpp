#include<iostream>
#include<vector>
#include<stack>


using std::cout;
using std::endl;
using std::vector;
using std::stack;

struct Node {
    Node(int v): val(v){};
    Node * add_edge(int v) {
        Node * tmp = new Node(v);
        edges.push_back(tmp);
        return tmp;  
    }
    void add_edge(Node *v) {
        edges.push_back(v);
    }
    int val;
    vector<Node *> edges;


};

struct Graph {
  Node * add_vertix(int v) {
      Node * tmp = new Node(v);
      verticies.push_back(tmp);
      return tmp;
  }
  void add_vertix(Node * v) {
      verticies.push_back(v);
  }
  void disp() {
     for (int i=0; i<verticies.size();i++)
        cout << verticies[i]->val << endl;

  }
  vector<Node*> verticies;

};

void topo_sort_util(Node* v, stack<Node *> &tracker, vector<bool> &visited) {
    visited[v->val] = true;
    cout << "AT: " << v->val << endl;
    for (int i=0; i<v->edges.size();i++){
          if (!visited[v->edges[i]->val])
               topo_sort_util(v->edges[i],tracker,visited);

    }


    tracker.push(v); 
 



}

void top_sort(Graph &g) {
    stack<Node*> tracker;
    vector<bool> visited(g.verticies.size(),false);
   
    for (int i=0; i<g.verticies.size();i++) {
            cout << "I: " << i << endl;
            if (!visited[g.verticies[i]->val]) {
                  topo_sort_util(g.verticies[i],tracker,visited);
            }

    }


    while (!tracker.empty()){
        cout << tracker.top()->val << endl;
        tracker.pop();
 
    }

}

int main (void) {
   Graph g;
   Node * index = g.add_vertix(5);

   Node * child = index->add_edge(3);
   g.add_vertix(child);

   child = child->add_edge(2);
   g.add_vertix(child);

   child = child->add_edge(1);
   g.add_vertix(child);

   Node * tmp  = g.add_vertix(4);

   tmp->add_edge(child);

   child = tmp->add_edge(0);
   index->add_edge(child);
   g.add_vertix(child);


   g.disp();

   top_sort(g);

}
