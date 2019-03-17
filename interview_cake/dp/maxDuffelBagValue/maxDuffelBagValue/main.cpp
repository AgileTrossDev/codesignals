//
//  main.cpp
//  maxDuffelBagValue
//
//  Created by Scott Jackson on 3/16/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::invalid_argument;
using std::max;
using std::cout;
using std::endl;

typedef unsigned long long val_t;

class CakeType
{
public:
    const unsigned int weight_;
    const unsigned int value_;
    
    CakeType(unsigned int weight = 0, unsigned int value = 0) : weight_(weight), value_(value){}
};

unsigned long long maxDuffelBagValue(const std::vector<CakeType>& cakeTypes,
                                     unsigned int weightCapacity)
{
    // Input check
    if (weightCapacity == 0) return 0;
    
    int cake_start = 0;
    while (cakeTypes[cake_start].weight_ <=0) cake_start++;
    if (cakeTypes.size() <= cake_start ) throw invalid_argument("POOP");
    
    // Memo completed calculations
    vector<val_t> memo(weightCapacity+1,0);
    
    // calculate the maximum value that we can carry by building up the best solution from the bottom
    for (int cur_cap = 1; cur_cap <=weightCapacity; cur_cap++ ) {
        
        val_t best_cur_value = 0;
       
        // Try adding a valid cake
        for (int i = 0; i<cakeTypes.size(); i++ ) {
            if (cakeTypes[i].weight_>cur_cap) continue;
            best_cur_value = max(best_cur_value,cakeTypes[i].value_ + memo[cur_cap-cakeTypes[i].weight_]);
        }

        memo[cur_cap] = best_cur_value;
        
        cout <<cur_cap <<": " << best_cur_value << endl;
        
    }
    
    return memo[weightCapacity];
}



void tc_2(){
    vector<CakeType> cakeTypes {  CakeType(51, 52), CakeType(50, 50) };
    unsigned int weightCapacity = 100U;
    
    val_t res = maxDuffelBagValue(cakeTypes, weightCapacity);
    cout << "RESULT: " << res << " | " <<  100ULL <<   endl;
    
}

void tc_1() {
    vector<CakeType> cakeTypes { CakeType(2, 1) };
    unsigned int weightCapacity =9U;
    
    val_t res = maxDuffelBagValue(cakeTypes, weightCapacity);
    cout << "RESULT: " << res << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_2();
    return 0;
}
