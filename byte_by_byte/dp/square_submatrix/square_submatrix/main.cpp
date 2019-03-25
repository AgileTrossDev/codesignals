//
//  main.cpp
//  square_submatrix
//
//  Created by Scott Jackson on 3/24/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::min;
using std::max;
using std::cout;
using std::endl;

typedef vector<int> row_t;
typedef vector<row_t> matrix_t;





int square_submatrix(matrix_t& m) {
    
    
    // track the largest known square that
    // is formed using the corresponding cell
    // as the bottom-left corner of the square.
    matrix_t tracker(m.size(),row_t(m[0]));
    
    // We can initialize the state of the tracker
    // because we know that the top and left most
    // columns cannot be anylarger squares then 1.
    for (int i = 0; i<tracker.size();i++) tracker[i][0] = m[i][0];
    for (int i = 0; i<tracker[0].size();i++) tracker[0][i] = m[0][i];
    
    
    // Optimal sub-problem is the largest square made with the surrounding squares (above,left,diagonal left&up)
    // Overlapping sub-problem - Calculate the square of the current element by looking at the minimum sizes
    //                           from the surrounding squares.
    
    
    int best = INT_MIN;
    

    // Iterate over of the rest of the matrix to calculate the best possible square made from
    // the new square.  This new square actually represents the bottom-right corner of a the square.
    for (int row= 1; row<m.size(); row++) {
        cout << row << ": ";
        for (int col= 1; col<m[row].size(); col++) {
            cout << col << " ";
            if (m[row][col] == 0 )  {
                tracker[row][col] = 0;
            } else {
                // Decide if we can build a larger square with this element.
                // In order to build a larger square we use the optimal-solution
                // from the over-lapping problems previous solved.
                //  - 1 row above
                //  - 1 col back
                //  - 1 row above and 1 col back.
                //
                //  we can the smallest square by 1, or start a new square of size 1.
                tracker[row][col] = min(min(tracker[row-1][col],tracker[row][col-1]),tracker[row-1][col-1])+1;
                best = max(best,tracker[row][col]);
                cout << "(" << tracker[row][col] << ") ";
            }
        }
        cout << endl;
        
    }
    
    
    return best;
}


void tc_1() {
    
    matrix_t matrix = {
        {0,1,1,1,0,1 },
        {1,1,1,1,0,1 },
        {1,1,1,1,1,1 },
        {1,1,1,1,0,0 },
        {1,1,1,1,1,1 },
        {0,1,1,1,1,1 }
    };
    
    int res = square_submatrix(matrix);
    cout << "TC 1:" << res << endl;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tc_1();
    
    
    return 0;
}
