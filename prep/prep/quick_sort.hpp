//
//  quick_sort.hpp
//  prep
//
//  Created by Scott Jackson on 3/14/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#ifndef quick_sort_hpp
#define quick_sort_hpp

#include <stdio.h>
#include <vector>


void quick_sort(std::vector<int> &v);
void quick_sort(std::vector<int> &v, size_t flr, size_t cel);
size_t partition(std::vector<int> &v, size_t flr, size_t cel);


#endif /* quick_sort_hpp */
