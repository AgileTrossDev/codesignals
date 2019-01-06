//
//  main.cpp
//  simplifyPath
//
//  Created by Scott Jackson on 12/28/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//
#include <iostream>
#include <stack>

using std::cout;
using std::endl;

std::string build_string(std::stack<std::string> &tracker) {
    std::string ret = "";
    cout << "tracker size: " << tracker.size() << endl;
    while (!tracker.empty()) {
        ret.insert(0, tracker.top());
        tracker.pop();
    }
    return ret;
}

std::string simplifyPath(std::string path) {
    
    std::stack<std::string> tracker;
    int index =0;
    
    // Clear up leading '/'
    while (path[index] != '/') { index++; }
    
    // Make sure path starts with '/'
    tracker.push("/");
    
    while (index < path.length()) {
        
        // Handle '/'
        if (index < path.size() && path[index] == '/') {
            if (tracker.top() != "/") tracker.push("/");
            index++;
        }
        while (index < path.size() && path[index] == '/') { index++; }
        // index should be pointing to next char after fina '/'
        // and stack should include a single '/'
        
        
        if (index < path.size() && path[index] == '.') {
             index++;
             if (index < path.size() && path[index] == '.') {
                 tracker.pop();
                 cout << "t: " << tracker.empty() <<  endl;
                 
                 if (tracker.empty()) {
                     cout <<"PUSHING" << endl;
                     tracker.push("/");
                 } else {
                     cout << "POPPPING " << endl;
                     tracker.pop();
                 }
                 index++;
             }
             // At this point we are either ignoring
            // a single '.' or we popped the recent
            // directory  and following '/' if there
            // are '..' Index should point to a '/',
            // so continue loop from top to handle
            // that directory.
             continue;
         }
        
        
        // Procesing an actual directory namee,
        // collect all characters until we find
        // a '/' or the ennd of the string.
        std::string dir_name = "";
        while (index < path.size() && path[index] != '/') {
              //dir_name.append(path[index]);
              dir_name = dir_name + path[index];
              index++;
        }
        //cout << "ADDING: " << dir_name << endl;
        if (dir_name != "") tracker.push(dir_name);
        
    }
    
    
    
    if (tracker.size() > 1 && tracker.top() == "/") tracker.pop();
    return build_string(tracker);
}

void exec_test_case(std::string input, std::string expected, int tc) {
    std::string  res =  simplifyPath(input);
    if (! (expected ==res)) {
        cout << "TEST CASE "<< tc << ": FAILED" << endl;
        cout << "I: " << input << endl;
        cout <<"R: " << res << endl;
        cout << "E: "  << expected << endl;
    } else {
        cout << "TEST CASE " << tc << ": PASSED" << endl;
    }
    
}

void test_case_1() {
    
    std::string input = "/home/a/./x/../b//c/";
    std::string expected = "/home/a/b/c";
    exec_test_case(input,expected,1);
    
}

void test_case_3() {
    
    std::string input = "/../";
    std::string expected = "/";
    exec_test_case(input,expected,3);
    
    
    
}
void test_case_18() {
    
    std::string input = "a/b/../c/d/../../e/../../a/";
    std::string expected = "/a";
    exec_test_case(input,expected,18);
    
}







int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //test_case_1();
    test_case_3();
    //test_case_18();
    return 0;
}
