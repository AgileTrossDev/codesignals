//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
// 
// 
// 
bool is_mirror(Tree<int> * lt,Tree<int> * rt) {
    
    // Traversal exits
    if (lt == 0 && rt ==0) return true;
    if ((lt != 0 && rt ==0) || (lt == 0 && rt !=0)) return false;
    if (lt->value != rt->value) return false;
    
    // Check Children
    bool outer = is_mirror(lt->left,rt->right);
    bool inner = is_mirror(lt->right,rt->left); 
    
    return (outer && inner);
}


bool isTreeSymmetric(Tree<int> * t) {
    if (t==0) return true;
    return is_mirror(t->left,t->right);
}

