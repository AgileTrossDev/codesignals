//
//  main.cpp
//  findLongestSubarrayBySum
//
//  Created by Scott Jackson on 2/8/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;


std::vector<int> findLongestSubarrayBySum(int s, std::vector<int> arr) {
    int l_run = 0;
    int r_run = 0;
    int run_sum= 0;
    int l_fnd = 0;
    int r_fnd = 0;
    std::vector<int> tmpa = {-1};
    
    
    //int flag= 0;
    
    while (r_run < arr.size()) {
        
        while (run_sum < s && (r_run) < arr.size() ) {
            //cout << "ADDING: " << arr[r_run] << " " << run_sum << endl;
            run_sum += arr[r_run++];
        }
        
        //cout << "1." <<  run_sum << " " << l_run << " " << r_run << endl;
        
        while (run_sum > s) run_sum -= arr[l_run++];
        
        //cout << "2. " <<  run_sum << " " << l_run << " " << r_run << endl;
        
        if (run_sum == s && (r_run - l_run) > (r_fnd - l_fnd)) {
            // cout <<" U2" << " "  << r_run << endl;
            while ( r_run < arr.size() && arr[r_run] == 0) r_run++;
            r_fnd = r_run;
            l_fnd = l_run;
            
        }
        
        if(run_sum == s )  run_sum -= arr[l_run++];
        
        
       // cout << "3. " <<  run_sum << " " << l_run << " " << r_run << " " << l_fnd << " " << r_fnd << endl;
       // if (flag>2) return tmpa;
        //flag++;
        
        
    }
    
    
    if (l_fnd == -1) {
        std::vector<int> tmpa = {-1};
        return tmpa;
    }
    
    if (arr.size() == 1) l_fnd= r_fnd;
    std::vector<int> tmp = {l_fnd, r_fnd};
    return tmp;
    
}



void tc_2(){
    int s=  3;
    std::vector<int> arr = {3};
    
    std::vector<int> res = findLongestSubarrayBySum(s,arr);
    
    cout << "TC 2: " << res[0] << " " << res[1] << endl;
    
    
}

void tc_1(){
    int s=  12;
    std::vector<int> arr = {1, 2, 3, 7, 5};
    
    std::vector<int> res = findLongestSubarrayBySum(s,arr);
    
    cout << "TC 1: " <<res[0] << " " << res[1] << endl;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    tc_2();
    return 0;
}
