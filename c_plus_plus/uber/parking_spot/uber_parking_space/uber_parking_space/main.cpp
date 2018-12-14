//
//  main.cpp
//  uber_parking_space
//
//  Created by Scott Jackson on 12/14/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
using std::vector;
using std::endl;
using std::cout;

#define TY 0
#define TX 1
#define BY 2
#define BX 3




typedef std::vector<int> vint_t;
typedef std::vector<vint_t> lot_t ;


void set_start(vint_t &start_x, vint_t &start_y, vint_t &end_x, vint_t &end_y, vint_t &spot, lot_t &lot) {
    
    
    if (spot[BX]-spot[TX] > spot[BY] - spot[TY]) {
        // Horizontal path
        start_x.insert(start_x.end(), {0, spot[TX]});
        start_y.insert(start_y.end(), {spot[TY],spot[TY]});
        end_x.insert(end_x.end(), {spot[BX], (int)lot[0].size()-1});
        end_y.insert(end_y.end(), {spot[BY], spot[BY]});
        
    } else {
        // vertical path
        start_x.insert(start_x.end(), {spot[TX],spot[TX]});
        start_y.insert(start_y.end(),  {0, spot[TY]});
        end_x.insert(end_x.end(),  {spot[BX], spot[BX]});
        end_y.insert(end_y.end(),  {spot[BY], (int)lot.size()-1});
    }
}

bool traverse_lot(vint_t &start_x, vint_t &start_y, vint_t &end_x, vint_t &end_y, lot_t &lot){
    bool set_good = true;
    for (int i=0; i<2; i++) {
        cout << "I: " << i << endl;
        set_good = true;
        for (int y = start_y[i]; y <= end_y[i]; y++) {
            cout << " Y: " << y << endl;
            for (int x = start_x[i]; x <= end_x[i]; x++) {
                cout << "  X: " << x << endl;
                if (lot[y][x]== 1) {
                    set_good= false;
                    break;
                }
            }
            if (!set_good) break;;
        }
        if (set_good) return set_good;
    }
    return set_good;
}


bool parkingSpot(std::vector<int> carDimensions, std::vector<std::vector<int>> parkingLot, std::vector<int> luckySpot) {
    vint_t start_x, start_y, end_y, end_x;
    set_start(start_x, start_y, end_x,end_y, luckySpot, parkingLot);
    return traverse_lot(start_x, start_y, end_x,end_y, parkingLot);
    
}



bool test_case_1() {
    vint_t car = {3, 2};
    
    lot_t lot =  {{1,0,1,0,1,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,1},
        {1,0,1,1,1,1}};
    
    vint_t spot = {1, 1, 2, 3};
    

    
    bool res= parkingSpot(car, lot, spot);
    
    if (!res)
        cout << "WE GOT A PROBLEM" << endl;
    
    
    return res;
    
    
}

bool test_case_8 () {
    
    vint_t carDimensions ={ 2, 1};
    lot_t lot =  {{1,0,1},
                  {1,0,1},
                  {1,1,1}};
    vint_t spot = {1, 1, 2, 1};
    
    vint_t start_x, start_y, end_x, end_y;
    set_start(start_x, start_y, end_x, end_y, spot, lot);
    
    
    //cout << start_x[0] << " " << start_x[1] << " " << start_y[0] << " " << start_y[1] << endl;
    //cout << end_x[0] << " " << end_x[1] << " " << end_y[0] << " " << end_y[1] << endl;
    
    if (!(start_x[0] == 1 &&
          start_x[1] == 1 &&
          start_y[0] == 0 &&
          start_y[1] == 1  &&
          end_x[0] == 1 &&
          end_x[1] == 1 &&
          end_y[0] == 2 &&
          end_y[1] == 2 ))
        cout << "START NOT RIGHT" << endl;
    
    bool res= parkingSpot(carDimensions, lot, spot);
    
    if (res)
        cout << "WE GOT A PROBLEM" << endl;
    
    return !res;
    
}


bool test_case_identify_start() {
    bool ret_val = true;
    
    vint_t start_x, start_y, end_x, end_y;
    vint_t spot = {1, 1, 2, 3};
    lot_t lot = {{1,0,1,0,1,0},
                {1,0,0,0,1,0},
                {0,0,0,0,0,1},
                {1,0,0,0,1,1}};
    
    
    set_start(start_x, start_y, end_x, end_y, spot, lot);
   
    ret_val = (start_x[0] == 0 &&
               start_x[1] == 1 &&
               start_y[0] == 1 &&
               start_y[1] == 1 &&
               end_x[0] == 3 &&
               end_x[1] == lot[0].size()-1 &&
               end_y[0] == 2 &&
               end_y[1] == 2 );
    
    return ret_val;
    
    
}

int main(void){
    cout << "START" << endl;
    
    //cout << "TC 1: " << test_case_identify_start() << endl;
    
    //bool res = test_case_8();
    //cout << "TC 2: " << res << endl;
    
    bool res = test_case_1();
    cout << "TC 3: " << res << endl;

    
    
    cout <<"END" << endl;
    
    
}
