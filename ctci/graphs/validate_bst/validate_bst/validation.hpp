//
//  validation.hpp
//  validate_bst
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#ifndef validation_hpp
#define validation_hpp

#include <stdio.h>
#include "node.hpp"

bool util(Node* root, int &last_val);
bool validate(Node * root);

#endif /* validation_hpp */
