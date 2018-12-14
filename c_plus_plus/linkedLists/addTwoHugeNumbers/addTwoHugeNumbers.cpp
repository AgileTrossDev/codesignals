// You're given 2 huge integers represented by linked lists. Each linked list
// element is a number from 0 to 9999 that represents a number with exactly
// 4 digits. The represented number might have leading zeros. Your task is to
// add up these huge integers and return the result in the same format.
//
// Example
//
//    For a = [9876, 5432, 1999] and b = [1, 8001], the output should be
//    addTwoHugeNumbers(a, b) = [9876, 5434, 0].
//
//    Explanation: 987654321999 + 18001 = 987654340000.
//
//    For a = [123, 4, 5] and b = [100, 100, 100], the output should be
//    addTwoHugeNumbers(a, b) = [223, 104, 105].
//
//    Explanation: 12300040005 + 10001000100 = 22301040105.
//
// Input/Output
//
//    [time limit] 500ms (cpp)
//
//    [input] linkedlist.integer a
//
//    The first number, without its leading zeros.
//
//    Guaranteed constraints:
//    0 ≤ a size ≤ 104,
//    0 ≤ element value ≤ 9999.
//
//    [input] linkedlist.integer b
//
//    The second number, without its leading zeros.
//
//    Guaranteed constraints:
//    0 ≤ b size ≤ 104,
//    0 ≤ element value ≤ 9999.
//
//    [output] linkedlist.integer
//
//    The result of adding a and b together, returned without leading zeros in
//    the same format.
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




int calc_carry_over(ListNode<int> * a){
  int carry =0;
  
  if (0 !=  a && a->value > 9999) {
    //carry = a->value - 9999;
    carry = (a->value / 9999);
    a->value = a->value - 10000;
  }
  
  return carry;
  
}

// As we go deeper we increment index to the right, as bubble back up
// we move start to the right
ListNode<int> * recurse( ListNode<int> * a, ListNode<int> * b, std::stack<int> &sa, std::stack<int> &sb) {
  
  ListNode<int> * result = 0;
  
  if (0 != a || 0 != b) {
    
    result = new ListNode<int>(0);
    
    if (a!=0) sa.push(a->value);
    if (b!=0) sb.push(b->value);
    
    // Not at bottom on both lists, so increment indexes not at the bottom to left and recuse
    result->next =recurse( ((a== 0) ? a :a->next),((b== 0) ? b : b->next),sa,sb  );
    
    // calculate the carry over from previous node to this node
    int carry = calc_carry_over(result->next);

    // At this point in the call stack the lists are at the right most/smallest
    // value of the number that hasn't bee processed.
    int tmpa = (!sa.empty() ? sa.top() : 0);
    int tmpb = (!sb.empty() ? sb.top() : 0);
    
    cout << tmpa << " + " <<tmpb << " "  << endl;
    
    if(!sa.empty())sa.pop();
    if(!sb.empty()) sb.pop();
    
    result->value = carry  + tmpa + tmpb;
   
  } else {
    // bottom hit, but lists are null, so we return the empty node we justed created
  
  }
  
 
  // Return the next value in the link list 
  return result; 
  
}

//------------------------------------------------------------------------------
// Problem
//------------------------------------------------------------------------------
ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
  
  if (a ==0) return b;
  if (b ==0) return a;
  if (b ==0 && a ==0) return 0;
  
  std::stack<int> sa, sb;
  
  ListNode<int> * result = recurse(a,b,sa,sb);
   cout << result->value << endl;
  int extra = calc_carry_over(result);
  if (extra>0) {
    
   
    ListNode<int> * carry_over = new ListNode<int>(extra);
    carry_over->next =result;
    result = carry_over;
  }
  
  
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
  
  
  // Test Case 1
  {
  
  
    int a[] =  {9876, 5432, 1999};
    int b[] =  {1, 8001};
    
    ListNode<int> * inputa = init(a,3);
    ListNode<int> * inputb = init(b,2);
    disp(inputa);
    disp(inputb);
    ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
    cout << "TEST CASE 1: " <<  endl;
    disp(result);
  

  }

 
  // Test Case 2
  {
  
    cout << "\n\nTest Case 2 Start..." << endl;
    int a[] =  {1234, 1234, 0};
    int b[] =  {0};
    
    ListNode<int> * inputa = init(a,3);
    ListNode<int> * inputb = init(b,1);
    disp(inputa);
    disp(inputb);
    
    cout <<"doing working..." << endl;
    ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
    cout << "TEST CASE 2: " <<  endl;
    disp(result);
  

  }
  
  
  
  // Test Case 3
  {
  
    cout << "\n\nTest Case 2 Start..." << endl;
    int a[] =  {9999, 9999, 9999,9999,9999,9999,9999};
    int b[] =  {1};
    
    ListNode<int> * inputa = init(a,7);
    ListNode<int> * inputb = init(b,1);
    disp(inputa);
    disp(inputb);
    
    cout <<"doing working..." << endl;
    ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
    cout << "TEST CASE 3: " <<  endl;
    disp(result);
  

  }
  
  // Test Case 4
  {
  
    cout << "\n\nTest Case 2 Start..." << endl;
    int a[] =  {9999, 9999, 9999,9999,9999,9999,9999};
    int b[] =   {9999, 9999, 9999,9999,9999,9999,9999};
    
    ListNode<int> * inputa = init(a,7);
    ListNode<int> * inputb = init(b,7);
    disp(inputa);
    disp(inputb);
    
    cout <<"doing working..." << endl;
    ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
    cout << "TEST CASE 3: " <<  endl;
    disp(result);
  

  }
  
  // Test Case 4
  {
  
    cout << "\n\nTest Case 1 Start..." << endl;
    int a[] =  {9999};
    int b[] =   {9999};
    
    ListNode<int> * inputa = init(a,1);
    ListNode<int> * inputb = init(b,1);
    disp(inputa);
    disp(inputb);
    
    cout <<"doing working..." << endl;
    ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
    cout << "TEST CASE 3: " <<  endl;
    disp(result);
  

  }





  
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
