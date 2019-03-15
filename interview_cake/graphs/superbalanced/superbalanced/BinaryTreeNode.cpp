//
//  BinaryTreeNode.cpp
//  superbalanced
//
//  Created by Scott Jackson on 3/15/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include "BinaryTreeNode.hpp"

#include <stack>
#include <queue>
#include <iostream>
#include <math.h>

using std::stack;
using std::queue;
using std::max;
using std::min;
using std::cout;
using std::endl;
//using std::pow;


void BinaryTreeNode::disp() {
    
    cout << value_;
    
    BinaryTreeNode * index= nullptr;
    
    queue<BinaryTreeNode*> tracker;
    tracker.push(left_);
    tracker.push(right_);
    
    int cnt = 1;
    int h = 0;
    
    while (!tracker.empty()){
        if (cnt == pow(2,h+1)-1) {
            //cout << "| " << cnt << " " << h << " " << (pow(2,h-1)+1) <<  endl;
            cout << endl;
            h++;
        }
        index = tracker.front();
        tracker.pop();
        cnt++;
        if (index == nullptr)  {
            cout << "NULL ";
            continue;
        }
        
        cout << index->value_ << " ";
        
        tracker.push(index->left_);
        tracker.push(index->right_);
    }
    
    cout << endl;
    
    
}

DepthTracker depth_util (const BinaryTreeNode* index, DepthTracker depth) {
    
    if (!index) return depth; // No change of depth on dead node
    
    // Early exit check
    if ((depth.max_depth - depth.min_depth) > 1) return depth;
    
    // Node is valid, continue on to next leaf, so increase depth
    depth.cur_depth +=1;
    
    if (!index->left_ && !index->right_) {
        // Leaf Found, update the min/max depth tracker if necessary
        depth.max_depth = max(depth.cur_depth,depth.max_depth);
        depth.min_depth = min(depth.cur_depth, depth.min_depth);
        //cout << "uDEPTH: " << index->value_ << " " << depth.cur_depth << " " << depth.max_depth  << " "  <<  depth.min_depth << endl;
    } else {
        
        // Recursively check leaf deaths on each branch
        DepthTracker l = depth_util(index->left_,depth);
        DepthTracker r = depth_util(index->right_,depth);
        
        depth.max_depth =  max(l.max_depth, r.max_depth);
        depth.min_depth = min(l.min_depth, r.min_depth);
    }
    
    return depth;
    
}


bool isBalanced(const BinaryTreeNode* treeRoot) {
    // determine if the tree is superbalanced
    if (!treeRoot || (!treeRoot->left_ && !treeRoot->right_) ) return true;
    DepthTracker d;
    DepthTracker r = depth_util(treeRoot,d);
    cout << "DEPTH: " << r.max_depth  << " "  <<  r.min_depth << endl;
    return (!(r.max_depth - r.min_depth > 1));
}
