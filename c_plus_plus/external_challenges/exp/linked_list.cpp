#include <iostream>


using std::cout;
using std::endl;


template<typename T>
struct TreeNode {
  TreeNode( T v) : value(v), left(0),right(0) {}
   T value;
   TreeNode *left;
   TreeNode *right;
};


TreeNode<int>* add_node(int v, TreeNode<int> * ll) {
  TreeNode<int> * b = new TreeNode<int>(v);
  ll->right = b;

  return b;

}


void disp(TreeNode<int> * ll) {
   TreeNode<int> * index = ll;
   while (index!= 0){
     cout << index->value << endl;
     index = index->right;
   }



}


int main (void) {
  int a = 1;

  TreeNode<int> * b = new TreeNode<int>(5);

  cout << b->value << endl;

  disp(b);
  TreeNode<int> * tail = add_node(6, b);
  tail = add_node(7,tail);
  tail = add_node(8,tail);
  tail = add_node(9,tail);
  tail = add_node(10,tail);


   disp(b);


}
