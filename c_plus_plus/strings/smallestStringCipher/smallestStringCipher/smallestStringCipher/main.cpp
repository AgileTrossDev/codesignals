//
//  main.cpp
//  smallestStringCipher
//
//  Created by Scott Jackson on 2/9/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

using std::string;
using std::cout;
using std::endl;


// ### SOLUTION ###

std::string theSmallestStringCipher(std::string key, std::string message) {
    
    int a =0;
    int b =0;
    string result = "";
    while (a < key.length() || b < message.length()) {
        
        // Next Key char is less than next Message Char or Message has been used
        while ((b >=message.length() &&  a  < key.length()) || (a < key.length() && key[a] < message[b]) ) {
            result.push_back(key[a]);
            cout << "ADDED FROM KEY" << " "  << key[a]<< endl;
            a++;
            
        }
        
        // Next Message char is less than next Key Char or Key has been used.
        while ( (b <message.length() && a >=key.length()) || (b < message.length() && key[a] > message[b]) ) {
            result.push_back(message[b]);
            cout << "ADDED FROM MESSAGE" << " "  << message[b]<< endl;
            b++;
            
        }
        
        
        
        // Now handle while they are equal
        int i =a;
        int j =b;
        
        while (a < key.length() && b < message.length() && key[a] == message[b]) {
            while (i < key.length() && j < message.length() && key[i] == message[j]) {
                i++;
                j++;
            }
            if ( i == key.length() ){
                result.push_back(message[b]);
                b++;
            } else if (j == message.length()) {
                result.push_back(key[a]);
                a++;
            } else if (key[i] <message[j]) {
                result.push_back(key[a]);
                a++;
            } else{
                result.push_back(message[b]);
                b++;
            }
        }
        
    }
    //cout << "KEY: " << key.length() << " "<<  a << " | " << message.length() << " " << b << endl;
    return result;
}


// ### Tests ###


void tc_3() {
    string a = "zswrmvwydkgvfbmbwfhl";
    string b = "uzreoxzxhufwdplhxacb";
    string exp ="uzreoxzswrmvwydkgvfbmbwfhlzxhufwdplhxacb";
    
    
    string res = theSmallestStringCipher(a,b);
    
    cout << "TC 3: " << (res==exp)  << " " << res<< endl;
}

void tc_2() {
    string a = "cbede";
    string b = "cbede";
    string exp ="cbcbededee";
    
    string res = theSmallestStringCipher(a,b);
    
    cout << "TC 2: " << (res==exp)  << " " << res<< endl;
}

void tc_1() {
    string a = "gdmz";
    string b = "hello";
    string exp ="gdhellmoz";
    
    string res = theSmallestStringCipher(a,b);
    
    cout << "TC 1: " << (res==exp)  << " " << res<< endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    tc_2();
    tc_3();
    return 0;
}
