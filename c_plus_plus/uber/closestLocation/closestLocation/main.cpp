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

using std::vector;
using std::set;
using std::string;
using std::find;
using std::find_if;
using std::cout;
using std::endl;
using std::map;

struct Node;

typedef vector<std::vector<int>> obj_t;
typedef std::vector<std::string> names_t;
typedef map<char,Node*> child_t;
typedef set<int> tracker_t;

struct Node {
    Node (char v) : val(tolower(v)), word(-1) {};
    
    Node * add_child(char v) {
        v = tolower(v);
        child_t::iterator it =  children.find(v);
        
        if (it == children.end()){
            Node * new_node = new Node(v);
            children[v] = new_node;
            return new_node;
        }
        
        return children[v];
    }
    
    
    void find_complete_words(tracker_t &tracker) {
        
        if (word != -1) tracker.insert(word);
        
        for (child_t::iterator i = children.begin(); i != children.end(); i++) {
            i->second->find_complete_words(tracker);
        }
        
    }
    
    void find_match(tracker_t tracker, string wrd) {
        
        
        
        
    }
    
    Node * find_child(char v) {
         v = tolower(v);
        child_t::iterator it =  children.find(v);
        
        if (it != children.end()) { children[v];}
        
        return nullptr;
    }
    
    
    Node * find_grand_child(char v) {
         v = tolower(v);
        Node * fnd = nullptr;
        for (child_t::iterator i = children.begin(); i != children.end(); i++) {
            fnd = i->second->find_child(v);
            if (fnd != nullptr) break;
        }
        return fnd;
    }
    
    
    char val;
    int word;
    child_t children;
};


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


// Populates tracker with indexes of valid words that meet the follow citeriea
//
// Base case of recursion
//   1. index at second to last letter and no typos - > all under are valid
//   2. index at last matching letter and typos -> all Under are valid
//
//
// 1. the typed in address is identical to the prefix of the object's address;
// 2. they differ only by one symbol;
// user's input has one extra symbol;
// user's input has one missing symbol.
void find_matches(Node *root, string wrd, tracker_t &tracker,  int typos = 0, int index = 0) {

    Node * nxt = nullptr;
    
    // Check to see if we are finalizing the word search
    if (index == wrd.size()-2 && typos == 0) {
        // Base Case 1.
        root->find_complete_words(tracker);
        
    } else if (index == wrd.size()) {
        // Reached end of pre-fix, so anything below that is valid is a suggestion
        root->find_complete_words(tracker);
    } else {
        // Still more letters to traverse
        
        nxt = root->find_child(wrd[index]);
        
        if (nxt != nullptr && typos == 0) {
            index++;
            typos++;
            nxt = root->find_grand_child(wrd[index]);
        }
        
        if (nxt != nullptr) {
            find_matches(root, wrd, tracker, typos , index+1);
        }
    }
}


// Calculates distance from 0,0
// Handles segments
float find_distance() {
    
    
    return 0.0;
}


std::string closestLocation(std::string address, obj_t objects, names_t names) {
    Node * root = build_dict( names) ;
    
    // Find possible matches
    tracker_t tracker;
    find_matches(root, address, tracker);
    if (tracker.size() == 0) return "";
    
    // Matches found, so calculate closest.
    float min_distance = INT_MAX;
    int min_id = -1;
    for (int i=0; i < tracker.size(); i++) {
        float calc =  find_distance();
        if (calc < min_distance) {
            min_distance = calc;
            min_id = i;
        }
    }
    
    return names[min_id];
}


// ----------------------------------------------------------------------------------------------------
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

int main(int argc, const char * argv[]) {
    // insert code here...

    std::cout << "Hello, World!\n";
    test_case_1();
    return 0;
}
