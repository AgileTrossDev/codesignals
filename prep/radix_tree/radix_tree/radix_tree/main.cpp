//
//  main.cpp
//  radix_tree
//
//  Created by Scott Jackson on 3/27/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//


#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;
using std::cout;
using std::endl;
using std::string;

struct Node {
    Node(string val, bool wrd= false): value(val), is_word(wrd){};
    
    void add_word(string wrd, int index =0) {
        
        if (index >= wrd.length()) return;
        
        // See if an existing key needs to be broken up
        int i = index;
        int j =0;
        while (j< value.length() && i < wrd.length() && wrd[i] == value[j] ) {
            i++;
            j++;
        }
        
        if (j < value.length()) {
            // Break-up value
            string tmp = value;
            value = value.substr(0,j-1);
            
            // Now add tail of old value as a child
            add_word(tmp.substr(j));
            
            // Need to push children to newly created child.
            children[tmp[j]]->children.insert(children.begin(), children.end());
            
            map<char, Node *>::iterator itr;
            while ( itr != children.end()) {
                Node * c = itr->second;
                itr++;
                if (c->value[0] != tmp[j]) children.erase(c->value[0]);
            }
        }
        
        // Add Key if it doesn't exist
        if (children.end() == children.find(wrd[index])) {
            children[wrd[index]] = new Node(string(1,wrd[index]));
        }
        
        
  
        
        // Check to see if we have a complete word
        if (index == wrd.length() -1 )
            children[wrd[index]]->is_word =true;
        else
            children[wrd[index]]->add_word(wrd,index+1);
        
        
        // Compress tree if possible
        if (children.size() == 1) {
            // combine values and update is_word flag
            value += children[wrd[index]]->value;
            if ( children[wrd[index]]->is_word) is_word =true;
            
            // Merge pull in chidren from this node's single child
            Node * tmp = children[wrd[index]];
            children[wrd[index]] = nullptr;
            children.insert(tmp->children.begin(),tmp->children.end());
            delete tmp;
            tmp = nullptr;
        }
        
    }
    
    
   
    
    string value;
    bool is_word;
    map<char, Node *> children;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
