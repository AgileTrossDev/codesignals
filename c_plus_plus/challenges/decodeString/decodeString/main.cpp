//
//  main.cpp
//  decodeString
//
//  Created by Scott Jackson on 12/16/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <string>

std::string gather(std::string &s, int &index) {
    std::string decoded = "";
    
    // Add characters
    while (index <s.length() && isalpha(s[index])) {
        decoded += (s[index]);
        index++;
    }
    
    return decoded;
    
}

int find_num(std::string &s, int &index){
    std::string tmp = "";
    while (index< s.length() && isdigit(s[index])) {
        tmp +=s[index];
        index++;
    }
    return std::stoi(tmp);
}

std::string block(std::string &s, int &index ) {
    std::string decoded = "";
    if (index< s.length() && isdigit(s[index])) {
        int reps = find_num(s,index);
        
        index++; // Accounts for the bracket
        
        std::string tmp = "";
        while ((s[index] != ']')) {
            tmp.append(gather(s,index));
            tmp.append(block(s,index));
        }
        
        for (int i =0; i<reps; i++)
            decoded.append(tmp);
        
        index++; // acount for closing bracket
        return decoded;
        
    }
    return decoded;
}
    
std::string decodeString(std::string s) {
        
        int index =0;
        std::string decoded = gather(s,index);
        //std::cout << "GATHER COMPLETE" << decoded << std::endl;
        while (index <s.length()) {
            decoded.append(block(s,index));
            decoded.append(gather(s,index));
           // std::cout << "GATHER COMPLETE" << decoded <<  " INDEX: " << index <<std::endl;
        }
        return decoded;
}


void test_case_1() {
    std::string input ="4[ab]";
    
    
    std::string res = decodeString(input);
    
    std::cout << "RESULT: " << res << std::endl;
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test_case_1();
    return 0;
}


// abababab
// abababab
