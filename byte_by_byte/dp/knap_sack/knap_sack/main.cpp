//
//  main.cpp
//  knap_sack
//
//  Created by Scott Jackson on 3/24/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
//

// Lessons learned
//     - overlapping subproblems are sometimes hard to find, but if one exist, more will.
//


// Optimal Solution - Best case of using this item with the optimal solution for w-item.weight
//                    OR  not to use this item at all and try something else.
//
// Overlapping Problem - Same weight and same collection of items available.
//
//
// Think about this....
//    TOP-DOWN - knapsack(items,w,i) --> Max Value of items using i and all itmes after it.
//
//    BOTTOM-UP - Knapsack(items,w,i) --> max-value of items up-to, but not including item i.
//
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::map;

struct Item {
    Item(int v, int w): val(v), weight(w){};
    int val;
    int weight;
};

typedef vector<Item> items_t;
typedef map<int,int> rec_t;
typedef map<int,rec_t> cache_t;

// NOTE: The overlapping problems vary by both weight remaining and item choice
//       So the cache will be index by these variables.

int top_down(items_t &items, int w, int i, cache_t &cache ) {
    if (i>=items.size()) return 0;  //  No more items to try, we hit the bottom of the recursion
    
    // Check to see if weight/item have been cached
    cache_t::iterator c = cache.find(w);
    if (c != cache.end() && cache[w].find(i) != cache[w].end()) return cache[w][i];
    
    // Not in cache, so we need to calculate this combination of weight and item.
    
    // Prep cache if necessary.
    if (c == cache.end()) {
        rec_t rec;
        cache[w] = rec;
    }
    
    // Now perform calculation
    int best = 0;
    if ((w - items[i].weight) < 0) {
        // Can't pick this item at this point because it is too big,
        // so best case is to use the next item
        best = top_down(items,w,i+1,cache);
    } else {
        // We can use this item, but we need to decide if this really
        // does make it better, so take the best case scenario between
        // using this item or not
        best = max(
                   top_down(items,w,i+1,cache),
                   (top_down(items,w-items[i].weight,i,cache) + (items[i].val) ) ) ;
    }
   
    // We have found the best case, so cache it.
    cache[w][i] = best;
    
    // Return the best case
    return best;
    
}

int top_down(items_t &items, int w) {
    cache_t cache;
    
    int res = top_down(items,w, 0, cache);
    return res;
    
}


int bottom_up(items_t &items, int w) {
    
    int best = 0;
    
    // Cache item
    vector <vector<int>> cache(items.size()+1,vector<int>(w+1,-1));
   
    // For each item and weight, compute the max
    // value of the items up to that item that
    // doesn't go over W weight
    //
    // outter-loop(i) tells us what item to consider
    //
    // inner-loop - tells up what weight to consider
    //
    // For each cell, we need to decide whether we get
    // a greater value at that weight by including or
    // excluding item i - 1.
    for (int i = 1; i <= items.size(); i++) {
        for (int j = 0; j <= w; j++) {
            if (items[i-1].weight > j) {
                // Busted, so we use value for previous item, but same weight
                cache[i][j] = cache[i-1][j];
            } else {
                // Need to decide if adding this item is better than the optimal
                // answer with the previous item
                cache[i][j] = max(cache[i-1][j], cache[i-1][j-items[i-1].weight] +
                                       items[i-1].val);
            }
        } }
    return cache[items.size()][w];
    
    
    
    // Build-up all weights
   
    return best;
}

items_t build_items(){
    items_t items;
    
    Item a(1,10);
    Item b(10,1);
    Item c(25,4);
    Item d(3,30);
    Item e(100,1);
    
    Item f(15,10);
    Item g(25,10);
    Item h(15,10);
    
    items.push_back(a);
    items.push_back(b);
    items.push_back(c);
    items.push_back(d);
    items.push_back(e);
    items.push_back(f);
    items.push_back(g);
    items.push_back(h);
    
    
    
    
    
    return items;
    
}

void tc_1(){
    items_t items = build_items();
    
    int res = top_down(items,100);
    
    cout << "TC 1: " << res << endl;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
