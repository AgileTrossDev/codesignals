//
//  main.cpp
//  countDistantPairs
//
//  Created by Scott Jackson on 3/24/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
using std::string;


int countDistantPairs(string i, int d) {
    d++;
    int x=0, c=0;
    while (x+d<i.length()) if (i[x+d] == i[x++]) c++;
    return c;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
