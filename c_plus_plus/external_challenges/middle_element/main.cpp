#include <iostream>

using std::cout;
using std::endl;


struct Node  {
  Node(int v) : val(v), next(0) {}
  Node *add_next(int c) {
    next= new Node(c);
    return next;
  }
  void disp(Node * node = 0){ 
   if (node == 0)
     cout << val << endl;
   if (next != 0)
     next->disp();

  }
  int val;
  Node * next;


};


int find_middle_value(Node * root) {
  Node * lead = root;
  Node * tail = root;

  while (lead->next != 0) {
    lead = lead->next;
    tail = tail->next;

    if (lead->next != 0){ 
      lead = lead->next;
    } else {
      //cout << " WEIRD" << endl;
      //tail = tail->next;
    }
    cout << "L: " << lead->val << " T: " << tail->val << endl; 
  }
  return tail->val;
}



Node * build_ll(int n) {
   Node * root = new Node(1);
   Node * index = root;
   for (int i=2;i<n+1;i++) 
     index = index->add_next(i);

   return root;
}


int main(void) {
    Node * root = build_ll(7);
    root->disp();
    cout << "RESULT: " << find_middle_value(root) << endl;



}
