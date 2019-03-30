//
//  main.cpp
//  box_stacking
//
//  Created by Scott Jackson on 3/29/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::max;



struct Box {
    Box(int h, int w, int d): height(h), width(w), depth(d){};
    int height;
    int width;
    int depth;
};


typedef vector<Box> boxes_t;

bool sort_by_width(Box &a, Box &b) {
    return a.width < b.width;
}

bool can_stack(Box &a, Box &b) {
    return a.width > b.width;
    
}

int  stack_boxes(boxes_t &boxes,int cur_bot, int next_bot, vector<int> &bottom_tracker) {
    if (next_bot>=boxes.size()) return 0;
    
    int height = 0;
    
    if (cur_bot == -1 || can_stack(boxes[next_bot], boxes[cur_bot])) {
        // Bottom is not set, or the new_bottom can be stacked under
        // current bottom.   
        
        if ( bottom_tracker[next_bot] == 0) {
            cout << "CALC: " << next_bot << endl;
            // need to calculate the stack height with this new bottom
            bottom_tracker[next_bot] = stack_boxes(boxes, next_bot, next_bot+1 , bottom_tracker);
            bottom_tracker[next_bot] += boxes[next_bot].height;
        }
        height = bottom_tracker[next_bot];
        cout << "Checking Bottom Box: " << next_bot << "=" << height <<endl;
    }
   
    // Find alternative height without using this box.
    int alt_height = stack_boxes(boxes, cur_bot, next_bot+1 , bottom_tracker);
   
    return  max(alt_height, height);
}

int stack_boxes(boxes_t &boxes) {
    sort(boxes.begin(),boxes.end(),sort_by_width);
    vector<int> bottom_tracker(boxes.size(),0);
    
    return  stack_boxes(boxes, -1, 0, bottom_tracker);
   
    
}


void disp(boxes_t & b){
    for (int i =0; i <b.size();i++)
        cout << b[i].height << " " << b[i].width << " " << b[i].depth << endl;
}


void tc_1() {
    boxes_t boxes = {Box(1,1,1), Box(2,2,2), Box(3,3,3), Box(4,4,4), Box(5,5,5)};
    disp(boxes);
    
    int res = stack_boxes(boxes);
    disp(boxes);
    
    cout << "TC_1: " << res << endl;
    
    
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    
    return 0;
}
