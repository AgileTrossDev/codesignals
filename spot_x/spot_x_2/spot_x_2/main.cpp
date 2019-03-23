//
//  main.cpp
//  spot_x_2
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

#include <vector>
using std::vector;

int solution(int M, vector<int>& A) {
    size_t N = A.size();     // TODO: size_t?
    vector<int> count(M + 1, 0);
    int maxOccurence = 1;
    int index = 0;   // TODO: If index is never updated, then all elements occurs once
    
    // Loop over the input
    for (int i = 0; i < N; i++) {
        if (count[A[i]] > 0) {
            int tmp = count[A[i]] +1;    // TODO: Need to increment count here
            if (tmp > maxOccurence) {
                maxOccurence = tmp;
                index = i;
            }
            count[A[i]] = tmp;    // TODO: Incremented the value above
        } else {
            count[A[i]] = 1;
        }
    }
    return A[index];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
