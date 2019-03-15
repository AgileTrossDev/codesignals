//
//  quick_sort.cpp
//  prep
//
//  Created by Scott Jackson on 3/14/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include "quick_sort.hpp"

using std::vector;
using std::swap;



void quick_sort(vector<int> &v) {
    quick_sort(v,0,v.size()-1);
}
void quick_sort(vector<int> &v, size_t flr, size_t cel) {
    if (flr<cel) {
        size_t part= partition(v,flr, cel);
        quick_sort(v,flr,part-1);
        quick_sort(v,part+1,cel);
    }
}



size_t partition(vector<int> &v, size_t flr, size_t cel) {
    
    int part = v[flr];
    size_t i = flr;
    size_t j = cel;
    
    
    while (i<j) {
        while (v[i] < part) i++;
        while (v[j] > part) j--;
        if (i>=j) break;
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
        
        
    }
    
    return j;
     
}
