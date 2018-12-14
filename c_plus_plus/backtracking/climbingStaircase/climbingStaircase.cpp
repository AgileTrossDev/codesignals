// You need to climb a staircase that has n steps, and you decide to get some extra
// exercise by jumping up the steps. You can cover at most k steps in a single jump.
// Return all the possible sequences of jumps that you could take to climb the staircase,
// sorted.
// 
// Example
// 
// For n = 4 and k = 2, the output should be
// 
// climbingStaircase(n, k) =
// [[1, 1, 1, 1],
//  [1, 1, 2],
//  [1, 2, 1],
//  [2, 1, 1],
//  [2, 2]]
// 
// There are 4 steps in the staircase, and you can jump up 2 or fewer steps at a time.
// There are 5 potential sequences in which you jump up the stairs either 2 or 1 at a
// time.
// 
// Input/Output
// 
//     [time limit] 500ms (cpp)
// 
//     [input] integer n
// 
//     Guaranteed constraints:
//     0 ≤ n ≤ 10.
// 
//     [input] integer k
// 
//     Guaranteed constraints:
//     0 ≤ k ≤ n.
// 
//     [output] array.array.integer
// 
//     An array containing all of the possible sequences in which you could climb
//     n steps by taking them k or fewer at a time.
// 
// [C++] Syntax Tips
// 
// //  Prints help message to the console
// //  Returns a string
// std::string helloWorld(std::string name) {
//     std::cout << "This prints to the console when you Run Tests" << std::endl;
//     return "Hello, " + name;
// }

#include<iostream>
#include<utility>
#include <vector>
#include <stack>
#include <algorithm>    // std::sort


using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

typedef std::vector<int> jumps_t;
typedef std::vector<jumps_t> result_t;
typedef pair<int,std::vector<int> > state_t;
typedef std::stack<state_t> states_t;

//-------------------------------------------------------------------------------
// Helpers
//-------------------------------------------------------------------------------
void disp (state_t & state) {
  cout << "HOPS" << state.first << " | ";
  
  for (int i =0;i<state.second.size();++i) {
   cout << state.second[i] << " ";
  }
  
  cout << endl;
  
}


//-------------------------------------------------------------------------------
// Solution
//
// Initial state: Empty vector of ints representing the jumps taken
// The decision: How many jumps out of k will I take.
// Rejection criterion: 0 steps allowed or sum of jumps is greater than n
//-------------------------------------------------------------------------------

bool jump_compare (result_t &i,result_t &j) {
  
  for (int index =0; index<i.size();++index) {
    if (i[index] != j[index])
      return (i[index] <j[index]);
    
  

  }
  return false;
}

std::vector<std::vector<int> > climbingStaircase(int n, int k) {
  // An array containing all of the possible sequences in which you could climb
  // n steps by taking them k or fewer at a time.
  
  
  // Contains all successful states
  result_t result;
  
  // Stack containing all states still being worked to success or failure
  states_t the_states;
  
  {
    jumps_t init_jump_state;
    the_states.push(make_pair(n,init_jump_state));  
  }
  
  // Loop until all States have been worked to completion
  while(!the_states.empty()) {
    
    // Work next state 
    state_t working_state = the_states.top();
    the_states.pop();
    
    for (int i=k;i>=1;--i) {
      //cout << "Checking (" << n << ") " << (working_state.first ) <<" - " << (i) << " = "  <<(working_state.first -i) << endl;
      if (0==(working_state.first -i)) {
        // Found successful state
        
        jumps_t tmp = working_state.second;
        tmp.push_back(i);
        result.push_back(tmp);
        
      } else if (0< (working_state.first -i)) {
        // Still have room to make decisions with this state,
        // so update it and put it back on the stack
        state_t tmp = working_state;
        tmp.second.push_back(i);
        tmp.first = working_state.first-i;
        the_states.push(tmp);
      } else {
        // Invalid State, no action
        //state_t tmp = working_state;
        //tmp.second.push_back(i);
        //tmp.first = working_state.first-i;
        //disp(tmp);
      }
      
    }
    
  }
  
  // Sorts results
   std::sort (result.begin(), result.end(), [](const jumps_t &i,const jumps_t &j){
  for (int index =0; index<i.size();++index) {
    if (i[index] != j[index])
      return (i[index] <j[index]);
  }
  return false;
});
  
  
  return result;
  
}



//-------------------------------------------------------------------------------
// Main
//-------------------------------------------------------------------------------
int main (void) {
  
  
}