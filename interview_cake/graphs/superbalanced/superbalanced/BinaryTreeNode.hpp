//
//  BinaryTreeNode.hpp
//  superbalanced
//
//  Created by Scott Jackson on 3/15/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

#include <stdio.h>

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
    
    
    void disp(void);
};


struct DepthTracker {
    DepthTracker():max_depth(0),min_depth(10000),cur_depth(){};
    int max_depth;
    int min_depth;
    int cur_depth;
    
    
};


bool isBalanced(const BinaryTreeNode* treeRoot);



#endif /* BinaryTreeNode_hpp */
