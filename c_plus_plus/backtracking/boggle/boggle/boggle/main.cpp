//
//  main.cpp
//  boggle
//
//  Created by Scott Jackson on 2/3/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Boggle is a popular word game in which players attempt to find words in sequences of adjacent
// letters on a rectangular board.
//
// Given a two-dimensional array board that represents the character cells of the Boggle board
// and an array of unique strings words, find all the possible words from words that can be
// formed on the board.
//
// Note that in Boggle when you're finding a word, you can move from a cell to any of its
// 8 neighbors, but you can't use the same cell twice in one word.
//
//
// Example
//
// For
//
// board = [
//          ['R', 'L', 'D'],
//          ['U', 'O', 'E'],
//          ['C', 'S', 'O']
//          ]
// and words = ["CODE", "SOLO", "RULES", "COOL"], the output should be
// wordBoggle(board, words) = ["CODE", "RULES"].
//
// Example
//
// Input/Output
//
// [execution time limit] 0.5 seconds (cpp)
//
// [input] array.array.char board
//
// A two-dimensional array of uppercase English characters representing a rectangular Boggle board.
//
// Guaranteed constraints:
// 2 ≤ board.length ≤ 4,
// 2 ≤ board[i].length ≤ 4,
// 'A' ≤ board[i][j] ≤ 'Z'.
//
// [input] array.string words
//
// An array of unique English words composed only of uppercase English characters.
//
// Guaranteed constraints:
// 0 ≤ words.length ≤ 100,
// 2 ≤ words[i].length ≤ 16,
// 'A' ≤ words[i][j] ≤ 'Z'.
//
// [output] array.string
//
// Words from words that can be found on the Boggle board without duplicates and sorted
// lexicographically in ascending order.





#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::map;
using std::string;
using std::min;
using std::max;
using std::cout;
using std::endl;
using std::sort;


//===========================================================================
// Solution
//===========================================================================
struct Node;

typedef std::vector<std::string> result_t;
typedef std::vector<std::vector<char>> board_t;
typedef std::vector<std::string> words_t;
typedef map<char, Node *> children_t;
typedef std::vector<std::vector<bool>> visited_t;

struct Node {
    Node(char v): val(v),valid(false) {};
    
    Node * add_child(char v) {
        children_t::iterator itr = children.find(v);
        if (itr == children.end()) children[v] = new Node(v);
        return children[v];
    }
    
    
    void add_word(string wrd, int index=0) {
        if (index == wrd.length()) {
            valid = true;
        } else {
            // Add Next Letter
            children_t::iterator itr = children.find(wrd[index]);
            if (itr == children.end()) add_child(wrd[index]);
            children[wrd[index]]->add_word(wrd,index+1);
        }
    }
    
    
    Node * has_child(char v){
        children_t::iterator itr = children.find(v);
        if (itr == children.end()) return nullptr;
        return children[v];
    }

    bool valid;
    char val;
    children_t children;
    
};

void boogle(board_t &board,int row, int col, Node * root, result_t &r,visited_t &v, string so_far ="") {
    if (v[row][col]) return;
    
    so_far.push_back(board[row][col]);
    cout << "SO_FAR: " << so_far << endl;
    
    if (root->valid){
        r.push_back(so_far);
        root->valid = false;
    }
    
    //cout << "LOOK AT: " << board[row][col] << " == " << root->val << endl;
    v[row][col] = true;
    
    for (int i = max(0,row-1); i<= min((int)board.size()-1, row+1); i++){
        for (int j = max(0,col-1); j<=min((int)board[row].size()-1,col+1); j++){
            //cout << "I/J: " << i << " " << j << " " << min((int)board.size(), row+1) << " " <<min((int)board[row].size(),col+1) << endl;
            
            if (i==row && j ==col) continue;
            Node * index = root->has_child(board[i][j]);
            
            if (index != nullptr) boogle(board,i,j,index,r,v,so_far);
        }
    }
    v[row][col] = false;
    
    
}


result_t wordBoggle(board_t board, words_t words) {
    result_t r;
    Node * root = new Node('*');
    visited_t v(board.size(), vector<bool> (board.size(), false));
    
    // Create Tries
    for(int i=0;i<words.size();i++) root->add_word(words[i]);
    
    // Search for Board
    for (int row = 0; row < board.size(); row++){
        for (int col = 0; col < board[row].size(); col++ ){
            cout << "STARTING: " << board[row][col] << endl;
            Node * index = root->has_child(board[row][col]);
            if (index !=nullptr) boogle(board,row,col,index,r,v);
        
        }
    }
        
    
    sort(r.begin(),r.end());
    return r;
    
}

//===========================================================================
// Test Cases
//===========================================================================
void disp(result_t res, int b){
    cout << "RESULTS " << b << ": " << endl;
    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";
    
    cout << endl;
    
    
}

void test_case_3(){
    
    
    board_t board=  {{'A','X','V','W'},
                     {'A','L','T','I'},
                     {'T','T','J','R'}};
         
    words_t words = {"AXOLOTL",
        "TAXA",
        "ABA",
        "VITA",
        "VITTA",
        "GO",
        "AXAL",
        "LATTE",
        "TALA",
    "RJ"};
    
    result_t res=  wordBoggle( board,  words);
    
    disp(res,3);
}


void test_case_2() {
    
    board_t board= {{'G','T'},
                    {'O','A'}};
    words_t words = {"TOGGLE",
        "GOAT",
        "TOO",
        "GO"};
    
    result_t res=  wordBoggle( board,  words);
    
    disp(res,2);
}

void test_case_1() {
    board_t board= {{'R','L','D'},
        {'U','O','E'},
        {'C','S','O'}};
    
    words_t words = {"CODE",
        "SOLO",
        "RULES",
        "COOL"};
    
    
    result_t res=  wordBoggle( board,  words);
    
    disp(res,1);
    
}

//===========================================================================
// Main
//===========================================================================
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //test_case_1();
    test_case_3();
    return 0;
}
