//
//  tries.cpp
//  prep
//
//  Created by Scott Jackson on 3/18/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include "tries.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;



void TriesNode::add_word(std::string w, int i) {
    //cout << val << " " << w << "  " << w[i] << " " << i << " " << (next[w[i]] ==nullptr) << " " << next.size() << endl;
    if (next[w[i]] == nullptr) next[w[i]] = new TriesNode(w[i]);
                                                              
    
    if (i==w.length()-1)
        is_word= true;
    else
        next[w[i]]->add_word(w,i+1);
}

TriesNode * build_tries(vector<string> input) {
    TriesNode * root = new TriesNode('*');
    
    for (int i =0; i<input.size();i++) {
        root->add_word(input[i]);
    }
    
    return root;
}


void TriesNode::disp() {
    
    cout << val << ": ";
    
    for (int i =0; i <next.size(); i++)
        if (next[i] != nullptr) cout << next[i]->val << " ";
    cout << endl;
    for (int i =0; i <next.size(); i++)
        if (next[i] != nullptr)  next[i]->disp();
    
}


bool is_a_word(std::string w, TriesNode* root, int i) {
    
    if (i == w.length()-1)
        return root->is_word;
    else if (root->next[w[i]] != nullptr )
        return is_a_word(w,root->next[w[i]],i+1);
    
    return false;
    
}
