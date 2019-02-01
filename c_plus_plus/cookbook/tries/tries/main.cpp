#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <set>

#define nullptr 0

using std::vector;
using std::set;
using std::string;
using std::find;
using std::find_if;
using std::cout;
using std::endl;
using std::map;

struct Node;

typedef vector<std::vector<int> > obj_t;
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
       cout << "ADDING WORD: " << word << "(" << val << ")" << endl;
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
    cout << "wrd:" << wrd << " index: " << index << " -> " << wrd[index] << " TYPOS: " << typos << " " << val << " " << so_Far << endl;
   
    if (allowed<typos) return;
    if(index == wrd.size()) {
        find_words(tracker);
    }
    
    for (child_t::iterator i = children.begin(); i != children.end(); i++) {
        if (tolower(wrd[index]) == i->first)
            i->second->find_matches( wrd, tracker,  allowed, typos, index+1, so_Far);
        else if (tolower(wrd[index+1]) == i->first)
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


Node * build_dict(names_t names) {
    Node * root = new Node ('*');

    for(int i =0; i< names.size(); i++) {
        add_to_dictionary(root, names[i], i);
    }
    return root;
}


//--------------------------------------------------------------------------------------
// Test Cases
//--------------------------------------------------------------------------------------
void disp_t(tracker_t &tracker, names_t names) {
 for (tracker_t::iterator i= tracker.begin() ;i != tracker.end();i++) {
       int tmp = *i;
       cout << tmp << ". " << names[tmp] << endl;
   }
}


void test_case_9() {
    cout << "\n\nTEST CASE 9:" << endl;
    names_t names =  {  "loocationnnn",
        "lcationaaaa"};
    
    Node * root = build_dict(names);
    disp_tries(root);
    
    tracker_t tracker;
    root->find_matches("Location",tracker);
    cout <<"TRACKER: " << tracker.size() << endl;
    disp_t(tracker,names);
}


void test_case_8() {
    cout << "\n\nTEST CASE 8:" << endl;
    names_t names =  {  "Bat building",
        "Cats exhibition",
        "Cramp",
        "cat avenue"};
    
    Node * root = build_dict(names);
    //  disp_tries(root);
    
    tracker_t tracker;
    root->find_matches("cat",tracker);
    cout <<"TRACKER: " << tracker.size() << endl;
    disp_t(tracker,names);
}


void test_case_7() {
    cout << "\n\nTEST CASE 7:" << endl;
    names_t names =  {  "Cramp" };
    Node * root = build_dict(names);
    //  disp_tries(root);
    
    tracker_t tracker;
    root->find_matches("cat",tracker);
    cout <<"TRACKER: " << tracker.size() << endl;
    disp_t(tracker,names);
}

void test_case_6() {
    cout << "\n\nTEST CASE 6:" << endl;
    names_t names =  {  "Ramble On Rose" };
    Node * root = build_dict(names);
    //  disp_tries(root);
    
    tracker_t tracker;
    root->find_matches("cat",tracker);
    disp_t(tracker,names);
}

void test_case_5() {
    cout << "\n\nTEST CASE 5:" << endl;
    names_t names =  {  "At street" };
    Node * root = build_dict(names);
    //  disp_tries(root);
    
    tracker_t tracker;
    root->find_matches("cat",tracker);
    disp_t(tracker,names);
}


void test_case_4() {
    cout << "\n\nTEST CASE 4:" << endl;
    names_t names =  {  "Bat building" };
    Node * root = build_dict(names);
    //  disp_tries(root);
    
    tracker_t tracker;
    root->find_matches("cat",tracker);
    disp_t(tracker,names);
}


void test_case_3() {
  cout << "\n\nTEST CASE 3:" << endl;
  names_t names =  {  "Bat building",
                      "Cast exhibition",
                      "At street",
                      "Cat avenue",
                      "The Phish",
                      "Ramble On Rose"};
  Node * root = build_dict(names);
//  disp_tries(root);

  tracker_t tracker;
  root->find_matches("cat",tracker);
  disp_t(tracker,names);
}


void test_case_2() {
  names_t names =  {  "Bat building",
                      "Cast exhibition",
                      "At street",
                      "Cat avenue"};
  Node * root = build_dict(names);

  tracker_t tracker;
  root->find_words(tracker);
  disp_t(tracker, names);

  cout << "RESULT: " << root->is_valid("At street") << endl;
  cout << "RESULT: " << root->is_valid("ATSTREET") << endl;
}

void test_case_1() {
  names_t names =  {  "Bat building",
                      "Cast exhibition",
                      "At street",
                      "Cat avenue"};
  Node * root = build_dict(names);
  disp_tries(root);

}
//----------------------------------------------------------------------------------------
// Main
//----------------------------------------------------------------------------------------
int main(void) {
   //test_case_1();
   //test_case_2();
    //test_case_3();
    //test_case_4();
    //test_case_5();
    //test_case_6();
     //test_case_7();
    // test_case_8();
    test_case_9();

}
