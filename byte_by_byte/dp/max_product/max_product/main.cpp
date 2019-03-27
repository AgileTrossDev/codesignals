//
//  main.cpp
//  max_product
//
//  Created by Scott Jackson on 3/27/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description: Find the largest product by crossing from the upper left to the bottom right of a matrix


// Lessons Learned
//  - Tracking matrix used a header row and collumn to make traversal simpler
//  - Even though you know you have the answer.... slow down and walk through the logic.  It will be less stressful.


#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::min;

typedef vector<int> row_t;
typedef vector<row_t> matrix_t;


int solve(matrix_t & matrix) {
    
    matrix_t tracker (matrix.size()+1,row_t(matrix[0].size()+1,1));
    
    // Traverse the input,  updating the tracker with the optimal solution
    for (size_t row=1; row<tracker.size(); row++){
        for (size_t col =1; col < tracker[row].size();col++){
            
            tracker[row][col] = max(matrix[row-1][col-1] * tracker[row-1][col], matrix[row-1][col-1] * tracker[row][col-1]);
            
            cout << "UPDATE: " << row << ":" << col << " -> " << tracker[row][col] << endl;
        }
    }
 
    return tracker.back().back();
}



void tc_2() {
    
    matrix_t input =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    int result = solve(input);
    cout << "TC 1: " << result << endl;
    
}

void tc_1() {
    
    matrix_t input =
    {
        {1,1,1,1},
        {2,1,1,1},
        {2,1,1,1},
        {2,2,2,1}
    };
    
    int result = solve(input);
    cout << "TC 1: " << result << endl;
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
     tc_2();
    return 0;
}
