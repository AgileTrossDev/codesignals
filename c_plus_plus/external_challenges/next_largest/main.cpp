// O(N) Algorithm to find the next largest number in array/vector.
//
// It utlitizes a stack to match next largest element.
// The stack tracks unmatched elements by their index.
//
// We start with pushing index 0 on to the stack,
// and then iterate through the vector attempting
// to find the next largest element. 
//
// During the iteration, if an element is smaller,
// then the current element trying to be matched,
// we then stick that element on the stack and try
// to then find the next element larger then that 
// element.   
//
// Once we find an element larger than the top of
// the stack, we pop the stack and set result 
// for that element location.  We continue 
// to set the result of next element in the stack if 
// the current indexed value is the larger than the 
// top of the stack.
//
// Once we looped through all elements, we finish
// off the results by popping the stack and setting
// all to -1/invalid. 
//
// Big (N) because loop through input once, placing the 
// value onto the stack and then processing the stack.
// So we traverse N twice.
//
//
// Applying this solution to the future....
// Draw out how I would manually solve phyical representation 
// of answer.  This might look like leader/follower index, which
// vary well might be a simpler solution, but notice how
// when the leader passes over element to be later processed,
// it is sort of like placing them on the stack.


#include<iostream>
#include<vector>
#include<stack>


using std::cout;
using std::endl;
using std::stack;
using std::vector;


typedef vector<int> input_t;
typedef vector<int> tracker_t;
typedef stack<int> worker_t;



tracker_t process(input_t &input) {

  tracker_t tracker(input.size(),-1);
  worker_t worker;


  worker.push(0);
  for (int i = 0; i<input.size();i++) {
    int cur = input[i];
   
    while (!worker.empty() && cur > input[worker.top()]) {
      tracker[worker.top()] = input[i];
      worker.pop();

    } 
    worker.push(i);
 

  }

  while ( !worker.empty()) {
    tracker[worker.top()] = -1;
    worker.pop();
  }


  return tracker;
}



void disp(input_t &i) {
  for (input_t::iterator itr = i.begin(); itr != i.end(); itr++) 
    cout << *itr << " ";

  cout << endl;

}


int main(void) {
   vector<vector<int> > inputs ={ {1,3,4,-5,5},
                               {5,4,3,2,1},
                               {1,5,3,1,6,9,11,2,22}
                              };

   for (size_t i =0; i<inputs.size();i++) {
     tracker_t output = process(inputs[i]);
     cout << "INPUT: " ;
     disp(inputs[i]);

     cout << "OUTPUT: ";
     disp(output);
   }

}
