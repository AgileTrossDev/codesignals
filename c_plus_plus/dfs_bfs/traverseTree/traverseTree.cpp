// Note: Try to solve this task without using recursion, since this is what
// you'll be asked to do during an interview.
// 
// Given a binary tree of integers t, return its node values in the following format:
// 
//     The first element should be the value of the tree root;
//     The next elements should be the values of the nodes at height 1 (i.e. the root
//     children), ordered from the leftmost to the rightmost one;
//
//     The elements after that should be the values of the nodes at height 2 (i.e. the
//     children of the nodes at height 1) ordered in the same way;
//     Etc.
// 
// Example
// 
// For
// 
// t = {
//     "value": 1,
//     "left": {
//         "value": 2,
//         "left": null,
//         "right": {
//             "value": 3,
//             "left": null,
//             "right": null
//         }
//     },
//     "right": {
//         "value": 4,
//         "left": {
//             "value": 5,
//             "left": null,
//             "right": null
//         },
//         "right": null
//     }
// }
// 
// the output should be
// traverseTree(t) = [1, 2, 4, 3, 5].
// 
// This t looks like this:
// 
//      1
//    /   \
//   2     4
//    \   /
//     3 5
// 
// Input/Output
// 
//     [time limit] 500ms (cpp)
// 
//     [input] tree.integer t
// 
//     Guaranteed constraints:
//     0 ≤ tree size ≤ 104.
// 
//     [output] array.integer
// 
//     An array that contains the values at t's nodes, ordered as described above.
// 



#include<iostream>
#include<queue>
#include <cstddef>


using std::queue;

#define nullptr 0



//----------------------------------------------------------------------------
// Definition for binary tree:
//----------------------------------------------------------------------------
 template<typename T>
 struct Tree {
   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
   T value;
   Tree *left;
   Tree *right;
 };


//----------------------------------------------------------------------------
// Helper
//----------------------------------------------------------------------------
 
//----------------------------------------------------------------------------
// Solution
//----------------------------------------------------------------------------
std::vector<int> traverseTree(Tree<int> * t) {
    
    std::vector<int> ret_val;
    std::queue<Tree<int>*> bfs_queue;
    
    
    bfs_queue.push(t);
    Tree<int> *  index = nullptr;
    
    while(!bfs_queue.empty()) {
        index = bfs_queue.front();
        bfs_queue.pop();
        
        if (index==nullptr) continue;
        
        ret_val.push_back(index->value);
        
        bfs_queue.push(index->left);
        bfs_queue.push(index->right);
        
    }
    
    return ret_val;
    

}

//----------------------------------------------------------------------------
// Test
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// Main
//----------------------------------------------------------------------------
int main(void) {
    
    
}