//
//  main.cpp
//  deleteNode
//
//  Created by Scott Jackson on 3/15/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

// Lessons learned
//   - Think about the data structure and what is the quickest manipulation that can be done.
//   - Traversing the linkList is slow and should be a redflag there is a better solution.  Also impossible in
//     this case.
//   - Ask ourselves what we know from the input.   Cur Val, Cur Next.   TWo things.
//   - LinkedLists are meant to be fluid in memory.  So deleting should be quick without array sizing.
//   - JUST COPY CONTENTS FROM NEXT NODE TO CURRENT NODE AND DELETE THE NEXT AND NOONE WOULD EVER KNOW.


#include <iostream>




class LinkedListNode {
public:
    int intValue_;
    LinkedListNode* next_;
    
    LinkedListNode(int value) :
    intValue_(value),
    next_(nullptr)
    {
    }
};

void deleteNode(LinkedListNode* nodeToDelete)
{
    // delete the input node from the linked list
    LinkedListNode* tmp = nodeToDelete->next_;
    nodeToDelete->intValue_ = nodeToDelete->next_->intValue_;
    nodeToDelete->next_ = nodeToDelete->next_->next_;
    delete tmp;
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
