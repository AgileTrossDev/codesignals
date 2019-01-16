//
//  main.cpp
//  max_region
//
//  Created by Scott Jackson on 1/8/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> grid_t;

int count_zone(int row, int col, grid_t &grid) {
    // Guard
    if (grid[row][col] != 1) return 0;
    
    // mark as visited and count it.
    grid[row][col] = 3;
    int count = 1;
    
    for (int i = row-1; i <= row+1; i++) {
        if (i <0 || i >= grid.size()) continue;
        //cout << "?"  << i << " " << col-1 << " " << col+1<< endl;
        
        for (int j = col-1; j <= col+1; j++) {
            cout <<" FILLING ----->>> " << i << " " << j << endl;
            if (j <0 || j >= grid[i].size()) continue;
            count = count + count_zone(i, j, grid);
        }
        
    }
    
    //cout << "COUNT: " << endl;
    return count;
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
    int largest = 0;
    
    for (int i = 0; i< grid.size(); i++ ){
        for (int j = 0; j < grid[i].size(); j++) {
           // cout << "CHECKING: " << i << " " << j << endl;
            if (grid[i][j]== 1) {
                cout << "  Found --> : " << i << " " << j << endl;
                largest = max(largest,count_zone(i,j,grid));
            }
        }
    }
    
    return largest;
}


void test_case_0() {
    grid_t grid = { {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    
    int res =maxRegion( grid);
    cout << "TEST CASE 0: " << res <<endl;
    
}

void test_case_1() {
    grid_t grid = { {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    
    int res =maxRegion( grid);
    cout << "TEST CASE 1: " << res <<endl;
    
}

void test_case_2() {
    grid_t grid = { {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}};
    
    int res =maxRegion( grid);
    cout << "TEST CASE 2: " << res <<endl;
    
}


void test_case_3() {
    grid_t grid = { {1, 0, 0, 0, 0},
                    {0, 1, 1, 1, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {0, 0, 0, 0, 1}};
    
    int res =maxRegion( grid);
    cout << "TEST CASE 3: " << res <<endl;
    
}


void test_case_10() {
    grid_t grid = { {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0}};
    
    int res =maxRegion( grid);
    cout << "TEST CASE 10: " << res <<endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //test_case_0();
    //test_case_1();
    //test_case_2();
    test_case_3();
    
    
    test_case_10();
    //return 0;
}
