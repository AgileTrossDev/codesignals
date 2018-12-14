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

Tree<int> * create_sub_tree(std::vector<int> &inorder, std::vector<int> &preorder, int pre_start, int in_start, int width) {
    
    // Reached a NULL Child 
    if (width<=0) return 0;
    
    // We know the tree root is at the start
    // of the pre-order sequence, so create
    // the root of this sub-tree
    Tree<int> * index = new Tree(preorder[pre_start]);
   // cout << "P: " << index->value << " PS: " << pre_start << " IS: " << in_start << " W: " << width << endl;
    
    // Find the inorder location of the sub-tree parent
    // so that we can sub-divide the offspring.
    int p_ind = in_start;
    while (p_ind<(in_start+width) && preorder[pre_start] != inorder[p_ind] ) p_ind++;
    
    // We now know that between in_start and p_ind-1
    // are part of the left sub-tree and 
    // p_ind+1 and in_start+width are part of the
    // right tree sub-tree.  Essentially how many
    // nodes on the left and how many are on the right
    int left_width = p_ind-in_start;
    int right_width = in_start+width-p_ind-1;
    
    // Left Child sub-tree preorder starts 1 place over from parent and is as long as the delta calculation
    // The inorder starts at the same location and is the length of the delta. 
    index->left = create_sub_tree(inorder,preorder,pre_start+1, in_start,left_width);
    
    // Right Child sub-tree preord starts 1 place over from parent and is as long as the delta calculation
    // The inorder starts at the same location  
    index->right = create_sub_tree(inorder,preorder,pre_start+left_width+1, p_ind+1,right_width);
    
    
    return index;
    
    
    
}



Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
    
   
    
    
    
    return create_sub_tree(inorder,preorder,0,0,inorder.size());

}

