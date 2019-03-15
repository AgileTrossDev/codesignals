//
//  main.cpp
//  MaxStack
//
//  Created by Scott Jackson on 3/15/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::endl;


// Lessons Learned
//   - Store only what you need to store and avoid over manipulation.
//   - Start with brute force, identify weaknesses and then eliminate.
//   - Identify edge cases.  In this case duplicate numbers and empty stacks
//
//  Alternativer solution:  Records on the stack include item value and also the largest from that point below.
//  Reduces the need of a second stack, how guarentees that you storing two integers, which is twice the data.
//
class MaxStack
{
public:
    void push(int item)
    {
        if (max_collection.empty() || item >= max_collection.top()) max_collection.push(item);
        data.push(item);
        
    }
    
    int pop()
    {
        if (data.top() == max_collection.top()) max_collection.pop();
        int item = data.top();
        data.pop();
        return item;
    }
    
    int getMax() const
    {
        return max_collection.top();
    }
    
private:
    stack<int> data;
    stack<int> max_collection;
    
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
