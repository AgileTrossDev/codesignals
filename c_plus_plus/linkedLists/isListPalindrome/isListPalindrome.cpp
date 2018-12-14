 // Note: Try to solve this task in O(n) time using O(1) additional space, where
 // in is the number of elements in l, since this is what you'll be asked to do
 // during an interview.
 //
 // Given a singly linked list of integers, determine whether or not it's a
 // palindrome.
 //
 // Example
 //
 //    For l = [0, 1, 0], the output should be
 //    isListPalindrome(l) = true;
 //    For l = [1, 2, 2, 3], the output should be
 //    isListPalindrome(l) = false.
 //
 // Input/Output
 //
 //    [time limit] 500ms (cpp)
 //
 //    [input] linkedlist.integer l
 //
 //    A singly linked list of integers.
 //
 //    Guaranteed constraints:
 //    0 ≤ list size ≤ 5 · 105,
 //    -109 ≤ element value ≤ 109.
 //
 //    [output] boolean
 //
 //    Return true if l is a palindrome, otherwise return false.

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };


#include <cstddef>
#include <iostream>
using std::cout;
using std::endl;

// Definition for singly-linked list:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(0) {}
   T value;
   ListNode *next;
};



// As we go deeper we increment index to the right, as bubble back up
// we move start to the right
bool recurse(ListNode<int>   * & start, ListNode<int> * index) {
  
   bool ret_val = true;
  if (0 != index) {    
    
    // Not at bottom, so increment index to left and recuse
    ret_val = recurse(start,index->next);
  
   // all nodes deeper have been compared and start has been slid to the right,
   // we should be comparing mirroring sides at this point
    ret_val = ret_val && (start->value == index->value);
    
    // Slide start to right before we bubble up, so that next comparison
    // is ready to go.
    start = start->next;
  } else {
    // bottom hit, so compare start and index, increment start
    // and return comparison result    
  }
  
 
  // Return Ret Val
  return ret_val; 
  
}

//------------------------------------------------------------------------------
// Problem
//------------------------------------------------------------------------------
bool isListPalindrome(ListNode<int> * l) {

  return recurse(l,l);
}


//------------------------------------------------------------------------------
// Helpers
//------------------------------------------------------------------------------
ListNode<int> * init(int a[], int size) {
  ListNode<int> * start = new ListNode<int>(a[0]);
  ListNode<int> * index = start;
  for (int i= 1;i<size;++i) {
    index->next = new ListNode<int>(a[i]);
    index =index->next;
  }
  
  
  return start;
  
}

void disp(ListNode<int> *start) {
  while (start) {
    cout << start->value << " ";
    start = start->next;
  }
  cout << endl;
  
}


//------------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------------
int main(void) {
  
  
  // Test Case 1
  {
  
    int a[] =  {3, 1, 2, 3, 4, 5};
    ListNode<int> * input = init(a,6);
    disp(input);
    bool result = isListPalindrome(input);
    cout << "TEST CASE 1: " << result << endl;
  

  }
  
    // Test Case 2
  {
  
    int a[] =  {0, 1,1, 0};
    ListNode<int> * input = init(a,4);
    disp(input);
    bool result = isListPalindrome(input);
    cout << "TEST CASE 2: " << result << endl;
  

  }
  
  // Test Case 3
  {
  
    int a[] =  {0, 1, 0};
    ListNode<int> * input = init(a,3);
    disp(input);
    bool result = isListPalindrome(input);
    cout << "TEST CASE 2: " << result << endl;
  

  }
  
}

