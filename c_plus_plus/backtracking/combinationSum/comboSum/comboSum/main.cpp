// Given an array of integers a and an integer sum, find all of the unique combinations in a that add up to sum.
//
// The same number from a can be used an unlimited number of times in a combination.
//
// Elements in a combination (a1 a2 … ak) must be sorted in non-descending order, while the combinations themselves
// must be sorted in ascending order.
//
// If there are no possible combinations that add up to sum, the output should be the string "Empty".
//
// Example
//
// For a = [2, 3, 5, 9] and sum = 9, the output should be
// combinationSum(a, sum) = "(2 2 2 3)(2 2 5)(3 3 3)(9)".
//
// Input/Output
//
//    [execution time limit] 0.5 seconds (cpp)
//
//    [input] array.integer a
//
//    An array of positive integers.
//
//  Guaranteed constraints:
//    1 ≤ a.length ≤ 12,
//    1 ≤ a[i] ≤ 9.
//
//    [input] integer sum
//
//  Guaranteed constraints:
//    1 ≤ sum ≤ 30.
//
//    [output] string
//        All possible combinations that add up to a given sum, or "Empty" if there are no possible combinations.

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

// Solution

typedef vector<int> iv_t;
typedef vector<iv_t> group_t;



string gen_output(group_t &r) {
   if (r.empty()) return "Empty";
   string output;
   for(int i =0; i<r.size();i++){
      output.push_back('(');
       for (int j=0;j<r[i].size();j++) {
           output.push_back('0' +r[i][j]);
           output.push_back(' ');
       }
       output.pop_back();
      output.push_back(')');
   }

   return output;

}


void solve(iv_t &a, int sum, int index, group_t &r, iv_t &cur, int value){
   if (sum == value) {
      // perfect
      // cout << cur.size() << endl;
      r.push_back(cur);
      return;
   } else if (sum < value + a[index] ) {
      // Busted
      return;
   } else {
      // Add to the party
      // cout << "VAL: " << value << " A: " << a[index] << " S: " << cur.size() << endl;
      for (int i=index; i<a.size();i++) {
          if (a[i] > sum) break;
          cur.push_back(a[i]);
          solve(a, sum, i, r, cur, value  +a[i] );
        //  cout << "B: " << cur.back() << " S: " << cur.size() << endl;
          cur.pop_back();
       //   cout << "A: " << cur.back() << " S: " << cur.size() << endl;
      }
   }
}

std::string combinationSum(std::vector<int> a, int sum) {
   group_t r;
   iv_t cur;
   
   for (int i=0; i<a.size();i++) {
       if (a[i] > sum) break;
       if (a[i] > sum/2 && a[i] < sum ) continue;

       cur.push_back(a[i]);
       solve(a,sum,i, r, cur,a[i]);
       cur.pop_back();
   }
   return gen_output(r);
}

// Tests

void test_case_1(){
    iv_t a = {2, 3, 5, 9};
    int sum = 9;
    string res = combinationSum(a,sum);
    cout << "TC 1: " << res << endl;
    
}

int main(void) {
    test_case_1();


}
