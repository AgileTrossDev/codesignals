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
//.Overlapping Problem - Same weight and same collection of items available.
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
        cout << "WTF?" << endl;
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
