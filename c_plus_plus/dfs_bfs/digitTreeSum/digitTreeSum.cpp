// We're going to store numbers in a tree. Each node in this tree will store a
// single digit (from 0 to 9), and each path from root to leaf encodes a
// non-negative integer.
// 
// Given a binary tree t, find the sum of all the numbers encoded in it.
// 
// Example
// 
//     For
// 
// t = {
//     "value": 1,
//     "left": {
//         "value": 0,
//         "left": {
//             "value": 3,
//             "left": null,
//             "right": null
//         },
//         "right": {
//             "value": 1,
//             "left": null,
//             "right": null
//         }
//     },
//     "right": {
//         "value": 4,
//         "left": null,
//         "right": null
//     }
// }
// 
// the output should be
// digitTreeSum(t) = 218.
// There are 3 numbers encoded in this tree:
// 
//     Path 1->0->3 encodes 103
//     Path 1->0->1 encodes 101
//     Path 1->4 encodes 14
//     and their sum is 103 + 101 + 14 = 218.
// 
// t = {
//     "value": 0,
//     "left": {
//         "value": 9,
//         "left": null,
//         "right": null
//     },
//     "right": {
//         "value": 9,
//         "left": {
//             "value": 1,
//             "left": null,
//             "right": null
//         },
//         "right": {
//             "value": 3,
//             "left": null,
//             "right": null
//         }
//     }
// }
// 
// the output should be
// digitTreeSum(t) = 193.
// Because 09 + 091 + 093 = 193
// 
// Input/Output
// 
//     [time limit] 500ms (cpp)
// 
//     [input] tree.integer t
// 
//     A tree of integers. It's guaranteed that the sum of encoded integers won't exceed 252.
// 
//     Guaranteed constraints:
//     1 ≤ tree size ≤ 2000,
//     1 ≤ tree depth ≤ 9,
//     0 ≤ node value ≤ 9.
// 
//     [output] integer64
// 
//     The sum of the integers encoded in t, as described above.
// 
// [C++] Syntax Tips
// 
// //  Prints help message to the console
// //  Returns a string
// std::string helloWorld(std::string name) {
//     std::cout << "This prints to the console when you Run Tests" << std::endl;
//     return "Hello, " + name;
// }

//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };


long long dive(std::stack<int> tracker, Tree<int> * t) {
  // Set to the value of the chain or the sum of the left and ride dives
  long long ret_val =0;
   tracker.push(t->value);
  if (t->left ==0 && t->right ==0) {
   // Leaf Node, so calculate value of chain
   std::stack<int> work = tracker;
   int i =0;
   while(!work.empty()) {
    ////////cout << work.top() << " ";
    ret_val = ret_val + (work.top() * pow(10,i++));
    work.pop();
     
   }
    
  } else {
    // Dive Deeper to find the leafs
   
    return (t->left ==0 ? 0 : dive(tracker,t->left) )+ (t->right ==0 ? 0 :dive(tracker,t->right));
  }

  return ret_val;
}
  

long long digitTreeSum(Tree<int> * t) {
  std::stack<int> tracker;
  return dive(tracker,t);
}