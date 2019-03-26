//
//  main.cpp
//  reverse_stack
//
//  Created by Scott Jackson on 3/26/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Revierse a Stack without using any external data structures
//
//
// Lessons Learned
//   - ask if we are building a custom stack class or using std lib?
//   - if custom stack, we could use a Link List and then reversing would be reversing the next links.
//   - if not, then we can the execution stack as a way to hold state as we make transactions.


#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::endl;

typedef stack<int> s_t;

void display (s_t s) {
    cout << "----" << endl;
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}


void push_down(s_t &s, int v, size_t t, int d ) {
    int tmp  = s.top();
    s.pop();
    
    if (t==d || s.empty())
        s.push(v);
    else
        push_down(s,v,t,d+1);
    
    s.push(tmp);
    
    
    
    
}

void reverse(s_t &s){
    
    for (size_t n = s.size()-1; n>0;n--) {
        int tmp = s.top();
        s.pop();
        push_down(s,tmp,n,1);
    }
    
    
}






int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    s_t s;
    for(int i=5;i>0;i--) s.push(i);
    display(s);
    reverse(s);
    display(s);
    return 0;
}
