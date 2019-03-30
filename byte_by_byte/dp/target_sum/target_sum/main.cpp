//
//  main.cpp
//  target_sum
//
//  Created by Scott Jackson on 3/30/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description: Given an array of integers, nums and a target value T,
// find the number of ways that you can add and subtract the values in
// nums to add up to T.

// Lessons Learned:
//  - Work it out by hand.  Then think of the solution and how it can be done recursively.
//    Start by stating the base case.  That should be make things clearer.
//
//  - Now look at the sub-problem and optimal sub-structure.  Notice what varies between
//    each recusion and what stays the same.
//
//  - Decide if there is a way to cache what you are caculating.  Assuming that
//    what varies will be

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::queue;
using std::map;


typedef vector<int> input_t;
typedef queue<int> tracker_t;
typedef map<int,int> entry_t;
typedef map<int,entry_t> cache_t;






int bottom_up(input_t & input, int target){
    
    // Initialize cache
    int sum = 0;
    for (int i =0; i<input.size();i++) sum +=input[i];
    if (sum ==0) return 0; // Early exit if input is sums to zero.
    vector<vector<int>> cache(input.size()+1, vector<int>(sum*2+1,0));
    cache[0][sum]=1;   // We know that with all values added we get once occurence, the prev sum.
    
    // now build up answer
    for (int i = 1; i <= input.size(); i++) {
        for (int j = 0; j < 2 * sum + 1; j++) {
            int prev = cache[i-1][j];
            if (prev != 0) {
                cache[i][j - input[i-1]] += prev;
                cache[i][j + input[i-1]] += prev;
            }
        } }
    return cache[input.size()][sum + target];
    
}


//---------------------------------------------------------------------------
// Refactored the slow_2 to use a cache to evolve from recursive to dynamic
// We are using a cache that tracks what num we are calculating and the sum
// at the moment.   In the call tree this is where the redundancy occurs because
// the same problem was being solved more than once.
//
//  Sum , i, and the cahce update in each recursion, where input and target
//  stay the same./
//
// Sub problem - the number of possible combinations of adding and subtracting
// the numbers at or after index i, where the sum of those numbers plus the
// sum equals T. It can also be stated as follows: The number of combinations
// where the sum equals T - sum.
int top_down(input_t & input, int target, int sum, int i, cache_t & cache )  {
  
    if (i>=input.size()) return (sum == target) ? 1 : 0;
    
    if ( cache.find(i) != cache.end() && cache[i].find(sum) != cache[i].end()) return cache[i][sum];

    cache[i][sum] =  top_down(input, target,sum+input[i],i+1,cache) + top_down(input, target,sum-input[i],i+1,cache);
    
    return cache[i][sum];
}



int top_down(input_t & input, int target){
    cache_t cache;
    return top_down(input,target,0,0,cache);
}


// BRUTE FORCE - Recursive.  Base case is that all nums have been used.
// We either reached the target or not.   At each recursion try adding
// and subtracting value to find the results.
int slow_solve_2(input_t & input, int target, int sum, int i) {
    if (i>=input.size()) return (sum == target) ? 1 : 0;
    
    return slow_solve_2(input, target,sum+input[i],i+1) + slow_solve_2(input, target,sum-input[i],i+1);
    
}
int slow_solve_2(input_t & input, int target) {
    return slow_solve_2(input, target,0,0);
}

// BRUTE FORCE
int slow_solve(input_t & input, int target){
    
    tracker_t tracker;
    
    // Initial State
    tracker.push(input[0]);
    tracker.push(0-input[0]);
    
    for(int i = 1; i < input.size(); i++) {  // O(N)
        size_t tracks = tracker.size();
        
        for (size_t j =0;j<tracks;j++){   // O(N^2)
            int new_sum = tracker.front() + input[i];
            tracker.push(new_sum);
            new_sum = tracker.front() - input[i];
            tracker.push(new_sum);
            tracker.pop();
        }
    }
    int total = 0;
    while (!tracker.empty()){  // O(N^N)
        if (tracker.front() == target) total++;
        tracker.pop();
    }
    return total;
}

void tc_1(){
    input_t input = {1,1,1,1,1};
    
    int res = slow_solve(input,5);
    
    cout << "TC 1 SLOW 1: " << res << endl;
    
    res = slow_solve_2(input,3);
    cout << "TC 1 SLOW 2: " << res << endl;
    
    res = top_down(input,2);
    cout << "TC 1 TOP DOWN: " << res << endl;
    
    res = bottom_up(input,2);
    cout << "TC 1 BOTTOM UP: " << res << endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
