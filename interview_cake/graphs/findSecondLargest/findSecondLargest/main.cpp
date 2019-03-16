//
//  main.cpp
//  findSecondLargest
//
//  Created by Scott Jackson on 3/16/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

// Lessons Learned
//  - Even if think you got it, talk to through the problem before coding.
//  - Describe the characteristics of the data structure in use.
//  - Largest element in tree is the right most node.
//  - 2nd Largest element is either the parent of the largest OR the rightmost Node on left branch
//  - Draw the edge cases of the data structure to see clearly what should be done.

using std::invalid_argument;


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

int findSecondLargest(const BinaryTreeNode* rootNode)
{
    // find the second largest item in the binary search tree
    if(!rootNode || (!rootNode->left_ && !rootNode->right_) ) throw invalid_argument("POOP");
    
    const BinaryTreeNode* index = rootNode;
    const BinaryTreeNode* parent = rootNode;
    
    // Find largest Number
    while (index->right_) {
        parent = index;
        index = index->right_;
    }
    
    // If Largest has the left side, then second largest
    // is down that side.  Find the right most element
    // on the left side of th largest.  If not, just
    // use the parent node as the second largest.
    if (index->left_) {
        parent = index->left_;
        while (parent->right_)  parent = parent->right_;
    }
    
    return parent->value_;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
