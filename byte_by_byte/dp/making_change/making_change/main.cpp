//
//  main.cpp
//  making_change
//
//  Created by Scott Jackson on 3/24/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::min;

typedef vector<int> coins_t;
typedef vector<int> memo_t;

void top_down(int n, coins_t &coins, memo_t &memo) {

    // Check if already solved for N
    if (memo[n] != -1 ) return;

    // Need to find the best way to get to N.
    int best = INT_MAX;
    for (int c = 0; c< coins.size(); c++) {
        
        // Check if using this coin busts
        if (n-coins[c] <0 ) continue;
        
        // Check if we need to solve for the case if we use this coin
        if (memo[n-coins[c]] == -1 ) top_down(n-coins[c],coins, memo);
       
        // Update if this our best choice N
        best = min(best, (memo[n-coins[c]] + 1));
    }
    memo[n] = best;
}


int top_down(int n, coins_t &coins) {
    memo_t memo(n+1,-1);
    memo[0] = 0;
    top_down(n,coins,memo);
    return memo[n];
    
    
    
}

int bottom_up(int n, coins_t &coins) {
    vector<int> tracker(n+1,INT_MAX);
    tracker[0] =0;
    
    
    // Build up answers from 1 to N
    for (int i =1; i<=n;i++) {
        
        // Set the min-num of coins to use for i, but
        // using the coin that produces the least amount
        // of coins in the difference.
        for (int c = 0; c< coins.size(); c++) {
            if (i-coins[c] <0) continue;
            //cout << "COIN: " << coins[c] << " " << c << endl;
            tracker[i] = min( (tracker[i-coins[c]]+1), tracker[i]);
        }
        //cout << i << ": " << tracker[i] << endl;
    }
    
    
    return tracker[n];
}

void tc_1(){
    coins_t coins = {1,5,10,25};
    
    int res_td, res_bu;
    
    res_td = top_down(75, coins);
    res_bu = bottom_up(75, coins);
    cout << "TC 1: 75-> " << res_td << " : " << res_bu <<  endl;
    
    res_td = top_down(4, coins);
    res_bu = bottom_up(4, coins);
    cout << "TC 1: 4 TD->" << res_td << " | BU-> " << res_bu <<  endl;
    
    res_td = top_down(5, coins);
    res_bu = bottom_up(5, coins);
    cout << "TC 1: 5 TD->" << res_td << " | BU-> " << res_bu <<  endl;
    
    
    
    res_td = top_down(7, coins);
    res_bu = bottom_up(7, coins);
    cout << "TC 1: 7-> " << res_td << " : " << res_bu <<  endl;
    
    res_td = top_down(10, coins);
    res_bu = bottom_up(10, coins);
    cout << "TC 1: 10-> " << res_td << " : " << res_bu <<  endl;
    
    
    
}

void tc_2() {
    int tc =2;
    coins_t coins = {1,6,11,24};
    
    int res_td, res_bu;
    
    res_td = top_down(75, coins);
    res_bu = bottom_up(75, coins);
    cout << "TC "<<tc <<": 75-> " << res_td << " : " << res_bu <<  endl;
    
    res_td = top_down(4, coins);
    res_bu = bottom_up(4, coins);
    cout << "TC "<<tc <<": 4 TD->" << res_td << " | BU-> " << res_bu <<  endl;
    
    res_td = top_down(5, coins);
    res_bu = bottom_up(5, coins);
    cout << "TC " << tc << ": 5 "<<  res_td << " | BU-> " << res_bu <<  endl;
    
    
    
    res_td = top_down(7, coins);
    res_bu = bottom_up(7, coins);
    cout << "TC "<<tc << ": 7-> " << res_td << " : " << res_bu <<  endl;
    
    res_td = top_down(10, coins);
    res_bu = bottom_up(10, coins);
    cout << "TC "<<tc <<": 10-> " << res_td << " : " << res_bu <<  endl;
    
    
    
}

void tc_3(){
    coins_t coins = {1,5,10,25};
    
    int res_td, res_bu, n, tc=3;
    
    n = 2;
    res_td = top_down(n, coins);
    res_bu = bottom_up(n, coins);
    cout << "TC "<<tc <<": " << n << " -> TU: " << res_td << " | BD: " << res_bu <<  endl;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tc_1();
    tc_2();
    tc_3();
    return 0;
}
