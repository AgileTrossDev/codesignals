//
//  main.cpp
//  matrix_product_path
//
//  Created by Scott Jackson on 2/19/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

struct Loc {
    Loc(int r, int c): row(r), col(c) {};
    int row;
    int col;
};

typedef vector<long> row_t;
typedef vector<row_t> matrix_t;
typedef queue<Loc> q_t;

// Calculate the paths leading to this location
void calc(matrix_t &input, matrix_t &tracker, Loc cur) {
    if (cur.col < 0 || cur.row < 0) return;
    cout << cur.row << " " << cur.col << " " << tracker[cur.row][cur.col] << endl;
    if (cur.row>0 && tracker[cur.row-1][cur.col] != 0) {
        tracker[cur.row-1][cur.col] = tracker[cur.row][cur.col] * input[cur.row-1][cur.col];
    }
    
    if (cur.col >0 && tracker[cur.row][cur.col-1] != 0) {
        tracker[cur.row][cur.col-1] = tracker[cur.row][cur.col] * input[cur.row][cur.col-1];
    }
    
    if (cur.col >0 && cur.row>0 && tracker[cur.row-1][cur.col-1] != 0) {
         tracker[cur.row-1][cur.col-1] = tracker[cur.row-1][cur.col] * tracker[cur.row][cur.col-1];
    }
    
    
}

void update_queue(Loc cur, q_t &work) {
    
    if (cur.col-1 >=0 ){
        Loc tmp(cur.col-1,cur.row);
        work.push(tmp);
    }
    
    if (cur.row-1 >=0 ){
        Loc tmp(cur.col,cur.row-1);
        work.push(tmp);
    }
    
    if (cur.row-1 >=0 && cur.col-1 >=0){
        Loc tmp(cur.col-1,cur.row-1);
        work.push(tmp);
    }
    
    
}

long exec(matrix_t &input) {
    matrix_t tracker(input.size(), row_t (input[0].size(),1));
    tracker[input.size()-1][input[0].size()-1] = input[input.size()-1][input[0].size()-1];
    
    // Quere for working from bottom-up, primed with ending location
    q_t work;
    Loc start((int)input.size()-1,(int)input[0].size()-1);
    work.push(start);
    
    
    // Work until we find the starting location
    while (!work.empty()) {
        Loc cur = work.front();
        work.pop();
        
        update_queue(cur, work);
        
        calc(input, tracker, cur);
        
        if (tracker[0][0] !=1) break;
    }
    
    
    return tracker[0][0];
}

void tc_1() {
    matrix_t input {{2,1,1 }, {2,1,1},{2,2,2}};
    
    long result = exec(input);
    cout << "RESULT" << result << endl;
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
