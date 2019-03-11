//
//  main.cpp
//  stack_with_min
//
//  Created by Scott Jackson on 3/3/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::min;

class MinStack {
    protected:
        struct Record {
            Record():val(-1), sub_stack_min(INT_MAX) {};
            Record(int v, int m): val(v), sub_stack_min(m){};
            int val;
            int sub_stack_min;
        };
    
    public:
        MinStack(int s): the_size(s),collection(s),top_index(-1) {}
        void push(int v);
        void pop();
        int get_min();
        int top();
    
   
    
    private:
        vector<Record> collection;
        int the_size;
        int top_index;
};


void MinStack::push(int v) {
    Record rec(v,min(v,get_min()));
    collection[++top_index] = rec;
}


int MinStack::top() {
    return collection[top_index].val;
}

void MinStack::pop() {
    if (top_index > 0 ) top_index--;
}


int MinStack::get_min() {
    return collection[top_index].sub_stack_min;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    MinStack s(5);
    s.push(1);
    s.push(2);
    s.push(0);
    s.push(10);
    s.push(6);
    
    
    for (int i=0;i<5;i++) {
        cout << "TOP: " << s.top() << endl;
        cout << "MIN: " << s.get_min() << endl;
        cout << endl;
        s.pop();
    }
    
    return 0;
}
