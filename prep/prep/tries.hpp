//
//  tries.hpp
//  prep
//
//  Created by Scott Jackson on 3/18/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#ifndef tries_hpp
#define tries_hpp

#include <stdio.h>
#include <vector>

struct TriesNode {
    TriesNode(char v) : val(v),  next(256, nullptr),is_word(false) {};
    
    void add_word(std::string w, int i =0);
    void disp();
    
    char val;
    bool is_word;
    std::vector<TriesNode *> next;
    
};

TriesNode * build_tries(std::vector<std::string> input);

bool is_a_word(std::string w, TriesNode* root, int i=0);



#endif /* tries_hpp */
