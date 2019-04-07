//
//  main.cpp
//  largest_square
//
//  Created by Scott Jackson on 4/3/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::max;

struct Rec {
    Rec(int r, int c) : row(r), col(c) {};
    int area() {return row * col;}
    int row, col;
    
    Rec& operator =(const Rec& a)
    {
        row = a.row;
        col = a.col;
        return *this;
    }
};


typedef vector<int> row_t;
typedef vector<row_t> matrix_t;

typedef vector<Rec> RecRow_t;
typedef vector<RecRow_t> RecTracker_t;

int solve(matrix_t &m) {
    
    int best = 0;
    
    // Matrix to dynamically build up answer
    matrix_t tracker (m.size()+1,row_t(m[0].size()+1,0));
    
    cout << m.size() << " " << m[0].size() << endl;
    cout << tracker.size() << " " << tracker[0].size() << endl;
    
    // Build up answer by traversing the input while
    // calculating the largest square formed by
    // adding the cell at each traversal.
    for (int row = 0; row<m.size(); row++) {
        for (int col = 0; col<m[row].size(); col++) {
            cout << row << " " << col << " | "  << row+1 << " " << col+1 << endl;
            if (m[row][col] == 1) {
               // cout << row << " " << col << endl;
                tracker[row+1][col+1] = min(tracker[row][col], min(tracker[row+1][col], tracker[row][col+1]));
                tracker[row+1][col+1]++;
            } else {
                tracker[row+1][col+1] = 0;
            }
            
            best = max (best,tracker[row+1][col+1] );
        }
        
        
    }
    return best;
    
    
}



void init_rec_tracker(RecTracker_t & tracker, size_t rows, size_t cols){
    for (size_t i = 0; i<rows;i++){
        Rec r (0,0);
        tracker[i].push_back(r);
    }
    
    for (size_t i = 1; i <cols; i++) {
        Rec r (0,0);
        tracker[0].push_back(r);
    }
}


void disp_rec_tracker(RecTracker_t & tracker) {
    
    
    for(int i=0;i<tracker.size();i++) {
        for(int j=0;j<tracker[i].size();j++) {
            cout << tracker[i][j].row << ":" << tracker[i][j].col  << "|";
        }
        cout << endl;
        
    }
    
    
}





Rec determine_rec(RecTracker_t & tracker ,matrix_t &m, size_t row, size_t col ) {
    if (m[row-1][col-1] == 0) {
        Rec t(0,0);
        return t;
    }
    
    
     Rec t (tracker[row-1][col].row+1,tracker[row][col-1].col+1);

    
  /*
    if (m[row-1][col-1] == 1 &&
        tracker[row-1][col-1].area() != 0 &&
        tracker[row][col-1].area() != 0 &&
        tracker[row-1][col].area() != 0) {
        
        // All surouding squares are part of rectangle.
        
        
        Rec r (tracker[row-1][col].row+1,tracker[row][col-1].col+1);
        
    }
    
    */
    return t;
}

int solve_rec(matrix_t &m) {
    
    int best =0;
    
     // Matrix to dynamically build up answer
    RecTracker_t tracker(m.size()+1);
    init_rec_tracker(tracker,m.size()+1,m[0].size()+1);
   
    cout << m.size() << " " << m[0].size() << endl;
    cout << tracker.size() << " " << tracker[0].size() << endl;
    
    // Build up answer by traversing the input while
    // calculating the largest square formed by
    // adding the cell at each traversal.
    for (size_t row = 1; row<tracker.size(); row++) {
        for (size_t col = 1; col<tracker[0].size(); col++) {
            
            tracker[row].push_back(determine_rec(tracker,m,row,col));
            
            
            
            best =  (best > tracker[row][col].area() ) ? best : tracker[row][col].area();
            cout << row << " " << col << " | "  << row+1 << " " << col+1 << " | " <<   tracker[row][col].row << " "<< tracker[row][col].col << endl;
        }
        
        
    }
    disp_rec_tracker(tracker);
    return best;
    
    
}




matrix_t build_matrix(int tc=0) {
    if (tc ==1 ){
        matrix_t m = {
            {1,1,1,0,0},
            {0,1,1,1,0},
            {0,1,1,1,1},
            {0,1,1,1,1},
            {1,1,1,1,1},
            {1,1,1,1,0}
           
        };
        return m;
        
    } else if   (tc ==2 ){
        matrix_t m = {
            {1,1,1,0,0},
            {0,1,1,1,0},
            {0,1,0,1,1},
            {0,1,1,1,1},
            {1,1,0,1,1},
            {1,1,1,1,0}
            
        };
        return m;
        
    } else if   (tc ==3 ){
        matrix_t m = {
            {1,1,1,0,0},
            {0,1,0,1,0},
            {0,1,0,0,1},
            {0,1,1,1,1},
            {0,1,0,1,0},
            {1,1,1,1,0}
            
        };
        return m;
        
    } else if   (tc ==4 ){
        matrix_t m = {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
            
            
        };
        return m;
        
    } else if   (tc ==5 ){
        matrix_t m = {
            {0,0,0},
             {0,0,0},
             {0,0,0}
            
            
        };
        return m;
        
    }
    
    matrix_t m = {
        {1,1,1,0,0},
        {0,1,1,1,0},
        {0,1,1,1,1},
        {0,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1}
    };
    
    
    return m;
}

void tc_1() {
    
    matrix_t m = build_matrix(3);
    
    int result = solve_rec(m);
    
    cout << "TC 1: " << result << endl;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
