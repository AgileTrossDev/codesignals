//
//  main.cpp
//  maximalSquare
//
//  Created by Scott Jackson on 3/24/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description:
// You have a 2D binary matrix that's filled with 0s and
// 1s. In the matrix, find the largest square that contains
// only 1s and return its area.

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::min;

typedef vector<vector<char>> matrix_t;
typedef vector<vector<int>> sums_t;

const char ONE = '1';
const char ZERO = '0';




int maximalSquare(matrix_t matrix) {
    
    // 1) Construct a sum matrix S[R][C] for the given M[R][C].
    //    a)    Copy first row and first columns as it is from M[][] to S[][]
    //    b)    For other entries, use following expressions to construct S[][]
    //      If M[i][j] is 1 then
    //        S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
    //      Else If M[i][j] is 0
    //       S[i][j] = 0
    //
    //  2) Find the maximum entry in S[R][C]
    //
    //  3) Using the value and coordinates of maximum entry in S[i], print
    //    sub-matrix of M[][]
    
    
    sums_t sums(matrix.size(),vector<int>(matrix[0].size(),0));
    for (int i = 0; i<matrix.size(); i++ ) {
        sums[0][i] = matrix[0][i];
        sums[i][0] = matrix[i][0];
    }
    
    
    int best_size =0;
    
    for (size_t row = 1; row<matrix.size();row++){
        for (size_t col = 1; col<matrix.size();col++)
            if (matrix[row][col] == ZERO){
                sums[row][col] =0;
            } else {
                sums[row][col] = min(min(sums[row][col-1],sums[row-1][col]),sums[row-1][col-1]) +1;
                best_size = max(best_size, sums[row][col]);
                
            }
            
            
        
    }
    
    
    return best_size;
    
}



void tc_1(){
    matrix_t input =   {{'1','0','1','1','1'},
                        {'1','0','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','0','0','1','0'},
                        {'1','0','0','1','0'}};
    
    int res = maximalSquare(input);
    
    cout << "TC 1: " << res << endl;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
