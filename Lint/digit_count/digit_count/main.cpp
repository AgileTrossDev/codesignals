//
//  main.cpp
//  digit_count
//
//  Created by Scott Jackson on 3/29/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description: Count the number of k's between 0 and n. k can be 0 - 9.
//
#include <iostream>
using std::cout;
using std::endl;


// for n <10 n%k ==0, then we have a match.  However, this is a given
//
// for n>=10, treat 0 as 10.   if  n%10 == k then result


int solve(int n, int k){
    
    if (n<10) return (k<n) ? 1: 0;
    if (k==0 ) k =10;
    
    int res =1;
    int index =10;
    while(index<= n) {
        cout << "CHECKING: " << index << " ";
        
        if () {
            
        } else if (index%10 == k) {
            res++;
            cout << "GOOD" << endl;
        } else {
            cout << "NOT GOOD" << endl;
        }
        index++;
    }
    
    
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << solve(12,1) << endl;
    
    
    return 0;
}
