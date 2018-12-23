//
//  main.cpp
//  canal_skating
//
/*
// Located in Canada's capital city, the Rideau Canal Skateway is the longest
// skating rink in the world, measuring a total of 7.8 kilometres!
//
// The locations of specific landmarks along the canal tend to be described
// according to their distance from the north end (eg: 7.0km would be close
// to the south end, 3.5km would be close to the middle). For the sake of this
// challenge, we'll be looking at finer grain distances, so we'll generally
// use metres instead of kilometres.
//
//
// As part of the canal skating experience, many tourists and locals like to enjoy
// a fried dough treat called a beavertail (don't let the name fool you - it's made
// from vegan-friendly pastry)! This is considered such an essential part of the
// experience that there are 4 beavertail vendors located at various points along
// the canal.
//
// Their approximate locations are 200m, 1400m, 3250m, and 7000m.
//
// If you're planning to skate on the canal, it's always a good idea to check the
// conditions first! There are 6 different quality grades for the ice, and this will
// affect how fast you're able to skate across that part of the surface.
//
// Quality grade    Numerical form    Skate time (seconds per metre)
// Very good           5               1
// Good                4               2
// Fair                3               3
// Poor                2               5
// Snow Covered        1               8
// Closed              0               -
//
You have a concise list of the current ice conditions, represented as ranges. More
// specifically, each section is represented as an array of the form [rangeStart,
// quality], meaning that the ice conditions from rangeStart onward will be in a
// state represented by quality.
//
// So for example, conditions = [[0, 3], [2000, 5], [5200, 2]] means that the ice
// is fair between 0m and 1999m (inclusive), very good between 2000m and 5199m, and
// poor between 5200m and 7800m.
//
// Given conditions and startPoint (your start point in metres), your task is to find
// the minimal amount of time (in seconds) required to reach a beavertail vendor!
// Return -1 if it's not possible to reach a beavertail vendor.
//
// Note:
//
// Include the first and last metre as part of the journey (ie: the startPoint
// location and the goal location are both part of the journey).
//
// You can't skate across any closed zones.
// The endpoints are 0m and 7800m, both of which can be included in your travel.
// The distance ranges in conditions[i][0] only state the start point of the range,
//  so you can assume this quality is consistent until conditions[i + 1][0] (or
// 7800m if there is no conditions[i + 1]).
//
// Remember: the beavertail stands are located at 200m, 1400m, 3250m, and 7000m.
//
//  Created by Scott Jackson on 12/20/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

typedef std::vector<std::vector<int> > cond_t;


const vector<int> STORES = {200, 1400, 3250, 7000};
const vector<int> LOOK_UP = {0,8,5,3,2,1};
const int THE_END = 7800;

int convert_time(int g) { return LOOK_UP[g];}

int determine_start_zone(std::vector<std::vector<int> > c,int s ) {
    int i =0;
    while (c[i][0] < s )
        i++;
    return (i-1);
}

int find_north(int s) {
    int i = 0;
    while (i < STORES.size() && s > STORES[i]) i++;
    if (i > STORES.size()) i--;
    return STORES[i-1];
}

int find_south(int s) {
    int i = 0;
    while (i<STORES.size() && s > STORES[i]) i++;
    if (i >= STORES.size()) return -1;
    return STORES[i];
}

int canalSkating(std::vector<std::vector<int> > c, int s) {
    c.push_back({THE_END,0});
    int best_time = 0;
    
    int index = s;
    int end_n = find_north(s);
    int end_s = find_south(s);
    int timen = 0;
    int times = 0;
    
    cout << "NORTH: " << s << endl;
    int zone = determine_start_zone(c, s);
    bool n_poss = (end_n < s);
    
    while (n_poss ) {
        
        cout << "Z: " << zone << " I: " << index << " t: " << timen << endl;
        if ( c[zone][1] == 0) {
            //cout << " BLAH " << endl;
            n_poss = false;
            break;
        }
        
        // Distance travalled in zone to next zone or end point
        int sub = std::max(c[zone][0],end_n);
        int d = index - sub + 1;
        //cout << index << " - " << sub  << " " << index-sub <<"   D: " << d << " MULT: " << convert_time(c[zone][1]) << " SUB "  << sub << endl;
        
        // Add the time
        timen += d * convert_time(c[zone][1]);
        
        if (index - d +1 == end_n) break;
        
        // Moving to next zone
        index=c[zone][0]-1;
        zone--;
        
    }
    cout << "N: " << timen << endl;
    
    cout << "SOUTH: " << s << endl;
    zone = determine_start_zone(c, s);
    bool s_poss = (end_s > s);
    while (s_poss ) {
        cout << "Z: " << zone << " I: " << index << " t: " << times << endl;
        if ( c[zone][1] == 0) {
            s_poss = false;
            break;
        }
        // Distance travalled in zone to next zone or end point
        int sub = std::min(c[zone+1][0]-1,end_s);
        int d = sub - index+1;
        cout << index << " - " << sub  << " " << index - sub <<"   D: " << d << " MULT: " << convert_time(c[zone][1]) << " SUB "  << sub << endl;
        // Add the time
        times += d *  convert_time(c[zone][1]);
        
        if (index + d -1 == end_s) break;
        
        // Moving to next zone
        zone++;
        index=c[zone][0];
       
        
    }
      cout << "S: " << times << endl;
    
    
    
    
    
    cout << "N: " << timen << " S: " << times << endl;
    
    if (n_poss && s_poss) {
        cout << "?" << endl;
        best_time = std::min(timen,times);
    } else if (n_poss){
         cout << "F" << endl;
        best_time = timen;
    } else if (s_poss)
        best_time = times;
    else
        best_time =-1;
    return best_time;
}


void test_case_4() {
    
    
    cond_t c =  {{0,5}};
    int s = 3000;
    int r= canalSkating(c,s);
    cout << "TC 3: " << r << endl;
}

void test_case_3() {
    
    
    cond_t c =  {{0,0},
        {400,3},
        {800,4},
            {1400,0},
                {2050,3},
                    {3150,5}};
    int s = 795;
    int r= canalSkating(c,s);
    cout << "TC 3: " << r << endl;
}

void test_case_2() {
    
// NORTH:
// 2501 1400
// Z: 3 LOC: 2050 D: 451 T: 2255 E: 1400
//    2050 1400
// Z: 2 LOC: 1400 D: 650 T: 4205 E: 1400
//
//    SOUTH 2500
// Z: 3 LOC: 3150 D: 651 T: 3255 E: 3250
// Z: 4 LOC: 3250 D: 101 T: 3457 E: 3250
// B: 3457
    
    cond_t c =  {{0,0}, {800,1}, {1400,3}, {2050,2}, {3150,4}, {3850,3}, {4300,5}, {5300,4}, {7200,2}};

    int s = 2500;
    int r= canalSkating(c,s);
    cout << "TC 2: " << r << endl;
}



void test_case_1() {
    
    /*
     NORTH:
     7503 7000
     WTF : 303 303  503 ? 7200
     Z: 6 LOC: 7200 D: 303 T: 606 E: 7000
     7200 7000
     WTF : 200 1900  200 ? 5300
     Z: 5 LOC: 7000 D: 200 T: 1206 E: 7000
     NORTH: 1206
     SOUTH 7502
     Z: 6 LOC: -1 D: -7503 T: -15004 E: -1
     SOUTH: T-> -15004
     B: -15004
     
     */
    cond_t c =  { {0,1}, {400,2}, {2050,5},{2850,0},{3150,1},{5300,3},{7200,4}, {7800,1}};
    int s = 7502;
    int r= canalSkating(c,s);
    cout << "TC 1: " << r << endl;
}


void test_case_0() {
    cond_t c = {{0,3}, {2850,4}, {5300,2}};
    int s = 5500;
    
    int r= canalSkating(c,s);
    cout << "TC 0: " << r << endl;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //test_case_0();
    //test_case_1();
    //test_case_2();
    //test_case_3();
    test_case_4();
    return 0;
}
