#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::make_pair;
using std::pair;
using std::queue;

typedef  unordered_map<char,int> look_up_t;

// Create look-up table by looping over the set of characters
// that form valid sub-strings.  The Look-up table tells
// us what characters we are still looking for.  It counts
// the number of occurences of a character in the set.
void create_look_up (look_up_t &lu, vector<char>& set) {
	
	for (int i=0;i<set.size();++i) { 
   std::unordered_map<char,int>::iterator got = lu.find (set[i]);
	 
   if (got == lu.end()){
   	lu.insert(make_pair<char,int>(set[i],0));
   } else {
     got->second = (got->second) + 1;
   }
  }
}

bool still_looking(look_up_t &lu, char c) {
	bool ret_val =false;
	std::unordered_map<char,int>::iterator got = lu.find (c);
   if (got == lu.end() ||  got->second  == 0 ){
			// Not in look-up table or we have already found all the characters
   } else {
     ret_val = true;
   }
	 
	 return ret_val;
 
}

void decrement_lu (look_up_t &lu, char c) {
	
	std::unordered_map<char,int>::iterator got = lu.find (c);
   if (got == lu.end()  ){
			// Not in look-up table or we have already found all the characters
   } else {
      got->second  =   got->second  -1;
   }
	 
	
}

int smallest_sub_string (string input, vector<char> set) {
  int delta = -1;

  // Create look-up table
  look_up_t lu;
	create_look_up(lu,set);
  
  // Loop over input
  int index =0, start= 0, tail =0;
  queue<pair<char,int> > tracker;
  bool found = false;
  while (index<input.size() && !found) {
		
			// Fast forward over duplicates.
			// TODO: Rewind last element of smallest sub-string
			while (input[i] == input[i+1]) i++;
  
      // Check if char is still in lu.
			if (still_looking(lu, input[i])) {
				tracker.push(input[i]);
				decrement_lu(lu, input[i]);
				tail = i;
			}
			
      // Check if complete sub-string has been found
			if (tracker.size() == set.size()) found = true.;
    }
  } 

  
	if (found) {
		// We found a complete sub-string
		start = queue.front.second;
		delta = tail -start;
		
		// Now attempt to improve upon the size of the sub-string.
    // Pop First element in tracker
    // Attempt to find popped element.

  }


  return delta;


}


int main (void) {
  cout << "START" << endl;


  cout << "END" << endl;



}
