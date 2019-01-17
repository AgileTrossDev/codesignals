/*
 tree is considered a binary search tree (BST) if for each of its nodes the following is true:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and the right subtrees must also be binary search trees.

Removing a value x from a BST t is done in the following way:

    If there is no x in t, nothing happens;
    Otherwise, let t' be a subtree of t such that t'.value = x.
    If t' has a left subtree, remove the rightmost node from it and put it at the root of t';
        Otherwise, remove the root of t' and its right subtree becomes the new t's root.
*/

//
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>

using std::cout;
using std::endl;

//const int nullptr =0;
 
// Definition for binary tree:
 template<typename T>
 struct Tree {
   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
   T value;
   Tree *left;
   Tree *right;
 };
 
void display_tree(Tree<int> *  root);
Tree<int> * test_remove(Tree<int> * root, int v);
int node_count(Tree<int> *  root);
Tree<int> * just_find_node(Tree<int> * root, int i);

Tree<int> * max(Tree<int> * x){
      while(x->right != nullptr) {
         x = x->right;
      }
      return x;
}


Tree<int> * delMax(Tree<int> * x) {
      if(x->right == nullptr) {
         return x->left;
      }
      x->right = delMax(x->right);
      return x;
}



Tree<int> * remove_from_bst (Tree<int> * t, int key) {
      if(t == nullptr) { return nullptr; }
      
      if(t->value == key) {
         if(t->left == nullptr) {
            return t->right;
         } else {
            Tree<int> * m = max(t->left);
            m->left = delMax(t->left);
            m->right = t->right;
            return m;
         }
      } else {
         if (t->value > key) 
           t->left = remove_from_bst(t->left, key);
         else 
           t->right = remove_from_bst(t->right, key);
      }

      return t;
}


// Iterate over queries to be deleted.
Tree<int> * deleteFromBST(Tree<int> * t, std::vector<int> queries) {
  for(int i=0; i < queries.size(); i++) {
    t = remove_from_bst(t, queries[i]);
  }
  
  return t; 
}

// ========
// TEST HELPERS
// ========

Tree<int> * build_test_tree_0(){
/*
    5
   / \
  2   6
 / \   \
1   3   8
       /
      7
*/
    Tree<int> * root = new Tree<int>(5);
    
    root->left =   new Tree<int>(2);
    root->right =   new Tree<int>(6);
    
    root->left->left =   new Tree<int>(1);
    root->left->right =   new Tree<int>(3);
    
    
    root->right->right =   new Tree<int>(8);
    
    root->right->right->left =   new Tree<int>(7);
    
    
    
    return root;

    
}
Tree<int> * build_test_tree_2(){
/***************
    3
     \ 
      4
****************/
    Tree<int> * root = new Tree<int>(3);    
    root->right = new Tree<int>(4);
    
    return root;    
}
Tree<int> * build_test_tree_3(){
/***************
    3
   /
  2 
****************/
    Tree<int> * root = new Tree<int>(3);    
    root->left = new Tree<int>(2);
    
    return root;    
}
Tree<int> * build_test_tree_4() {
    Tree<int> * root = new Tree<int>(3);    
    root->left = new Tree<int>(2);
    root->right = new Tree<int>(5);
    
    root->left->left = new Tree<int>(1);    
    
    return root;
}
Tree<int> * build_test_tree_5() {
    // Build test tree
    /***************
            3
           / \
          2   5
         /
        1
    ****************/
    Tree<int> * root = new Tree<int>(3);    
    root->left =   new Tree<int>(2);
    root->right =   new Tree<int>(5);
    root->left->left = new Tree<int>(1);
    
    return root;
}
Tree<int> * build_test_tree_6() {
    
    Tree<int> * root = new Tree<int>(5);    
    root->left = new Tree<int>(2);
    root->right = new Tree<int>(6);
    
    root->left->left = new Tree<int>(1);
    root->left->right = new Tree<int>(3);
    

    root->right->right = new Tree<int>(8);
    root->right->right->left = new Tree<int>(7);
    
    return root;
    
}
Tree<int> * build_test_tree_7() {
    Tree<int> * root = new Tree<int>(3);    
    root->left = new Tree<int>(2);
    root->right = new Tree<int>(5);
    
    return root;
}
Tree<int> * build_test_tree_8(){

  Tree<int> * root = new Tree<int>(5);
  
  root->left = new Tree<int>(2);
  root->left->left = new Tree<int>(1);
  root->left->right = new Tree<int>(3);
  
  root->right = new Tree<int>(6);
  root->right->right = new Tree<int>(8);
  root->right->right->left = new Tree<int>(7);
    
   return root; 
}
Tree<int> * build_test_tree_9(){

  Tree<int> * root = new Tree<int>(3);
  
  root->left = new Tree<int>(2);
  root->left->left = new Tree<int>(1);  
  
  root->right = new Tree<int>(5);
    
  return root; 
}





void test_case_1(){
  /*
     5
    / \
   2   6
  / \   \
 1   3   8
        /
       7
  */
  
  Tree<int> * root = new Tree<int>(5);    
  root->left = new Tree<int>(2);
  root->right = new Tree<int>(6);
  
  root->left->left = new Tree<int>(1);
  root->left->right = new Tree<int>(3);
  
  root->right->right = new Tree<int>(8);
  root->right->right->left = new Tree<int>(7);
  
  
  cout << "7: " << root->right->right->left->value << endl;
  
  std::vector<int>  queries = {4, 5, 6};
  display_tree(root);
  Tree<int> * result = deleteFromBST(root,queries);
  
  cout << "\nFinal: " << endl;
  display_tree(result);
  cout << "ROOT: " << result->value << endl;
 
}




// Returns Node with value i.  Updates sub_tree_root
// pointer to the parent of the found node. Parent
// is set to nullptr if the search node is the root
Tree<int> * just_find_node(Tree<int> * root, int i) {
   
   Tree<int> * index = root;
   
   while (index !=nullptr && index->value != i) {   
      if (index->value < i) 
        index = index->right;
      else 
        index = index->left;
      
   }
   
   return index;
}

void display_tree(Tree<int> *  root) {
    if (root ==nullptr)  return;    
    display_tree(root->left);
    cout << root->value << endl;
    display_tree(root->right);   
}

int node_count(Tree<int> *  root) {
    if (root ==nullptr)  return 0;    
    return (1 + node_count(root->left) + node_count(root->right));
}

int main(void) {

   //test_case_0();
   test_case_1();
    //test_case_2();
    //test_case_3();    
    // test_case_4();
    //test_case_5();    
    //test_case_6();
    //test_case_7();
    //test_case_8();
    //test_case_9();
    //test_case_10();
    //test_case_11();
    
    /*
    Tree<int> * root = build_test_tree_3();
    display_tree(root);
    
    
    Tree<int> * parent;
    Tree<int> * found;
    Tree<int> * largest;
    
    root = remove_node(root,1);
    cout << "FIRST: " <<root->value << endl;
    display_tree(root);
    
    root = remove_node(root,2);
    cout << "SECOND: " <<root->value << endl;
    display_tree(root);
    
    root = remove_node(root,3);
    cout << "THIRD: " << (root == nullptr) << endl;
    display_tree(root);
    
    root = remove_node(root,5);
    
    cout << "FINAL" << endl;
    display_tree(root);
    
    */
    
    
    
    /*
    Tree<int> * largest = pop_largest_in_tree(root);
    cout << "LARGEST: " << largest->value << endl;
    display_tree(root);
    
    Tree<int> * parent = root;
    Tree<int> * found = find_node(parent,3);
    cout << "FOUND: " << found->value << endl;
    display_tree(root);
    cout << "PARENT: " << parent->value << endl;
    display_tree(parent);
    
    
    root = remove_node(root,2);
    cout << "NEW ROOT: " << root->value << endl;
    display_tree(root);
    */
    
    /*
    cout << "----" << endl;
    parent = root;
    found = find_node(parent,5);
    cout << "FOUND: " << found->value << endl;
    display_tree(root);
    cout << "PARENT: " << parent->value << endl;
    display_tree(parent);
    largest = pop_largest_in_tree(found->left);
     cout << "LARGEST: " << largest->value << endl;
    display_tree(root);
    
     cout << "----" << endl;
    
   */
    
    /*
    root = remove_node(root,5);
    cout << "NEW ROOT: " << root->value << endl;
    display_tree(root);
    */
     /*
    root = remove_node(root,6);
    cout << "NEW ROOT: " << root->value << endl;
    display_tree(root);
    
    root = remove_node(root,1);
    cout << "NEW ROOT: " << root->value << endl;
    display_tree(root);
    
    root = remove_node(root,3);
    cout << "NEW ROOT: " << root->value << endl;
    display_tree(root);
    
    root = remove_node(root,2);
    cout << "NEW ROOT: " << root->value << endl;
    display_tree(root);
    */
}

