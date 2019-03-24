//
//  main.cpp
//  8_12_eight_queens
//
//  Created by Scott Jackson on 3/23/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description:  8-Queens
//
// Lessons:
//    - Understand the principles of what is being asked to create logical rules
//
//    - Use logical rules to possibly simplify data structure - rows must be unique, so 1D vector of columns works.
//
//    - Break-up the problem....  Need to decide next move and then validate it.   Separate functions.
//
//    - Although 8 is defined in the problem, try to shrink problem and work out by hand.
//
//    - Identify ways to build_up the solution.  Work across the rows, finding which column to place it.
//


#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

typedef vector<int> solution_t;
typedef vector<solution_t> answer_t;


bool validate_place(solution_t &s, int row, int col){
    
    //cout << "VAL: " << row << " " << col << endl;
    
    // Move can't be placed into a used row
    if (s[row] != -1) return false;
    
    // Make sure the column is not used.
    for (int i = 0; i<s.size(); i++) {
        if (s[i] == -1) continue;
        
        // Verify column is empty
        if (s[i] == col) return false;
        
        // Verify we are not in the same diagnol
        int row_distance = abs(row-i);
        int col_distance = abs(col-s[i]);
        if (row_distance == col_distance) return false;
    }
    
    
    return true;
}


void util(answer_t &a, solution_t s, int row, int col) {
    
    if (validate_place(s,row,col)) {
        // This move is valid
        s[row] = col;
        
        if (row+1 <s.size()) {
            for(int i =0;i<s.size();i++){
                if (i==col) continue;
                util(a,s,row+1,i);
            }
        } else {
            a.push_back(s);
        }
    } else {
        //cout << "REJECTED" << endl;
    }
    
}

answer_t solve(int n) {
    answer_t answer;
    for (int i = 0;i<n;i++) {
        solution_t s(n,-1);
        util(answer,s,0,i);
    }
    
    return answer;
    
}


void disp(answer_t &a) {
    for (int i = 0; i<a.size();i++){
        cout << i << ": ";
        for (int j=0; j<a[i].size();j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void tc_1() {
    
    
    answer_t a = solve(8);
    
    disp(a);
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
