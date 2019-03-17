//
//  main.cpp
//  findDuplicate
//
//  Created by Scott Jackson on 3/17/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>


using std::vector;

typedef unsigned int ui_t;

// Lessons Learned
//   - Vectors can be treated as LinkedLists if the values are within the range of N and N is
//     less than size of vector
//
//   - Duplicates in the vector turn out to be loops in the link list because they end up
//     pointing to the same location multiple times.
//
//   - In order to find duplicate value in a vector, find the start of the cycle. The node
//     before it will be a duplicate value.
//
//   - The start of the cycle will always have two nodes pointed to it.  In this case,
//     the duplicate values act as pointers to the start of the cycle.
//
//   - Find the start of the cycle by traversing the vector N-times.  The index
//     will definitely be inside the cycle somewhere.   Now iterate around the
//     cycle to obtain the length of the cycle.   Once we have a length, we can use
//     two runners that difference apart.   When they collide, it will be when the
//     second runner first enters the cyle.  Which is the start of the cycle. The leader
//     will be beginning it's second lap.
//
//   - As stated above, the duplicates will be the parent of either runner, which is either
//     node before the start of the cycle.  So track that position and you will find the
//     duplicate values.



unsigned int findDuplicate(const vector<unsigned int>& theVector)
{
    // find a number that appears more than once ... in O(n) time
    
    // Step 1:  Find node inside loop
    const ui_t n = static_cast<unsigned int>(theVector.size() - 1);
    
    ui_t pos_to_cycle = n+1;
    
    // Travese the vector as a LinkList by treating the vector value of the node
    // as the ->next in the LinkList.   If we traverse N times, we definitely will
    // be inside the cycle.
    for (int i = 0; i< n; i++) {
        pos_to_cycle = theVector[pos_to_cycle-1];
    }
    
    
    // Step 2:  Determine length of the loop by traversing the loop until we get
    //          back to the known location inside the cycle
    ui_t pos_cycle_counter = theVector[pos_to_cycle-1];
    ui_t counter = 1;
    while (pos_cycle_counter != pos_to_cycle) {
        pos_cycle_counter =  theVector[pos_cycle_counter-1];
        counter++;
        
    }
    
    // Step 3:  Find the start of the cycle based on the rule that the length of the cycle
    //          difference between two indexes will collide at the start of the loop.
    //          But the trick is that the start of the loop always has 2 'nexts' pointing
    //          to it.  The duplicate is the node before the start of the loop.  Either of
    //          of the two nodes.
    
    ui_t pos_hare = n+1;
    ui_t pos_tortouis  = n+1;
    ui_t pos_collision = pos_tortouis;
    
    
    // More lead runner ahead the distance of the cycle
    for(int i = 0; i<counter; i++)  {
        pos_hare =  theVector[pos_hare-1];
    }
    
    
    // Move Tortious and Hare in tandem until they collide
    while (pos_hare !=  pos_tortouis){
        pos_collision = pos_tortouis;
        pos_hare =  theVector[pos_hare-1];
        pos_tortouis =  theVector[pos_tortouis-1];
    }
    
    // AT this point we know the start of the loop.
    

    
    
    return theVector[pos_collision-1];
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
