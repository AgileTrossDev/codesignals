//
//  main.cpp
//  nQueens
//
//  Created by Scott Jackson on 12/30/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> results_t;

void disp(results_t &r);

using std::cout;
using std::endl;


bool can_add(std::vector<int> & board,  int row,int col, int n) {
    
    // Columns are valid by default
   
    // Check rows
    for (int i = col+1; i<n; i++ ) {
        if (board[i] == row+1) { return false; }
    }
    
    // Check diagonal
    int row_up = row;
    int row_down = row;
    int col_index = col+1;
    while(col_index < n ) {
       
        row_up= row_up-1;
        row_down=row_down+1;
        
        if (board[col_index]-1 == row_up ||board[col_index]-1 == row_down) { return false; }
        col_index++;
        
    }
    
    return true;
}


std::vector<std::vector<int>> nQueens(int n, int col =0  ) {
    std::vector<std::vector<int>> res;
    if (col == n-1) {
        // BASE CASE:  any row can contain a queen
        std::vector<int> init_row(n,-1);
        
        for (int i=0; i<n; i++) {
            init_row[col] = i+1;
            res.push_back(init_row);
        }
        return res;
    } else {
    
        // Get valid states for next column
        std::vector<std::vector<int>> tmp = nQueens(n,col+1);
       
        // We have all valid states after the current column,
        // so we rebuild the results with all new valid states
        // For each valid state, try every row for this column,
        // if it works, add it to the new result set.
        for (int i = 0; i < tmp.size(); i++){
            for (int row = 0; row < n; row++) {
                if (can_add(tmp[i], row,col,n)) {
                    tmp[i][col] = row+1;
                    res.push_back(tmp[i]);
                }
            }
        }
    }
    
    return res;
}




void disp(results_t &r) {
    cout << "Canditates in Board: " << r.size() << endl;
    for (int row=0;row<r.size();row++){
        cout << "B: ";
        for (int col=0;col<r[row].size();col++)
            cout  << r[row][col] << " ";
        cout << endl;
    }
    cout << endl;
    
}

void test_case(int n) {
    results_t r = nQueens(n);
    cout << "TEST CASE "<< n << ": " << endl;
    disp(r);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test_case(1);
    test_case(2);
    test_case(3);
    test_case(4);
    test_case(6);
    return 0;
}

