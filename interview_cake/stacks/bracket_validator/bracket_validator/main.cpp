//
//  main.cpp
//  bracket_validator
//
//  Created by Scott Jackson on 3/16/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <stack>


using std::stack;
using std::string;



bool is_openner(char c) {
    
    return   (c=='(' || c=='{' || c=='[' );
}

bool is_closer(char c) {
    
    return  (c==')' || c=='}' || c==']' );
}

bool is_matched(char x, char j) {
    return ( (x =='(' && j ==')') ||
            (x == '{' && j == '}') ||
            (x== '[' && j ==']'));
    
    
}



bool isValid(const string& code)
{
    // determine if the input code is valid
    stack<char> tracker;
    
    size_t index =0;
    while( index<code.length() ) {
        
        while (index<code.length() && !is_openner(code[index]) && !is_closer(code[index]))
            index++;
        
        if (index <code.length() && is_openner(code[index])) {
            
            tracker.push(code[index++]);
        }
        
        if (index<code.length() && is_closer(code[index])) {
            
            if (!is_matched(tracker.top(), code[index])) return false;
            
            tracker.pop();
            index++;
            
        }
    }
    
    return tracker.empty();
}





int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
