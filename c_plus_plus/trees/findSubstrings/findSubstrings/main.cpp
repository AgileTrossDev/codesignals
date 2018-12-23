//
//  main.cpp
//  findSubstrings
//
// You have two arrays of strings, words and parts. Return an array that contains the strings from words,
// modified so that any occurrences of the substrings from parts are surrounded by square brackets [],
// following these guidelines:
//
//
// If several parts substrings occur in one string in words, choose the longest one. If there is still
// more than one such part, then choose the one that appears first in the string.
//
//  Created by Scott Jackson on 12/16/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;


typedef std::vector<std::string> input_t;



struct Node {
    Node(char c) : val(c), complete(false) {}
    
    
    ~Node() {
        for (int i=0;i<children.size();i++){
            delete children[i];
        }
    }
    
    
    Node * add_child(char c) {
        
        Node * node = find_child(c);
        if (node ==0) {
            node = new Node(c);
            children.push_back(node);
        }
        return node;
    }
    
    
    Node* find_child(char c) {
        Node * child = 0;
        for (int i=0;i<children.size();i++){
            if (children[i]->val == c){
                child = children[i];
                break;
            }
            
        }
        return child;
    }
    
    
    char val;
    std::vector<Node *> children;
    bool complete;
};


Node * build_tree(input_t &input) {
    Node * root = new Node('!');
    Node * index= root;
    int cnt = 0;
    for (int i =0; i< input.size(); i++) {
        index = root;
        //cout << "BUILDING: " << input[i] << endl;
        
        for(int j=0; j<input[i].length(); j++){
            index = index->add_child(input[i][j]);
            cnt++;
        }
        index->complete =true;
    }
    //cout << "COUNT: " << cnt << endl;
    return root;
}


std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
    input_t output;
    
    // Build a Tries for quick look up of parts
    Node * tree = build_tree(parts);
    
    Node * node = tree;
    
    // For each word
    for (int i =0; i< words.size(); i++) {
        //cout << "CODING WORD: " <<words[i] << endl;
        
        // Traverse the word starting conditions
        int j =0;
        int  largest=-1,larg_start=-1, larg_end=-1;
        
        // Loop until we reach end of a word by incrementing j by 1
        // TODO: Early exit possible
        while (j < words[i].length()) {
            
            int index =j;
            node = tree;
            
            // Tree search init
            int cur_size = 0, cur_start =j;
            
            //cout << "WC: " << words[i][index]  << " NC: " <<node->val << endl;
            
            // Search tree starting at indexed character
            node = node->find_child(words[i][index]);
            while (node !=0 ) {
                //cout << "LOOP " << node->val<< " " << node->complete  << endl;
                
                if ((node!=0 && node->complete) && cur_size> largest) {
                    largest = cur_size;
                    larg_start = cur_start;
                    larg_end = index;
                }
                
                index++;
                cur_size++;
                node = node->find_child(words[i][index]);
                
               
               
                
            }
            /*cout << "N: " << node << endl;
            if (node!=0)
                cout << "BURP: " << node->val << endl;
            */
           
            
            // Search complete from this character,
            // so move to the next character
            j++;
        }
        
        // Searching word is complete,
        // now if necessary, adjust string
        // and then insert it into the output
        
        std::string tmp =words[i];
        if (larg_start != -1 && larg_end != -1) {
            // Sub found
            tmp.insert(larg_start,"[");
            tmp.insert(larg_end+2,"]");
        }
        output.push_back(tmp);
        
    }
    
    return output;
}


//========================================================================================================
// Dev Helpers
//========================================================================================================
void disp_tree_dive(Node * root, std::string w) {
    
    if (root != 0) {
        //cout << root->val;
        w = w + root->val;
        
        if (root->complete){
            cout << "WORD: " << w << endl;
        }
        
        for (int i=0;i< root->children.size();i++)
            disp_tree_dive(root->children[i], w);
    }
}

void disp_tree(Node * root) {
    cout << "DISPLAYING TREE" << endl;
    std::string w;
    
    if (root  != 0 ) {
       for (int i=0;i<root->children.size();i++) {
             disp_tree_dive(root->children[i], w);
        }
   }
}


void disp(input_t v) {
    cout << "DISP:";
    for (int i=0; i<v.size();i++) {
        cout << " " << v[i];
    }
    cout << endl;
}

//========================================================================================================
// Test Cases
//========================================================================================================
void test_case_2() {
    
    input_t words = {"neuroses", "myopic", "sufficient",
        "televise", "coccidiosis", "gules", "during", "construe", "establish", "ethyl" };
    
    input_t wordsa = {"myopic" };
    
    input_t parts = {"aaaaa", "Aaaa", "E", "z", "Zzzzz", "a", "mel", "lon", "el", "An", "ise", "d", "g",
                    "wnoVV","i", "IUMc", "P", "KQ", "QfRz", "Xyj", "yiHS" };

    input_t expected_output =
    {"neuroses",
     "myop[i]c",
     "suff[i]cient",
     "telev[ise]",
     "cocc[i]diosis",
     "[g]ules",
     "[d]uring",
     "construe",
     "est[a]blish",
        "ethyl"};
    
    
    //Node * root = build_tree(parts);
    //for (int i=0; i<root->children.size();i++) {
    //    cout << " " << root->children[i]->val;
    //}
    cout << endl;
    
    
    //disp_tree(root);
    //root = root->find_child('i');
   
    
    input_t output = findSubstrings(words,parts);
    disp(output);
    
    
}

void test_case_1() {
    input_t words =  {"Apple", "Melon", "Orange", "Watermelon"};
    input_t parts =  {"a", "mel", "lon", "el", "An"};
    input_t output = findSubstrings(words,parts);
    disp(output);
}


void test_case_build_tree() {
    input_t parts =  {"a", "mel", "lon", "el", "An"};
    Node * root = build_tree(parts);
    disp_tree(root);
}

//========================================================================================================
// Main
//========================================================================================================
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //test_case_build_tree();
    //test_case_1();
    test_case_2();
    return 0;
}
