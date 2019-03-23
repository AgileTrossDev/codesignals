//
//  main.cpp
//  spot_1
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::abs;
using std::stringstream;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int i=0;
    int cnt = 0;
    
    while (A[i] != -1) {
        i = A[i];
        cnt++;
    }
    
    return cnt+1 ;
}

int main(int argc, const char * argv[]) {
    
    typedef vector<int> t;
    t i = {1, 4, -1, 3, 2};
    cout << solution(i) << endl;
   
    t j = {-1};
    cout << solution(j) << endl;
    
    t j = {1};
    cout << solution(j) << endl;
    
    
    
    return 0;
}
