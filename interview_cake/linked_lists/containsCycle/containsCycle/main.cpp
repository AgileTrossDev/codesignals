//
//  main.cpp
//  containsCycle
//
//  Created by Scott Jackson on 3/15/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

class LinkedListNode {
public:
    int intValue_;
    LinkedListNode* next_;
    
    LinkedListNode(int value) : intValue_(value), next_(nullptr) {};
};

bool containsCycle(const LinkedListNode* firstNode)
{
    // check if the linked list contains a cycle
    const LinkedListNode* hare = firstNode;
    const LinkedListNode* tortious = firstNode;
    if (hare) hare = hare->next_;
    
    while (hare) {
        if (hare ==tortious) return true;
        
        tortious = tortious->next_;
        hare = hare->next_;
        
        if (!hare) return false;
        
        if (hare ==tortious) return true;
        hare = hare->next_;
        
    }
    
    return false;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
