/*
* Kadane's Algorithm - Simple Dynamic recursion algorithm to find
* the smallest sub-array, by traversing the data set and tracking
* what is larger, the current sub-array, or next element.  It is
* dynamic in that it solves for the largest sub-array at N, and
* then N1, then N2, etc to cover the entire data set. 
*
*
*/


#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;


typedef vector<int> data_t;

int find_largest_sub_array(data_t &d) {
  int best = 0;
  int current = 0;
  for (int i = 0; i < d.size(); i++) {
     current = max(d[i], current + d[i]);
     best = max(current, best);

  }

  return best;
}


int main(void) {
  data_t d = {1,2,3,-4,-5,10 };
  cout << "RESULT = " << find_largest_sub_array(d) << endl;
}
