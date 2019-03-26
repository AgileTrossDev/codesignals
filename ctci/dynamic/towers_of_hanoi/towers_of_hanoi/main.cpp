//
//  main.cpp
//  towers_of_hanoi
//
//  Created by Scott Jackson on 3/25/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description:  Towers of Hanoi Problem
//
// Lessons Learned
//   - Hand-work through problem.   Start with simplest cases.
//   - Identify the optimal previous state, in this case n-1 discs in tmp stack.  If we
//     can move n-1 to the tmp stack, then we can place the nth disk in the right location
//     and then move n-1 to the right location.
//   - Now establish the base cases.  N=0, n=1, n=2
//   - Now implement hand written algorithm.
//   - Nifty trick... refactored out logic to identify the tmp stack.  Used a XOR to find unused stack

#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::endl;

typedef stack<int> tower_t;


void init_problem(int n, tower_t towers[]) {
    // Initialize first tower
    for (int i=n;i>0;i--) towers[0].push(i);
}


void move(tower_t towers[], int s, int t){
    towers[t].push(towers[s].top());
    towers[s].pop();
}

int tmp(int s,int t) {
    return (s | t) ^ 3;
}

int solve(int n, tower_t towers[], int src, int dest) {
    int moves =0;
    if (n==0) {
        return moves;
    } else if (n==1) {
        move(towers,src,dest);
        moves++;
    } else if (n==2) {
        move(towers,src,tmp(src,dest));   // Move top to tmp
        move(towers,src,dest);            // Move next to dest
        move(towers,tmp(src,dest),dest);  // move tmp to dest
        moves = moves+3;
    } else {
        moves += solve(n-1,towers,src,tmp(src,dest));
        moves += solve(1,towers,src,dest);
        moves += solve(n-1,towers,tmp(src,dest),dest);
    }
    
    return moves;
}


void solve(int n) {
    tower_t towers[3];
    
    init_problem(n,towers);
    
    
    int moves = solve(n, towers,0,2);
    
    
    cout << "RESULT: " << moves << endl;
    while (!towers[2].empty()) {
        cout << towers[2].top()  << endl;
        towers[2].pop();
        
    }
        
    
    
    
}

void tc_1() {
    solve(0);
    solve(1);
    solve(2);
    solve(3);
    solve(4);
    
    solve(20);
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    

    
    tc_1();
    return 0;
}
