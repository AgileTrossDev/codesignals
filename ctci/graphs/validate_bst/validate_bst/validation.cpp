//
//  validation.cpp
//  validate_bst
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include "validation.hpp"

using std::cout;
using std::endl;

bool util(Node* root, int &last_val) {
    
    if (root->left) {
        cout << "CHECKING " << root->val << " left" << endl;
        if (!util(root->left,last_val)) {
            cout << "ERR: 1" << endl;
            return false;
        }
        if (last_val > root->val) {
            cout << "ERR: 2: " << root->val << " " << last_val << endl;
            return false;
        }
    }
    
    last_val = root->val;
    cout << "LAST VAL SET: " << last_val << " " << root->val <<  endl;
    
    if (root->right) {
        cout << "CHECKING " << root->val << " right" << endl;
        if (!util(root->right,last_val)){
            cout << "ERR: 3" << endl;
            return false;
        }
        if (last_val < root->val) {
            cout << "ERR: 4 " << root->val << " " << last_val << endl;
            return false;
        }
    }
    
    return true;
}


bool validate(Node * root) {
    int last_val = INT_MIN;
    if (root->left) {
         cout << "CHECKING " << root->val << " left" << endl;
        if (!util(root->left,last_val)) return false;
        if (last_val >root->val) return false;
    }
    
    last_val = root->val;
    
    if (root->right) {
         cout << "CHECKING " << root->val << " right" << endl;
        if (!util(root->right,last_val)) return false;
        if (last_val <root->val) return false;
        
    }
    
    return true;
}
