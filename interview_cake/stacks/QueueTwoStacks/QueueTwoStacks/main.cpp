//
//  main.cpp
//  QueueTwoStacks
//
//  Created by Scott Jackson on 3/16/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <stack>

using std::stack;

class QueueTwoStacks
{
private:
    stack<int> inStack_;
    stack<int> outStack_;
    
public:
    void enqueue(int item)
    {
        inStack_.push(item);
    }
    
    int dequeue()
    {
        if (outStack_.empty()) {
            while (!inStack_.empty()) {
                outStack_.push(inStack_.top());
                inStack_.pop();
            }
        }
        
        int val = outStack_.top();
        outStack_.pop();
        return val;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
