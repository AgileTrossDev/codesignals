//
//  main.cpp
//  longest_path
//
//  Created by Scott Jackson on 12/14/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>


using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::stack;
using std::max;

typedef vector<string> links_t;
typedef map<string,links_t> graph_t;
typedef stack<string> tracker_t;

const char NL = '\n';
const char TAB = '\t';



int find_next(string input, int &index, tracker_t &tracker, int &cur ) {
    //cout << "CALLED: " << index << " |" << input[index]  << "|" << endl;
    
    // Reached end of input search
    if (index >=input.length())
        return 0;
    
    
    // Find the depth of the element
    int tab_count = 0;
    while (index<input.length() && input[index] == TAB) {
        tab_count++;
        index++;
    }
    //cout << "TABS: " << tab_count << " index: " << index << " " << input[index]<< endl;
    
    // Build the next element from input string,
    // marking it if is a string
    string f = "";
    bool is_file = false;
    while (index<input.length() && input[index] != NL ) {
        f += input[index];
        index++;
        if (input[index] == '.') is_file =true;
    }
    if (input[index] == NL) index++;
   // cout << "ELEMENT: " << f << " index: " << index << " " << input[index]<< endl;
    
    // Pop elements from stack that are not
    // parents to new elements
    while (tracker.size()> 0 && tab_count < tracker.size()) {
        //cout << "POPPING " << tab_count << " " << tracker.size() <<  endl;
        cur = cur - (int)tracker.top().length();
        tracker.pop();
    }
    
    // IF we found a file, then return
    // it's length, else the element
    // is a folder, so push it on
    // to the stack
    if (is_file) {
        //cout << "FILE FOUND " << endl;
        return cur + (int)f.length() + (int) tracker.size();
    } else {
        cur = cur + (int)f.length();
        tracker.push(f);
    }
    
    // Haven't found a file yet and still more
    // to search, so continue
    return  find_next(input, index, tracker, cur );
    
}

int longestPath(string input) {
    int ret = 0;
    
    int index = 0;
    int cur = 0;
    tracker_t tracker;
    
    // Loop through input, looking for the next file,
    // and then track the maximum length of the paths
    // found in the input
    while (index < input.length()){
        ret = max(ret, find_next(input,index,tracker, cur));
        //cout << "CURRENT MAX: "<< ret << endl;
    }
    
    return ret;
   
}

bool test_case_0() {
    string s = "user\n\tpictures.text";
    int blah =longestPath(s);
    cout << "LONGEST PATH = " << blah << endl;
    
    return false;
}


bool test_case_1() {
    string s = "user\n\tpictures\n\t\tphoto.png\n\t\tcamera\n\tdocuments\n\t\tlectures\n\t\t\tnotes.txt";
    int blah =longestPath(s);
    cout << "LONGEST PATH = " << blah << endl;
    
    return false;
}


bool test_case_2() {
    string s = "user\n\tpictures\n\tdocuments\n\t\tnotes.txt";
    int blah =longestPath(s);
    cout << "LONGEST PATH = " << blah << endl;
    
    return false;
    
}

bool test_case_3() {
    string s = "a";
    int blah =longestPath(s);
    cout << "LONGEST PATH = " << blah << endl;
    
    return false;
    
}



int main(int argc, const char * argv[]) {
    test_case_0();
    test_case_1();
    test_case_2();
    test_case_3();
    return 0;
}

/*
 
 void disp_graph( graph_t &g) {
 cout << "DISPLAYING GRAPH..." << endl;
 
 for ( graph_t::iterator it = g.begin(); it != g.end(); it++ ) {
 cout << "KEY: " << it->first << " || ";
 for (int i=0;i<it->second.size();i++)
 cout << " " << it->second[i];
 
 cout << endl;
 }
 }
 
 void disp_roots(links_t &roots) {
 cout << "ROOTS: ";
 for (int i = 0; i<roots.size();i++)
 cout << roots[i] << " ";
 
 cout << endl;
 
 }
 
 
 TRY #2
 
 
 void test_case_2() {
 
 graph_t g;
 links_t roots;
 
 string s = "user\n\tpictures\n\t\tphoto.png\n\t\tcamera\n\tdocuments\n\t\tlectures\n\t\t\tnotes.txt";
 build_graph(s,g,roots);
 disp_graph(g);
 disp_roots(roots);
 
 
 }
 
 void test_case_1_build_graph() {
 
 graph_t g;
 links_t roots;
 
 string s = "user\n\tpictures\n\t\tphoto.png\n\t\tcamera\n\tdocuments\n\t\tlectures\n\t\t\tnotes.txt";
 int blah =longestPath(s);
 cout << "LONGEST PATH = " << blah << endl;
 
 
 }
 
 void build_graph(string s, graph_t &g, links_t &roots) {
 int i =0;
 
 tracker_t current_key;
 
 while (i<s.length()) {
 
 // Find element depth
 int tab_count = 0;
 while (i<s.length() && s[i] == TAB) {
 tab_count++;
 i++;
 }
 
 // Build element string
 string f = "";
 while (i<s.length() && s[i] != NL ) {
 f += s[i];
 i++;
 }
 
 // Find the right parent key
 while (current_key.size() > (tab_count))
 current_key.pop();
 
 //cout << "NEW ELEMENT: " << f  << "|| at Depth: " << tab_count << endl;
 
 if(!current_key.empty()) {
 graph_t::iterator it = g.find(current_key.top());
 if (it != g.end()) {
 //cout << "FOUND PARENT: " <<  it->first << " ->" << f << endl;
 it->second.push_back(f);
 }
 } else {
 // Root
 //cout << "FOUND ROOT" << endl;
 roots.push_back(f);
 }
 
 links_t c;
 g.insert(make_pair(f,c));
 
 current_key.push(f);
 i++;
 
 }
 
 }
 
 
 int traverse(string root, graph_t & graph ) {
 
 int ret_val = (int)root.length()+1;
 int cur = (int)root.length()+1;
 
 for (int i=0;i<graph[root].size();i++)
 ret_val = max(ret_val, cur + traverse(graph[root][i], graph));
 
 cout << "ROOT: " << root << " " << ret_val << endl;
 return ret_val;
 }
 
 
 
 int max_length(links_t &roots,graph_t &graph) {
 int ret_val=0;
 
 for (int i = 0; i<roots.size();i++)
 ret_val = max(ret_val,traverse(roots[i],graph));
 
 return ret_val-1;
 }
 
 
 int longestPath(string fileSystem) {
 
 graph_t graph;
 links_t roots;
 
 build_graph(fileSystem,graph,roots);
 return max_length(roots,graph);
 }

 */



/*
 
 
 TRY #1
 
 const char SL = '\\';
 const char CR = 'r';
 const char TAB = 't';
 const char EXT = '.';
 const bool FILE = true;
 const bool DIR = false;
 
 int dive (std::string & fileSystem, int & start, int curr_len=0, int depth=-1) {
 // Assumes start indexes the start of a new element does not start
 // Carraige Returns, These would have already been processed in last round
 //
 // fileSystems - string containing the entire listing
 // start - location of next element to be processed.
 // curr_len - Entire parent path length ,including all elements above with '/'
 // depth - Represents how deep the file structure is nested.
 //
 // RETURNS maximum length for a path to a file in current and all sub-directories
 int ret_val = 0;
 bool loop = true;
 int index =start;
 
 // Loop until we can't.  Either we hit the end of the string
 // or loop is set to exit because we hit the end of a sub-directory
 while (loop && (index < fileSystem.length())) {
 
 // Find next element by traversing string until a carraige return.
 // If we encounter a file, then we mark it. We also count the tabs
 // associated with this element.
 int tabs = 0;
 bool type = DIR;
 while ((fileSystem[index] != SL || fileSystem[index+1] != CR) && index< fileSystem.size()) {
 if (fileSystem[index] == EXT) type = FILE;
 if (fileSystem[index] == SL && fileSystem[index+1] == TAB) tabs++;
 index++;
 }
 
 cout << start << " "  <<  index << " "  <<  type  << " "<<  endl;
 
 // 0-based, subtract out the tabs to get the element length
 int element_length = index -start -tabs*2;
 cout << "ELEMENT: " << index << " " << element_length << "+" << curr_len <<endl;
 
 // Move index passed the CR, so that it points at next element
 index++;
 index++;
 
 // Update Start to point to next element to process
 // NOTE: This will be returned due to pass by reference
 start = index;
 
 if (type == DIR) {
 cout<<"DIR"<<endl;
 if (tabs > depth){
 // Dive into next sub-directory
 ret_val = std::max(ret_val,dive(fileSystem,index,curr_len+element_length+1,tabs+1));
 //else  if (tabs <= depth){
 // Start processing sibling directory at this depth
 //ret_val = std::max(ret_val,dive(fileSystem,index,curr_len+element_length,(depth)));
 } else {
 // Element is not a sub-directory so stop loop,
 // and return to caller.
 //
 // NOTE: start was updated to point to next element and it was passed-by-ref
 loop =false;
 }
 
 } else {
 // FILE: Check path length
 cout << "PATH: " << (curr_len+ 1 +element_length) << endl;
 ret_val = std::max(ret_val,((curr_len+ 1 +element_length)));
 }
 
 }
 return ret_val;
 }
 
 int longestPath(std::string fileSystem) {
 int start =0;
 cout << fileSystem << endl;
 return  dive(fileSystem,start);
 
 }
 */
