#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::sort;

struct Node {  
    Node(int v):val(v){};
    int val;


};

void disp(vector<Node*> v) {
  for(int i=0; i<v.size();i++){
     cout << v[i]->val << endl;
  }
}


bool comp(void * a, void *b) {
      Node * aa = (Node*) a;
      Node * bb = (Node*) b;

    return aa->val < bb->val;

}

int main(void) {
   Node * root = new Node(10);

   vector<Node*> v;
   v.push_back(root);
  

   v.push_back(new Node(5));
   v.push_back(new Node(11));
   v.push_back(new Node(1));
   v.push_back(new Node(9));
   v.push_back(new Node(2));
   v.push_back(new Node(8));
   v.push_back(new Node(3));
   v.push_back(new Node(4));
   v.push_back(new Node(7));
   v.push_back(new Node(5));
   v.push_back(new Node(6));

   disp(v);

   sort(v.begin(),v.end(),comp);
   disp(v);
}
