#include <iostream>
#include <stack>
#include <vector>


using std::cout;
using std::endl;
using std::vector;
using std::stack;

typedef vector<int> input_t;
typedef vector<int> result_t;
typedef stack<int> worker_t;

void process(input_t &i, result_t &r) {
   worker_t s;


   // Push the first element on to stack
   s.push(0);
  
   for (size_t index= 1;index<r.size();index++){

      // Get next current
      int cur = i[index];

      // Set largest element to current for items in queue.
      while (!s.empty() && i[s.top()] < cur){


          /// Found next element
          r[s.top()] = cur;
          s.pop();
 
       }
      s.push(index);
    }

    while (!s.empty()){
         r[s.top()] = -1;
         s.pop();
    }
}



void disp_result(input_t &i, result_t &r) {

   cout << "INPUT: ";
   for(input_t::iterator itr = i.begin(); itr != i.end();itr++)
     cout << (*itr )<< " ";


   cout << endl;


   cout << "RESULT: ";


   for(result_t::iterator itr = r.begin(); itr != r.end();itr++)
     cout << (*itr )<< " ";

   cout << endl;
}


bool test_case_1() {
    input_t i = {1, 3, 2, 4 };
    result_t r (4,-1);

    process(i,r);
    disp_result(i,r);

    return true;

}
 
int main (void) {
  bool res = test_case_1();
  cout << "TC 1: " <<res << endl;

}
