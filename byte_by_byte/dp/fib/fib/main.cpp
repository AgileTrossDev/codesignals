//
//  main.cpp
//  fib
//
//  Created by Scott Jackson on 3/24/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void top_down(int n, vector<int> &tracker) {
    if (tracker[n] == -1) {
        top_down(n-1,tracker);
        top_down(n-2,tracker);
        tracker[n] = tracker[n-1] +tracker[n-2];
    }
    
}


int top_down(int n ) {
    
    vector<int> tracker(n+1,-1);
    tracker[0] = 0;
    tracker[1] = 1;
    top_down(n,tracker);
    return tracker[n];
}


int bottom_up(int n) {
    if (n<2) return (n == 0 ? 0 : 1);
    
    
    int n2 = 0;
    int n1 = 1;
    int res=-1;
    
    for (int i = 2;i<=n;i++) {
        res = n2+n1;
        n2 = n1;
        n1 = res;
    }
    
    
    
    return res;
}

void tc_1() {
    
    int b = bottom_up(6);
    int t = top_down(6);
    
    cout << "Bottom Up: " << b << " Top Down: " << t << endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tc_1();
    
    return 0;
}
