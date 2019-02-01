//
//  main.cpp
//  closestLocation
//
//  Created by Scott Jackson on 1/28/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <set>
#include <math.h>

using std::vector;
using std::set;
using std::string;
using std::find;
using std::find_if;
using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;


struct Node;

typedef vector<std::vector<int>> obj_t;
typedef vector<int> addr_t;
typedef std::vector<std::string> names_t;
typedef map<char,Node*> child_t;
typedef set<int> tracker_t;


//--------------------------------------------------------------------------------------
// Tries Definition
//--------------------------------------------------------------------------------------
struct Node {
    Node (char v) : val(tolower(v)), word(-1) {};
    
    Node * add_child(char v);
    
    bool is_valid(string wrd, int i =0);
    void find_words(tracker_t &tracker);
    void find_matches(string wrd, tracker_t &tracker, int allowed =1, int typos=0, int index=0,string so_Far = "");
    Node * find_child(char v);
    
    
    char val;
    int word;
    child_t children;
};



Node * Node::find_child(char v) {
    v = tolower(v);
    child_t::iterator it =  children.find(v);
    if (it != children.end()) { return children[v];}
    return nullptr;
}


bool Node::is_valid(string wrd, int i) {
    Node * chld = find_child(wrd[i]);
    if (chld == nullptr) return false;
    i++;
    if (wrd.size() == i) {
        return  true;
    }
    
    return chld->is_valid(wrd,i);
    
}

void Node::find_words(tracker_t &tracker) {
    if (word != -1) {
        tracker.insert(word);
    }
    
    for (child_t::iterator i = children.begin(); i != children.end(); i++) {
        i->second->find_words(tracker);
    }
    
}



// Find all canditates that match wrd.  Factors is possible typos (missing, extra, wrong)
// wrd - prefix
// tracker - holds integers of canditates
// allowed - number of typos allowed
// typos - number of errors found
// index - index of character we are looking for
// so_Far - Prefix path so far
void Node::find_matches(string wrd, tracker_t &tracker, int allowed, int typos, int index, string so_Far) {
    so_Far.push_back(val);
    
    if (allowed<typos) return;
    if(index == wrd.size()) {
        find_words(tracker);
    }
    
    for (child_t::iterator i = children.begin(); i != children.end(); i++) {
        if (wrd[index] == i->first)
            i->second->find_matches( wrd, tracker,  allowed, typos, index+1, so_Far);
        else if (wrd[index+1] == i->first)
            i->second->find_matches( wrd, tracker,  allowed, typos+1, index+2, so_Far);
        else
            i->second->find_matches( wrd, tracker,  allowed, typos+1, index+1, so_Far);
    }
    
}


Node * Node::add_child(char v) {
    v = tolower(v);
    child_t::iterator it =  children.find(v);
    
    if (it == children.end()){
        Node * new_node = new Node(v);
        children[v] = new_node;
        return new_node;
    }
    
    return children[v];
}


//--------------------------------------------------------------------------------------
// Tries Support
//--------------------------------------------------------------------------------------
void add_to_dictionary(Node* cur, string &wrd,int wrd_index, int index=0) {
    if (index == wrd.length() ){
        cur->word = wrd_index;
    } else {
        Node* n = cur->add_child(wrd[index]);
        add_to_dictionary(n, wrd, wrd_index, index+1);
    }
}


Node * build_dict(names_t names) {
    Node * root = new Node ('*');
    
    for(int i =0; i< names.size(); i++) {
        add_to_dictionary(root, names[i], i);
    }
    return root;
}


//--------------------------------------------------------------------------------------
// Calc
//--------------------------------------------------------------------------------------

// Calculates distance from 0,0
// Handles segments
float find_distance(addr_t & addr) {
    if ( addr.size() ==2)  return sqrt(pow(abs(addr[0]),2) + pow(abs(addr[1]),2));
    //cout << "ROAD" << endl;
    if (addr[0] == addr[2]) {
        // Vertical
        if (( addr[1] < 0 && addr[3] < 0) || (addr[1] > 0 && addr[3] < 0)) {
            // Crosses axis
            return abs(addr[0]);
        }
        
        int tmp = -1;
        if (0 > addr[1] ) {
            tmp = max(addr[1],addr[3]);
        } else {
            tmp = min(addr[1],addr[3]);
        }
        return sqrt(pow(abs(addr[0]),2) + pow(abs(tmp),2));
        
    }
    
    
    // Vertical
    if (( addr[0] < 0 && addr[2] > 0) || (addr[0] > 0 && addr[2] < 0)) {
         // Crosses axis
        return abs(addr[1]);
    }
    
    int tmp = -1;
    if (0 > addr[0] ) {
        tmp = max(addr[0],addr[0]);
    } else {
        tmp = min(addr[0],addr[1]);
    }
    
    return sqrt(pow(abs(addr[0]),2) + pow(abs(tmp),2));
}


std::string closestLocation(std::string address, obj_t objects, names_t names) {
    Node * root = build_dict( names) ;
    
    // Find possible matches
    tracker_t tracker;
    root->find_matches(address, tracker);
    if (tracker.size() == 0) return "ERROR";
   
    // Matches found, so calculate closest.
    float min_distance = INT_MAX;
    int min_id = -1;
    for (tracker_t::iterator i = tracker.begin(); i != tracker.end(); i++) {
       
        float calc =  find_distance(objects[*i]);
        if (calc < min_distance) {
            min_distance = calc;
            min_id = *i;
        }
    }
    
    return names[min_id];
}


//--------------------------------------------------------------------------------------
// Dev Support
//--------------------------------------------------------------------------------------
void disp_tries(Node * root) {
    
    cout << root->val << ": ";
    
    for (child_t::iterator i = root->children.begin(); i != root->children.end(); i++) {
        cout << i->first << " ";
    }
    cout << endl;
    
    for (child_t::iterator i = root->children.begin(); i != root->children.end(); i++) {
        disp_tries(i->second);
    }
}

void disp_tracker(tracker_t &tracker, names_t names) {
    cout << "TRACKER: " << tracker.size() << endl;
    for (tracker_t::iterator i = tracker.begin(); i != tracker.end(); i++) {
        cout << "TRACKER: " << names[*i] << endl;
        
    }
    
}

//--------------------------------------------------------------------------------------
// Test Cases
//--------------------------------------------------------------------------------------
void test_case_1 () {
    string address =  "Cat";
    obj_t objects =  {{-2,0},
                {1,2},
                {2,1,2,4},
                {-3,-1,4,-1}};
    names_t names =  {  "Bat building",
                        "Cast exhibition",
                        "At street",
                        "Cat avenue"};

   string res =  closestLocation(address, objects, names);
   cout << "TC 1: " << res << endl;
    
}

void test_case_2() {
    
    string address =  "Cat";
    obj_t objects =  {{-3,0},
        {1,3},
        {2,1,2,4},  // 2.23607
        {-4,-3,6,-3}};
    
    names_t names =  {  "Bat building",
        "Cats exhibition",
        "Cramp",
        "cat avenue"};
    

    string res =  closestLocation(address, objects, names);
    cout << "TC 2: " << res << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    std::cout << "Hello, World!\n";
    test_case_1();
    test_case_2();
    return 0;
}
