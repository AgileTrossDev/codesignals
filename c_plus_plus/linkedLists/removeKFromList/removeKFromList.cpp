// Note: Try to solve this task in O(n) time using O(1) additional space, where 
// n is the number of elements in the list, since this is what you'll be asked
// to do during an interview.
//
// Given a singly linked list of integers l and an integer k, remove all
// elements from list l that have a value equal to k.
//
// Example
//
//    For l = [3, 1, 2, 3, 4, 5] and k = 3, the output should be
//    removeKFromList(l, k) = [1, 2, 4, 5];
//    For l = [1, 2, 3, 4, 5, 6, 7] and k = 10, the output should be
//    removeKFromList(l, k) = [1, 2, 3, 4, 5, 6, 7].
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
//    0 ≤ list size ≤ 105,
//    -1000 ≤ element value ≤ 1000.
//
//    [input] integer k
//
//    An integer.
//
//    Guaranteed constraints:
//    -1000 ≤ k ≤ 1000.
//
//    [output] linkedlist.integer
//
//    Return l with all the values equal to k removed.



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


void disp(ListNode<int> *start);


ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
  ListNode<int> *trailing_index = l;
  ListNode<int> * index=l;
  
  // Remove any at start of list
  while (index && index->value == k){
      trailing_index = index;
      index =index->next;   
      delete trailing_index;
  }// Index now points at next good value
    
  
  if (index != l ) {
    // start of list has changed
    // so adjust
    l = index;
    trailing_index = l;
  }


    
  while (index !=0) {
    // Remove any at this point in this list
    while (index && index->value == k){      
      ListNode<int> * delete_me = index;
      index =index->next;
      delete delete_me;
    }

    // Index now points at next good value
    // or at the end of the list if anything
    // had been removed
    if (index != trailing_index  && index != trailing_index->next) {
      // Segment of list was removed, so reconnect
      // and move trailing index forward      
      trailing_index->next = index;
           
    } // else end of the list, so we are done
  
    trailing_index = index;
    if (index) index = index->next;    

  }

  return l;
}


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



int main(void) {
  
  {
  
  int a[] =  {3, 1, 2, 3, 4, 5};
  ListNode<int> * input = init(a,6);
  disp(input);
  input = removeKFromList(input,3);
  disp(input);
  

  }
}
