//
//  main.cpp
//  reverse
//
//  Created by Scott Jackson on 3/16/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

// Lessons Learned
//   - Assumed throw exception on null list, but really to pass test need to return nullptr.  ASK FOR CLARIFICATION
//   - Always Draw out the data structure and talk through/list steps.
//   - CONSIDER BOTH ITERATIVE AND RECURSIVE SOLUTIONS
//   - Implement
//   - Work through code with original list and make sure it confirms.
//   - Finally compile and test edge cases



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

LinkedListNode* reverse_util(LinkedListNode* index,LinkedListNode* prev) {
    
    // Base case
    if (!index->next_) {
        // Tail is should be reverserd
        index->next_ = prev;
        return index;
    }
    
    LinkedListNode* head = reverse_util(index->next_, index);
    index->next_ = prev;
    return head;
    
}

LinkedListNode* reverse(LinkedListNode* headOfList)
{
    // reverse the linked list in place
    if (!headOfList) throw std::invalid_argument("No Dice man");
    if (!headOfList->next_) return headOfList;
    
    LinkedListNode* head = reverse_util(headOfList->next_, headOfList);
    headOfList->next_ = nullptr;
    return head;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
