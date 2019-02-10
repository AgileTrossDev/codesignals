// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.


#include<iostream>
#include<vector>
#include <climits>
using std::cout;
using std::endl;
using std::vector;
using std::max;

typedef vector<int> iv_t;



int solve(iv_t &a) {

   int leading = 0;
   int running_sum = 0;
   int max_val = INT_MIN;


   // Loop over entire array once
   while (leading<a.size()) {

      // Starting growing the sum
      while (leading<a.size() && a[leading] >= 0) running_sum = running_sum + a[leading++];

      // Update if we had a lead change
      if(running_sum>0) max_val= max(max_val,running_sum);

      // Handle negative numbers, taking in the account that a single negative number may be the largest value
      while(leading<a.size() && a[leading] <=0) {
          max_val= max(max_val,a[leading]);
          running_sum = running_sum + a[leading++];
      }

      // Reset running sum if the next value is positive and the running sum is negative.
      if (leading<a.size() && running_sum < 0) running_sum = 0;
   }
   return max_val;
}


void tc_2(){

  iv_t a = {-1, -2, -3, -2, -5};
  int res = solve(a);
  cout << "TC 2: " << res << endl;



}

void tc_1() {
  iv_t a = {1, 2, 3, -2, 5};
  int res = solve(a);
  cout << "TC 1: " << res << endl;

}


int main(void) {
   tc_1();
   tc_2();


}
