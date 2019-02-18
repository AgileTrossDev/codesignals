//
//  main.cpp
//  quick_sort_2
//
//  Created by Scott Jackson on 2/10/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;


void swap(string &s, size_t l ,size_t r) {
    char tmp = s[l];
    s[l] = s[r];
    s[r] = tmp;
}

size_t partition(string &s, size_t l ,size_t r){
    if (l == r) return r;
    char val = s[(l+r)/2];
    cout << "PART: " << s << " > " << l << " " << r <<  " " << val << endl;
    
    while(l<r){
        while (s[l] <= val) l++;
        while (val < s[r]) r--;
        if (l>=r) return r;
        swap(s,l,r);
    }
    return 0;
}

void do_sort(string &s, size_t l, size_t r) {
    
    if (l>=r) return;
    //cout << "DS: " << s << " > " << l << " " << r << endl;
    
    size_t index = partition(s,l,r);
    
    if (l<r) {
        do_sort(s, l, index);
        do_sort(s, index+1,r );
    }
}

string do_sort(string s) {
    do_sort(s, 0, s.size()-1);
    return s;
}


// ##################
// ##### TESTS ######
// ##################

void test(int i, string s,  string e) {
    string r = do_sort(s);
    cout << "TC " << i <<": " << r << "->" << (e==r) << endl;
}



void tc_1() {
    
    test(1,"CBA","ABC");
    test(2,"ABC","ABC");
    //test(3,"AAA","AAA");
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
