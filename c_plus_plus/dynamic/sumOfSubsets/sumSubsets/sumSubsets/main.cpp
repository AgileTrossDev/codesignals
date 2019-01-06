//
//  main.cpp
//  sumSubsets
//
//  Created by Scott Jackson on 12/31/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using std::cout;
using std::endl;


typedef std::vector<std::vector<int>> groups_t;
typedef std::map<int, groups_t> lookup_t;
typedef std::vector<int> unit_t;

void disp_v(unit_t &t);
void disp(groups_t &res, int tc);
void disp_t(lookup_t &lu);

void insert_util(lookup_t &tracker, int target, unit_t &data) {
    //cout << "UPDATING TRACKER: " << target << endl;
    if (tracker.find(target) == tracker.end() && !data.empty()) {
        groups_t tmp = {data};
        tracker.insert(make_pair(target,tmp));
    } else if (!data.empty()) {
        tracker[target].push_back(data);
    }
}


void join_results(lookup_t &tracker, int val, int key) {
    
    int target = val + key;
    //disp_t(tracker);
    
    //cout << "JOINING: " << target << " by including " << val << " in all of this key: " << key << " with " <<  tracker[key].size()  <<endl;
   
    if (tracker.find(key) == tracker.end()) return;
    
    // Init tracker for this target
    unit_t tmp;
    insert_util(tracker,target,tmp);
    
    //disp_t(tracker);
    //cout << "*******" << endl;
    
    for (int i=0; i < tracker[key].size(); i++) {
        //cout << "BLAH: " << key << "->" << i << endl;
        unit_t tmp = {val};
        tmp.insert( tmp.end(),  tracker[key][i].begin(),  tracker[key][i].end());
        //disp_v(tmp);
        sort(tmp.begin(),tmp.end());
        tracker[target].push_back(tmp);
    }
    
    //cout << "*******" << endl;
   // disp_t(tracker);
    //cout << "*******" << endl;
}

// Recursive function to populate the look-up by solving for Num starting with value at index
void sumSubsetsUtils(std::vector<int> &arr, int num, lookup_t &tracker, int index) {
    
    // Base case - input is larger than half off num or we are out of input
    if ( num < 1 || index >= arr.size()) return;
    
    int addend = num - arr[index];
    cout << "UTIL SOVLING FOR: " << num << " starting at " << index << " -> " << arr[index] << " PLUS " << addend << endl;
    
  
    //if (arr[index] > addend) return;
    
    
    if (tracker.find(num) != tracker.end()) return;
    
    // For each record in arr, find all subsets that equal to difference
    // combine the subsets to finalize the answer
    int i = index;
    
    for (; i < arr.size() && arr[i] <= addend ; i++) {
        //cout << "HERE: " << i << endl;
        
        if (num == arr[index] && tracker[num].empty()) {
            unit_t tmp = {num};
            insert_util(tracker, num, tmp);
            //disp_t(tracker);
        }

        // Find all subsets for the addend
        sumSubsetsUtils(arr, num-arr[i], tracker, i+1);
        //cout << "BACK" << endl;
        
        if (num == 35) disp_t(tracker);
        
        // Join results of arr[i] and num-arr[i]
        //cout << "INDEX: " << i << endl;
        //disp_t(tracker);
        join_results(tracker,arr[i], num-arr[i]);
        //cout << "JOIN COMPLETE" << endl;
        //disp_t(tracker);
        
        while (i+1 < arr.size() && arr[i] == arr[i+1]) i++;
       // i++;
        
        
    }
    //cout << "OK" << endl;
    //disp_t(tracker);
    // Now double check if num is already in the input and can be used.
    while (i<arr.size()) {
        if (arr[i]== num) {
            unit_t tmp = {num};
            insert_util(tracker,num,tmp);
            break;
        }
        i++;
    }
    //cout << "COMPLETE UTIL LOOKING FOR: " << num << " starting at " << index << " -> " << arr[index] << endl;
    //disp_t(tracker);
}


// Find the subsets by using dynamic programming approach
std::vector<std::vector<int>> sumSubsets(std::vector<int> arr, int num) {

    // Guard
    if (arr.empty() || num <= 0 )return {{}};
    
    // Memo to reduce work
    lookup_t tracker;
    
    // For each record in arr, find all subsets that equal to the addend
    // Combine the subset iwth the record to finalize the answer
    int i =0;
    for (; i<arr.size() && arr[i]<= num/2; i++) {
       cout << "BEGIN WITH: I:" << i << " V: " << arr[i] << endl;
        
        // Find all subsets forming the addend
        sumSubsetsUtils(arr, num-arr[i], tracker, i+1);
        
        cout << i <<  " BACK" << endl;
        disp_t(tracker);
        
        // Join results of arr[i] and num-arr[i]
        join_results(tracker,arr[i], num-arr[i]);
        
        while (i+1 < arr.size() && arr[i] == arr[i+1]) i++;
       
        //cout << "I: " << i << " " << (i<arr.size() && arr[i] <= num/2) << " " << (num/2) <<  endl;
        //cout << "DONE WITH: I:" << i << " V: " << arr[i] << endl;
        //disp_t(tracker);
    }
   
    // Now double check if num is already in the input and can be used.
    while (i<arr.size()) {
        if (arr[i]== num) {
            unit_t tmp = {num};
            insert_util(tracker,num,tmp);
            break;
        }
        i++;
    }
    
    groups_t results = tracker[num];
    
    return results;
    
}


//------------------------------------------------------
void disp_t(lookup_t &lu) {
    lookup_t::iterator itr = lu.begin();
    
    while (itr != lu.end()) {
        disp(itr->second,itr->first);
        itr++;
    }
    
    
    
    
}


void disp(groups_t &res, int tc) {
    
    cout << tc << "-DISP(" << res.size() << ") "  << " [ ";
    for (int i =0; i<res.size(); i++) {
        cout << " [ ";
        for (int j=0; j<res[i].size();j++) {
            cout << res[i][j] << ", ";
            
        }
        cout << " ] ";
        
        
    }
    
    cout << " ] " << endl;
   
}

void disp_v(unit_t &t) {
    cout << "V: ";
    for (int i= 0; i < t.size(); i++)
        cout << t[i] << " ";
    cout << endl;
    
}

void test_case_0 () {
    
    int num = 0 ;
    unit_t v = {};
    groups_t res = sumSubsets(v,num);
    cout << "TEST 0 COMPLETE" << endl;
    disp(res,0);
    
}


void test_case_1 () {
    
    int num = 5 ;
    unit_t v = {1, 2, 3, 4, 5};
    /*
     [[1,4],
     [2,3],
     [5]]
     */
    
    groups_t res = sumSubsets(v,num);
    disp(res,1);
    
}

void test_case_2 () {
    cout << "TC 2 Start " << endl;
    int num = 5 ;
    unit_t v = {10};
    groups_t res = sumSubsets(v,num);
    cout << "TEST 2 COMPLETE" << endl;
    disp(res,2);
    
}

void test_case_3 () {
    cout << "TC 3 Start " << endl;
    int num = 4 ;
    unit_t v = {1,3};
    groups_t res = sumSubsets(v,num);
    cout << "TEST 3 COMPLETE" << endl;
    disp(res,3);
    
}

void test_case_4 () {
    int tc = 4;
    cout << "TC " << tc << " Start " << endl;
    int num = 5 ;
    unit_t v = {1,2,2,3,4,5};
    
    groups_t res = sumSubsets(v,num);
    cout << "TC " << tc << " COMPLETE" << endl;
    disp(res,tc);
    
}

void test_case_5 () {
    int tc =5;
    cout << "TC " << tc << " Start " << endl;
    int num = 5 ;
    unit_t v = {1,2,3,4,5,5};
    groups_t res = sumSubsets(v,num);
    cout << "TC " << tc << " COMPLETE" << endl;
    disp(res,tc);
    
}

void test_case_6(){
    
    int tc=6;
    int num =9;
    unit_t v = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    groups_t res = sumSubsets(v,num);
    cout << "TC " << tc << " COMPLETE" << endl;
    disp(res,tc);
    
}
void test_case_7() {
    int tc=7;
    int num =9;
    unit_t v = {1, 1, 2, 2, 2, 5, 5, 6, 8, 8};
    groups_t res = sumSubsets(v,num);
    cout << "TC " << tc << " COMPLETE" << endl;
    disp(res,tc);
}

void test_case_8() {
    
    //          0  1  2  3  4  5
    unit_t v = {1, 1, 2, 4, 4, 4, 7, 9, 9, 13, 13, 13, 15, 15, 16, 16, 16, 19, 19, 20};
    int num =  36;
    int tc=8;
    groups_t res = sumSubsets(v,num);
    cout << "TC " << tc << " COMPLETE" << endl;
    disp(res,tc);
 /*
Output:
    [[1,1,2,4,4,4,7,13],
     [1,1,2,4,4,4,20],
     [1,1,2,4,4,9,15],
     [1,1,2,4,9,19],
     
     [1,1,2,4,13,15],
     [1,1,2,4,13,15],
     
     [1,1,2,7,9,16],
     [1,1,2,13,19],
     [1,1,2,16,16],
     [1,1,2,13,19],
     [1,1,4,4,4,7,15],
     [1,1,4,4,4,9,13],
     [1,1,4,4,7,19],
     [1,1,4,4,13,13],
     [1,1,4,15,15],
     [1,1,9,9,16],
     
     [1,1,15,19],
     [1,1,15,19],
     
     [1,2,4,4,9,16],
     [1,2,4,7,7,15],
     
     [1,2,4,7,9,13],
     [1,2,4,7,9,13],
     
     [1,2,4,9,20],
     
     [1,2,4,13,16],
     [1,2,4,13,16],
     
     [1,2,4,7,7,15],
     [1,2,4,7,9,13],
     [1,2,7,7,19],
     [1,2,7,13,13],
     [1,2,4,7,9,13],
     [1,2,4,9,20],
     [1,2,9,9,15],
     [1,2,7,13,13],
     
     [1,2,13,20],
     [1,2,13,20],
     
     [1,4,4,4,7,16],
     
     [1,4,4,7,7,13],
     [1,4,4,7,20],
     [1,4,4,7,7,13],
     
     [1,4,4,7,20],
     [1,4,7,9,15],
     [1,4,7,9,15],
     [1,4,9,9,13],
     
     [1,4,15,16],
     [1,4,15,16],
     
     [1,4,4,7,7,13],
     [1,4,4,7,20],
     [1,4,7,9,15],
     [1,7,9,19],
     
     [1,7,13,15],
     [1,7,13,15],
     
     [1,4,7,9,15],
     [1,4,9,9,13],
     [1,7,9,19],
     [1,9,13,13],
     [1,7,13,15],
     [1,9,13,13],
     [1,7,13,15],
     [1,15,20],
     [1,16,19],
     [1,16,19],
     [1,15,20],
     [2,2,4,4,4,7,13],
     [2,2,4,4,4,20],
     [2,2,4,4,9,15],
     [2,2,4,9,19],
     [2,2,4,13,15],
     [2,2,4,13,15],
     [2,2,7,9,16],
     [2,2,13,19],
     [2,2,16,16],
     [2,2,13,19],
     [2,4,4,4,7,15],
     [2,4,4,4,9,13],
     [2,4,4,7,19],
     [2,4,4,13,13],
     [2,4,15,15],
     [2,9,9,16],
     [2,15,19],
     [2,15,19],
     [4,4,4,4,7,13],
     [4,4,4,4,20],
     [4,4,4,9,15],
     [4,4,9,19],
     [4,4,13,15],
     [4,4,13,15],
     [4,7,9,16],
     [4,13,19],
     [4,16,16],
     [4,13,19],
     [4,7,9,16],
     [7,7,7,15],
     [7,7,9,13],
     [7,7,9,13],
     [7,9,20],
     [7,13,16],
     [7,13,16],
     [4,7,9,16],
     [7,7,9,13],
     [7,9,20],
     [7,13,16],
     [7,13,16],
     [16,20]]
    Expected Output:
    [[1,1,2,4,4,4,7,13],
     [1,1,2,4,4,4,20],
     [1,1,2,4,4,9,15],
     [1,1,2,4,9,19],
     [1,1,2,4,13,15],
     [1,1,2,7,9,16],
     [1,1,2,13,19],
     [1,1,2,16,16],
     [1,1,4,4,4,7,15],
     [1,1,4,4,4,9,13],
     [1,1,4,4,7,19],
     [1,1,4,4,13,13],
     [1,1,4,15,15],
     [1,1,9,9,16],
     [1,1,15,19],
     [1,2,4,4,7,9,9],
     [1,2,4,4,9,16],
     [1,2,4,7,9,13],
     [1,2,4,9,20],
     [1,2,4,13,16],
     [1,2,7,13,13],
     [1,2,9,9,15],
     [1,2,13,20],
     [1,4,4,4,7,16],
     [1,4,4,7,20],
     [1,4,7,9,15],
     [1,4,9,9,13],
     [1,4,15,16],
     [1,7,9,19],
     [1,7,13,15],
     [1,9,13,13],
     [1,15,20],
     [1,16,19],
     [2,4,4,4,7,15],
     [2,4,4,4,9,13],
     [2,4,4,7,19],
     [2,4,4,13,13],
     [2,4,15,15],
     [2,9,9,16],
     [2,15,19],
     [4,4,4,9,15],
     [4,4,9,19],
     [4,4,13,15],
     [4,7,9,16],
     [4,13,19],
     [4,16,16],
     [7,9,20],
     [7,13,16],
     [16,20]] */
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
    test_case_0();
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();
    test_case_7();
     */
    test_case_8();

    return 0;
}
