// Given a binary tree t and an integer s, determine whether there is a root to
// leaf path in t such that the sum of vertex values equals s.
// 
// Example
// 
//     For
// 
//     t = {
//         "value": 4,
//         "left": {
//             "value": 1,
//             "left": {
//                 "value": -2,
//                 "left": null,
//                 "right": {
//                     "value": 3,
//                     "left": null,
//                     "right": null
//                 }
//             },
//             "right": null
//         },
//         "right": {
//             "value": 3,
//             "left": {
//                 "value": 1,
//                 "left": null,
//                 "right": null
//             },
//             "right": {
//                 "value": 2,
//                 "left": {
//                     "value": -2,
//                     "left": null,
//                     "right": null
//                 },
//                 "right": {
//                     "value": -3,
//                     "left": null,
//                     "right": null
//                 }
//             }
//         }
//     }
// 
//     and
//     s = 7,
//     the output should be hasPathWithGivenSum(t, s) = true.
// 
//     This is what this tree looks like:
// 
//           4
//          / \
//         1   3
//        /   / \
//       -2  1   2
//         \    / \
//          3  -2 -3
// 
//     Path 4 -> 3 -> 2 -> -2 gives us 7, the required sum.
// 
//     For
// 
//     t = {
//         "value": 4,
//         "left": {
//             "value": 1,
//             "left": {
//                 "value": -2,
//                 "left": null,
//                 "right": {
//                     "value": 3,
//                     "left": null,
//                     "right": null
//                 }
//             },
//             "right": null
//         },
//         "right": {
//             "value": 3,
//             "left": {
//                 "value": 1,
//                 "left": null,
//                 "right": null
//             },
//             "right": {
//                 "value": 2,
//                 "left": {
//                     "value": -4,
//                     "left": null,
//                     "right": null
//                 },
//                 "right": {
//                     "value": -3,
//                     "left": null,
//                     "right": null
//                 }
//             }
//         }
//     }
// 
//     and
//     s = 7,
//     the output should be hasPathWithGivenSum(t, s) = false.
// 
//     This is what this tree looks like:
// 
//           4
//          / \
//         1   3
//        /   / \
//       -2  1   2
//         \    / \
//          3  -4 -3
// 
//     There is no path from root to leaf with the given sum 7.
// 
// Input/Output
// 
//     [time limit] 500ms (cpp)
// 
//     [input] tree.integer t
// 
//     A binary tree of integers.
// 
//     Guaranteed constraints:
//     0 ≤ tree size ≤ 5 · 104,
//     -1000 ≤ node value ≤ 1000.
// 
//     [input] integer s
// 
//     An integer.
// 
//     Guaranteed constraints:
//     -4000 ≤ s ≤ 4000.
// 
//     [output] boolean
// 
//     Return true if there is a path from root to leaf in t such that the sum of
// node values in it is equal to s, otherwise return false.
//     
    


#include <iostream>
#include <queue>
#include <math.h>



// Definition for binary tree:
 template<typename T>
 struct Tree {
   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
   T value;
   Tree *left;
   Tree *right;
 };


using std::cout;
using std::endl;



//------------------------------------------------------------------------------
// Solution
//------------------------------------------------------------------------------
bool recurse (Tree<int> * t, int s, int path_val =0, int d=0 ) {
  
  if (0==t || nullptr == t) {
    return (false);
  } 
  
  path_val = path_val+t->value;
  bool ret_flag = false;
  
  if (s==path_val && 0 == t->left && 0==t->right ) {
    ret_flag = true;
  } else  {
    ret_flag=(recurse (t->left,s,path_val,1 ) || recurse (t->right,s,path_val,2 )); 
  } 
  return ret_flag;
  
}

bool hasPathWithGivenSum(Tree<int> * t, int s) {
  // DFS this 
  return (t== 0 && s ==0) ? true : recurse(t,s);
}


//------------------------------------------------------------------------------
// Helpers
//------------------------------------------------------------------------------
Tree<int> * init(int a[], int size) {
  // Assume array is tree hierachictal order, meaning level 1 vals,lvl 2, lvl3, etc
  
  // Seed the first Node in the tree, which should be the root.
  Tree <int> * start = new Tree <int>(a[0]);
  
  // Init the processing queue for nodes in the tree
  queue<Tree <int> *> queue;
  queue.push(start);

  // Loop through the rest of input and create tree nodes
  for (int i= 1;i<size;i=i+2) {
    
    cout <<"Adding val to tree: " << a[i] << " " << ((i+1)<size ? a[i+1] : 0)<< endl;
    
    if ((i)<size && a[i] != -9999) {
      cout << "adding left "; 
      queue.front()->left = new Tree <int>(a[i]);
      queue.push(queue.front()->left);
    } else {
      cout << "NULL LEFT" << endl;
     queue.front()->left = 0; 
    }
    if ((i+1)<size && a[i+1] != -9999)  {
      cout << "adding right";
      queue.front()->right = new Tree <int>(a[(i+1)]);
      queue.push(queue.front()->right);
    } else {
      cout << "NULL RIGHT" << endl;
     queue.front()->right = 0; 
    }
    cout << endl;
    
    
    queue.pop();
  }
  
  
  return start;
  
}

void disp(Tree <int> *start) {
  
  queue<Tree <int> *> queue;
  queue.push(start);
  int node_count = 0;
  int depth =0;
  
  cout << "Depth: " << depth << ": ";
  while (!queue.empty()) {
    if (queue.front() == 0) {
      // Null node, so no processing
      cout << "_ ";
      queue.pop();
    } else {
      cout << "" << queue.front()->value << " ";
      
      queue.push(queue.front()->left);
      queue.push(queue.front()->right);
      queue.pop();
    }
   //cout << "*" <<  (node_count+1)<< " " << pow(2,depth) << "*" <<endl;
    if (!queue.empty() &&(++node_count) && node_count == pow(2,depth)) {      
      depth++;
      cout << endl;
      cout << "Depth: " << depth << "(" << node_count << "): ";
      node_count =0;
    }

 
  }
  cout << endl;
  
}




//------------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------------
int main(void) {
  {
    
    //           4
    //          / \
    //         1   3
    //        /   / \
    //       -2  1   2
    //         \    / \
    //          3  -2 -3
    
    int a[] ={ 4, 1,3,-2,-9999,1,2,-9999,3,-9999,-9999,-2,-3};
    Tree<int> * input = init(a,13);
    disp(input);
    cout << hasPathWithGivenSum(input,7) << endl;
    cout << hasPathWithGivenSum(input,77) << endl;
  }
}