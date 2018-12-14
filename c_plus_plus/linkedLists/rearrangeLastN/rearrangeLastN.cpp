 // Note: Try to solve this task in O(list size) time using O(1)
 // additional space, since this is what you'll be asked during an interview.
 //
 // Given a singly linked list of integers l and a non-negative integer n,
 // move the last n list nodes to the beginning of the linked list.
 //
 //Example
 //
 //    For l = [1, 2, 3, 4, 5] and n = 3, the output should be
 //    rearrangeLastN(l, n) = [3, 4, 5, 1, 2];
 //
 //    For l = [1, 2, 3, 4, 5, 6, 7] and n = 1, the output should be
 //    rearrangeLastN(l, n) = [7, 1, 2, 3, 4, 5, 6].
 //
 //Input/Output
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
 //    [input] integer n
 //
 //    A non-negative integer.
 //
 //    Guaranteed constraints:
 //    0 ≤ n ≤ list size.
 //
 //    [output] linkedlist.integer
 //
 //    Return l with the n last elements moved to the beginning.
 //
// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//


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

//------------------------------------------------------------------------------
// Solution
//------------------------------------------------------------------------------
ListNode<int> * fast_fwd(ListNode<int> * index,int n) {
	while (index && (--n)>0) index = index->next;

        // NOTE: assumed that n will be equal to or less 
        // than list size, but we might be looking for
        // node beyond end. If that is the case we return
        // 0;
	return index;
}

ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
   ListNode<int> * fwd = fast_fwd(l,n+1);
   ListNode<int> * trail=l;

   // N is the length of the list, so rearranging is not possible
   if (fwd==0 || n ==0 ) return l;

   // Find last node
   while (fwd->next) {
	fwd= fwd->next;
        trail = trail->next;
   }
   // At this point fwd points to the last node and trail is 
   // one node behind the segment be rearranged
   fwd->next = l;
   l = trail->next;
   trail->next = 0;
   
   return l;

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
  
    int a[] =  {1, 2, 3, 4, 5};
    ListNode<int> * input = init(a,5);
    disp(input);
    input  = rearrangeLastN(0,0);
    cout << "TEST CASE 1: " <<  endl;
    disp(input);
  

  }
  
    // Test Case 2
  {
  
    //int a[] =  {0, 1,1, 0};
    //ListNode<int> * input = init(a,4);
    //disp(input);
    //bool result = rearrangeLastN(input);
    //cout << "TEST CASE 2: " << result << endl;
  

  }
  
  // Test Case 3
  {
  
    //int a[] =  {0, 1, 0};
    //ListNode<int> * input = init(a,3);
    //disp(input);
    //bool result = rearrangeLastN(input);
    //cout << "TEST CASE 3: " << result << endl;
  

  }
  
}
