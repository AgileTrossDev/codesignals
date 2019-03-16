//
//  main.cpp
//  isBinarySearchTree
//
//  Created by Scott Jackson on 3/15/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
using std::min;
using std::max;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;
    
    BinaryTreeNode(int value) :
    value_(value),
    left_(nullptr),
    right_(nullptr)
    {
    }
    
    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }
    
    BinaryTreeNode* insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }
    
    BinaryTreeNode* insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};




bool util (const BinaryTreeNode* root, int &min_val, int &max_val) {
    if (!root) return true;
    
    int l_min_val = INT_MAX, l_max_val= INT_MIN, r_min_val = INT_MAX, r_max_val = INT_MIN;
    bool l_result = util(root->left_, l_min_val, l_max_val);
    bool r_result = util(root->right_, r_min_val, r_max_val);
    
    cout << l_result << " " << l_min_val << " " << l_max_val << " | " <<  r_result << " " << r_min_val << " " << r_max_val  << endl;
    
    // Return result
    bool res = (l_result && r_result && r_min_val > root->value_ && l_max_val <= root->value_);
    
    min_val = min(root->value_,min(l_min_val,r_min_val));
    max_val = max(root->value_,max(l_max_val,r_max_val));
    
    return res;
}

bool isBinarySearchTree(const BinaryTreeNode* root)
{
    if (!root) return true;
    
    // early exit check
    if ( (root->left_ && root->left_->value_ > root->value_) ||  (root->right_ &&root->right_->value_ < root->value_))
        return false;
    
    // determine if the tree is a valid binary search tree
    // by finding min_val on right and max_value on left
    // and check the parent parent/child relationship is valid
    int l_min_val = INT_MAX, l_max_val= INT_MIN, r_min_val = INT_MAX, r_max_val = INT_MIN;
    bool l_result = util(root->left_, l_min_val, l_max_val);
    bool r_result = util(root->right_, r_min_val, r_max_val);
    
    
    cout << "FINAL: " << l_result << " " << l_min_val << " " << l_max_val << " | " <<  r_result << " " << r_min_val << " " << r_max_val  << endl;
    
    // Return result
    return (l_result && r_result && r_min_val > root->value_ && l_max_val <= root->value_);
    
}



void tc_2(){
    BinaryTreeNode *  root= new BinaryTreeNode(50);
    root->insertLeft(40)->insertLeft(30)->insertLeft(20)->insertLeft(10);
    
    bool res= isBinarySearchTree(root);
    cout << "TC 1 RESULT: " << res << endl;

}
void tc_1() {
    BinaryTreeNode *  root= new BinaryTreeNode(50);
    root->insertLeft(30)->insertLeft(10);
    root->insertRight(70)->insertRight(80);
    root->left_->insertRight(40);
    root->right_->insertLeft(60);
    
    bool res= isBinarySearchTree(root);
    
    
    cout << "TC 1 RESULT: " << res << endl;
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_2();
    return 0;
}
