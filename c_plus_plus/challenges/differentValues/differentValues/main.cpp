//
//  main.cpp
//  differentValues
//
//  Created by Scott Jackson on 3/25/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;
using std::cout;
using std::endl;

int differentValues(vector<int> a, int d) {
    set<int> tracker(a.begin(), a.end());
    
    for (int i=d; i>0;i--) {
        for (int j=0;j<a.size();j++) {
            cout << i << ":" << a[j] << "-> " << (a[j] + d) << " " << (a[j] + -1* d) << endl;
            if (tracker.find( a[j] + i) != tracker.end()) {
                return i;
            }
        
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> v = {10, -11, -9, -3, 5, -15};
    int res = differentValues(v,3);
    cout << "RESULT: " << res << endl;
    
    return 0;
}
