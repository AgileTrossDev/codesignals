//
//  main.cpp
//  isSingleRiffle
//
//  Created by Scott Jackson on 3/13/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>


// Characteristic of a Single Riffle
//   - Shuffled deck(s) should be in order if we are
//     pulling cards from either half of riffle.  If
//     the next card is out of order, then the deck
//     was shuffled more than must a single rifle.


// Greedy Algorithm - Check if the next card is valid

using std::vector;

typedef vector<int> deck_t;

bool util (const deck_t& h1,const deck_t& h2, const deck_t& s, int i1, int i2, int i3){
    if (i3 >= s.size()) return true;
    
    if (i1<h1.size() && h1[i1] == s[i3])
        i1++;
    else if (i2<h2.size() && h2[i2] == s[i3])
        i2++;
    else
        return false;
    
    return util(h1,h2,s,i1,i2,i3+1);
    
}


bool isSingleRiffle(const deck_t& h1,
                    const deck_t& h2,
                    const deck_t& s)
{
    // check if the shuffled deck is a single riffle of the halves
    return util(h1,h2,s,0,0,0);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
