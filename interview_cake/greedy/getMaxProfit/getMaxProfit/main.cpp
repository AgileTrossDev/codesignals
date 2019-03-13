//
//  main.cpp
//  getMaxProfit
//
//  Created by Scott Jackson on 3/12/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

#include <vector>
using std::vector;


using namespace std;

int getMaxProfit(const vector<int>& stockPrices)
{
    // calculate the max profit
    int min_val = stockPrices[0];
    int best = INT_MIN;
    
    // Update the best value and the min number
    for (int i=1; i<stockPrices.size(); i++ ) {
        best = max(best, stockPrices[i]-min_val);
        min_val= min(min_val,stockPrices[i]);
    }
    return best;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
