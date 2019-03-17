//
//  main.cpp
//  changePossibilities
//
//  Created by Scott Jackson on 3/16/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

typedef vector<int> rec_t;
typedef vector<rec_t> col_t;
typedef vector<col_t> memo_t;

void disp(memo_t &m);


void calc(int amount, memo_t &memo,const vector<int>& denominations, int denom_start = 0) {
    
    // Check to see if we calculated this amount yet
    if (!memo[amount].empty()) return;
    
    // Need calc this amount, so loop through each denomination
    for (int i = 0; i<denominations.size();i++) {
       
        // Calc amount needed to form the amount w/ this denomination
        int amount_needed = amount-denominations[i];
        if (amount_needed<0) continue;
        //cout << "NEED TO FIND: " << amount_needed << " + " << denominations[i] << " = " << amount<< " " <<  denom_start<< endl;
        
        // Make sure this amount is calculated
        if (memo[amount_needed].empty()) calc(amount_needed, memo, denominations,i);
        
        // Impossible if the amount_needed can't be formed.
        if (0 == memo[amount_needed].size()) continue;
        
        // Now form all new records that use this denomination
        // By looping through each record of amount_needed,
        // and create a new record with this denomination
        for (int j=0; j< memo[amount_needed].size(); j++) {
            //if (amount_needed > denominations[i]) continue;
            rec_t rec = {denominations[i]};
            bool good = true;
            for (int k = 0; k < memo[amount_needed][j].size(); k++){
                if (denominations[i] >memo[amount_needed][j][k]){
                    good =false;
                    break;
                }
                rec.push_back( memo[amount_needed][j][k]);
            }
            // Add Reord
            if (good) memo[amount].push_back(rec);
        }
       // cout << "AMOUNT: " << amount << " complete: " << memo[amount].size() <<  endl;
        
        
    }
    
}

size_t changePossibilities(int amount, const vector<int>& denominations)
{
    // calculate the number of ways to make change
    memo_t memo((amount+1));
    memo[0] = {{}};
    calc(amount,memo,denominations);
    
    disp(memo);
    
    return memo[amount].size();
}


void disp(memo_t &m) {
    for (int i=0; i<m.size();i++) {
        cout << i << " ";
        for (int j=0; j<m[i].size();j++){
            cout << "{";
            for (int k= 0; k <m[i][j].size(); k++)
                cout << m[i][j][k] << " ";
            cout << "} ";
        }
        cout << endl;
    }
}

void tc_1() {
    size_t res = changePossibilities(4, {1, 2, 3});
    cout << "RESULT 1: " << res << endl;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
