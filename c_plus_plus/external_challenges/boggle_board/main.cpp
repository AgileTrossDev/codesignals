#include <iostream>
#include <vector>
#include <queue>


using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef vector<string> dict_t;
typedef vector<string> board_t;

struct TreeNode {
   TreeNode(char v) : val(v) {}

   TreeNode * is_child(char v) {
        for (size_t i = 0 ; i<children.size();i++) {
           if  (children[i]->val == v){
               return children[i];
           }
        }	
        return 0;
   }

 
   TreeNode * add_child(char v) {
      TreeNode * child = is_child(v); 

      if (child==0) {
         child = new TreeNode(v);
         children.push_back(child);
      }
      return child;
   }


   void disp(void) {
     cout << "NODE : " << val << ": ";
     for (size_t i = 0 ; i<children.size();i++) {
       cout << children[i]->val << " ";
     }
     cout << endl;

     for (size_t i = 0 ; i<children.size();i++) {
       children[i]->disp();
     }
     
   }


   char val;
   vector<TreeNode *> children;


};


TreeNode * build_tree(dict_t dict) {
  TreeNode * root = new TreeNode('!');
  for (size_t i = 0; i<dict.size(); i++) {
    TreeNode * index = root;
    for (size_t j = 0; j < dict[i].length(); j++){
       index =index->add_child(dict[i][j]);
    }
    index = index->add_child('*');
  }
  return root;
}




void traverse_board(TreeNode * tree, board_t board) {


}





bool test_case_1(void) { 
  dict_t dict {"SCOTT", "BOB","FRED", "SAM", "BO", "BEN", "Frank"}; 
  board_t board {"SABEN","SCOTT","FREDA","SAMTO","BOBOT"};
 
  TreeNode * tree = build_tree(dict);

  return true;

}


int main(void) {
   test_case_1();


  return 0;


}
