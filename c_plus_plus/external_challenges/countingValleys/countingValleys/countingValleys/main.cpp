//
//  main.cpp
//  countingValleys
//
//  Created by Scott Jackson on 1/5/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include<iostream>
using namespace std;


// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    
    int alt=0;
    int val_cnt =0;
    for (int i = 0; i < s.length(); i++) {
        
        int addend = (s[i] == 'U') ?  1 : -1;
        cout << addend << " " << alt << endl;
        if (alt == 0 && addend == -1) {
            cout << " NEW VAL" << endl;
            val_cnt++;
        }
        alt = alt + addend;
        
    }
    return val_cnt;
}

int main()
{
    string tmp = "DDUUDDUDUUUD";
    int k =12;
    int res = countingValleys(k,tmp);
    cout << "RES: " << res << endl;
}
