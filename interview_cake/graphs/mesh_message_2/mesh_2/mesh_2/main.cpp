#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>


using std::vector;
using std::queue;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::stack;

typedef vector<string> row_t;
typedef map<string,row_t> matrix_t;
typedef queue<string> working_t;
typedef map<string,string> tracker_t;
typedef stack<string> reverse_t;


void solve(matrix_t &network,string src, string dest){
   working_t working;
   working.push(src);

   tracker_t tracker;
   tracker[src] = src;

   while(!working.empty()){
       string cur = working.front();
       working.pop();
       if (cur == dest) break;
       for(int i =0;i <network[cur].size();i++){
          string checking = network[cur][i];
          if (tracker.end() == tracker.find(checking)){
              tracker[checking] = cur;
              working.push(checking);
          }
       }    
   }

    
   reverse_t r;
   r.push(dest);

   while(r.top() != src) {
      r.push(tracker[r.top()]);
   }   


   cout << "SOLUTION: ";
   while (!r.empty()) {
       cout << r.top() << " ";
       r.pop();
   }



}


void tc_1() {
  matrix_t network;
    network["Min"]     = {"William", "Jayden", "Omar"};
    network["William"] = {"Min", "Noam"};
    network["Jayden"]  = {"Min", "Amelia", "Ren", "Noam"};
    network["Ren"]     = {"Jayden", "Omar"};
    network["Amelia" ] = {"Jayden", "Adam", "Miguel"};
    network["Adam"]   = { "Amelia", "Miguel", "Sofia", "Lucas"};
    network["Miguel"]  = {"Amelia", "Adam", "Liam", "Nathan"};
    network["Noam"]    = {"Nathan", "Jayden", "William"};
    network["Omar"]    = {"Ren", "Min", "Scott"};
  

 solve(network,"Jayden", "Adam");

}

int main (void) {
    tc_1();

}




