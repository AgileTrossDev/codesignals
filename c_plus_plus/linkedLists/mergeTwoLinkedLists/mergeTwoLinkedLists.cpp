// Note: Your solution should have O(l1.length + l2.length) time complexity, since this is what
// you will be asked to accomplish in an interview.
// 
// Given two singly linked lists sorted in non-decreasing order, your task is to merge them. In
// other words, return a singly linked list, also sorted in non-decreasing order, that contains
// the elements from both original lists.
// 
// Example
// 
// For l1 = [1, 2, 3] and l2 = [4, 5, 6], the output should be
// mergeTwoLinkedLists(l1, l2) = [1, 2, 3, 4, 5, 6];
//
// For l1 = [1, 1, 2, 4] and l2 = [0, 3, 5], the output should be
// mergeTwoLinkedLists(l1, l2) = [0, 1, 1, 2, 3, 4, 5].
// Input/Output
// 
// [time limit] 500ms (cpp)
// [input] linkedlist.integer l1
// 
// A singly linked list of integers.
// 
// Guaranteed constraints:
// 0 ≤ list size ≤ 104,
// -109 ≤ element value ≤ 109.
// 
// [input] linkedlist.integer l2
// 
// A singly linked list of integers.
// 
// Guaranteed constraints:
// 0 ≤ list size ≤ 104,
// -109 ≤ element value ≤ 109.
// 
// [output] linkedlist.integer
// 
// A list that contains elements from both l1 and l2, sorted in non-decreasing order.
// 
// 
//  Definition for singly-linked list:
//  template<typename T>
//  struct ListNode {
//    ListNode(const T &v) : value(v), next(nullptr) {}
//    T value;
//    ListNode *next;
//  };
//



#include <iostream>
#include <stack>
using std::cout;
using std::endl;

// Definition for singly-linked list:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(0) {}
   T value;
   ListNode *next;
};


void refresh_choices (ListNode<int> * &l1, ListNode<int> * & l2,ListNode<int> * & index) {
    // Traverse selected branch to setup next comparison
    if (index == l1)
        l1 = l1->next;
    else
        l2 = l2->next;
    
}


ListNode<int> * pick_next(ListNode<int> * l1, ListNode<int> * l2){
    // Make next selection
    //  - if both nodes are canditates, pick the smallest value
    //  - if only one branch contain nodes, then pick that one
    return (l1 && l2) ? ((l1->value < l2->value) ? l1 : l2) : ((l1 ==0) ? l2 : l1);
}

//------------------------------------------------------------------------------
// Solution
//------------------------------------------------------------------------------
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    
    if (l1 ==0 && l2 ==0) return 0;
    
    // Initial state, result and index is pointing at smallest value
    ListNode<int> * result = 0;
    if (l1 && l2)
        result = ((l1->value < l2->value) ? l1 : l2);
    else
         result = ((l1 == 0) ? l2 : l1);
    
    ListNode<int> * index = result;
    refresh_choices(l1,l2,index);
    
    // Traverse both branches until both have been full merged        
    while (l1 != 0 || l2 !=0){
        
        index->next =pick_next(l1,l2);
      
        index = index->next;
        refresh_choices(l1,l2,index);
    }
 index->next = 0;
    return result;
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
  
  
  //// Test Case 1
  {
  
    cout << "test Case 1 start..." << endl;
    int a[] =  {1, 2, 3};
    int b[] =  {4, 5, 6};
    
    ListNode<int> * inputa = init(a,3);
    ListNode<int> * inputb = init(b,3);
    disp(inputa);
    disp(inputb);
    ListNode<int> * result = mergeTwoLinkedLists(inputa,inputb);
    cout << "TEST CASE 1: " <<  endl;
    disp(result);
  
  
  }
  
  
  
  
    {
  
    cout << "test Case 2 start..." << endl;
    int a[] =  {};
    int b[] =  {1, 1, 2, 2, 4, 7, 7, 8};
    
    ListNode<int> * inputa = 0;//init(a,0);
    ListNode<int> * inputb = init(b,8);
    //disp(inputa);
    disp(inputb);
    ListNode<int> * result = mergeTwoLinkedLists(inputa,inputb);
    cout << "TEST CASE 2: " <<  endl;
    disp(result);
  
  
  }
  
  //// Test Case 2
  //{
  //
  //  cout << "\n\nTest Case 2 Start..." << endl;
  //  int a[] =  {1234, 1234, 0};
  //  int b[] =  {0};
  //  
  //  ListNode<int> * inputa = init(a,3);
  //  ListNode<int> * inputb = init(b,1);
  //  disp(inputa);
  //  disp(inputb);
  //  
  //  cout <<"doing working..." << endl;
  //  ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
  //  cout << "TEST CASE 2: " <<  endl;
  //  disp(result);
  //
  //
  //}
  //
  //
  //
  //// Test Case 3
  //{
  //
  //  cout << "\n\nTest Case 2 Start..." << endl;
  //  int a[] =  {9999, 9999, 9999,9999,9999,9999,9999};
  //  int b[] =  {1};
  //  
  //  ListNode<int> * inputa = init(a,7);
  //  ListNode<int> * inputb = init(b,1);
  //  disp(inputa);
  //  disp(inputb);
  //  
  //  cout <<"doing working..." << endl;
  //  ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
  //  cout << "TEST CASE 3: " <<  endl;
  //  disp(result);
  //
  //
  //}
  //
  //// Test Case 4
  //{
  //
  //  cout << "\n\nTest Case 2 Start..." << endl;
  //  int a[] =  {9999, 9999, 9999,9999,9999,9999,9999};
  //  int b[] =   {9999, 9999, 9999,9999,9999,9999,9999};
  //  
  //  ListNode<int> * inputa = init(a,7);
  //  ListNode<int> * inputb = init(b,7);
  //  disp(inputa);
  //  disp(inputb);
  //  
  //  cout <<"doing working..." << endl;
  //  ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
  //  cout << "TEST CASE 3: " <<  endl;
  //  disp(result);
  //
  //
  //}
  //
  //// Test Case 4
  //{
  //
  //  cout << "\n\nTest Case 1 Start..." << endl;
  //  int a[] =  {9999};
  //  int b[] =   {9999};
  //  
  //  ListNode<int> * inputa = init(a,1);
  //  ListNode<int> * inputb = init(b,1);
  //  disp(inputa);
  //  disp(inputb);
  //  
  //  cout <<"doing working..." << endl;
  //  ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
  //  cout << "TEST CASE 3: " <<  endl;
  //  disp(result);
  //
  //
  //}





  
    // Test Case 2
  {
    //
    //int a[] =  {0, 1,1, 0};
    //ListNode<int> * input = init(a,4);
    //disp(input);
    //bool result = isListPalindrome(input);
    //cout << "TEST CASE 2: " << result << endl;
  

  }
  
  // Test Case 3
  {
  
    //int a[] =  {0, 1, 0};
    //ListNode<int> * input = init(a,3);
    //disp(input);
    //bool result = isListPalindrome(input);
    //cout << "TEST CASE 2: " << result << endl;
  

  }
  
}
