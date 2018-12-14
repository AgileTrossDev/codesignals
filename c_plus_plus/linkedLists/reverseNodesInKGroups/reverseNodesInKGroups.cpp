// Note: Your solution should have O(n) time complexity, where n is the number of element in l,
// and O(1) additional space complexity, since this is what you would be asked to accomplish
// in an interview.
 //
 // Given a linked list l, reverse its nodes k at a time and return the modified list. k is a
 // positive integer that is less than or equal to the length of l. If the number of nodes in
 // the linked list is not a multiple of k, then the nodes that are left out at the end should
 // remain as-is.
 //
 // You may not alter the values in the nodes - only the nodes themselves can be changed.
 //
 //Example
 //
 //For l = [1, 2, 3, 4, 5] and k = 2, the output should be
 //reverseNodesInKGroups(l, k) = [2, 1, 4, 3, 5];
 //
 //For l = [1, 2, 3, 4, 5] and k = 1, the output should be
 //reverseNodesInKGroups(l, k) = [1, 2, 3, 4, 5];
 //
 //For l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] and k = 3, the output should be
 //reverseNodesInKGroups(l, k) = [3, 2, 1, 6, 5, 4, 9, 8, 7, 10, 11].
 //
 //Input/Output
 //
 //[time limit] 500ms (cpp)
 //[input] linkedlist.integer l
 //
 //A singly linked list of integers.
 //
 //Guaranteed constraints:
 //1 ≤ list size ≤ 104,
 //-109 ≤ element value ≤ 109.
 //
 //[input] integer k
 //
 //The size of the groups of nodes that need to be reversed.
 //
 //Guaranteed constraints:
 //1 ≤ k ≤ l size.
 //
 //[output] linkedlist.integer
 //
 //The initial list, with reversed groups of k elements.
 
 
//Definition for singly-linked list:
//template<typename T>
//struct ListNode {
//  ListNode(const T &v) : value(v), next(nullptr) {}
//  T value;
//  ListNode *next;
//};
  
  


#include <iostream>
#include <stack>
#include <utility>
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

typedef std::pair<ListNode<int>*,ListNode<int>* > segment_t;

segment_t invert (ListNode<int> * leading_index, int k,ListNode<int> * trail_index = 0) {
    
    
    // Leading index will always be one step ahead of trailing on
    // each call.  If we have a complete set, then we bubble
    // the kth+1 node up, reversing links on the way up, if
    // there isn't a complete set, we leave things alone.
    // This is marked be a return val of -1.  Note, tha the k+1
    // node might be a null value of 0.
    //
    // At the end of the recussion, we will return node for the next
    // segment to invert
    
    // First will point to start of segment, and second will point to end
    // First will be updated as it bubbles up
    segment_t ret_val(0,0);
    
    if (leading_index ==0 && k !=0) {
        // bottomed out, and do not have a complete set, so we return 0
    } else if (k >1) {
         // Still diving       
        ret_val = invert(leading_index->next,--k,leading_index);
        
        if (ret_val.first != 0)  {
            // Complete set, so invert. The catch is that when we
            // bubbled up to the last record in the call stack, then
            // this node is now the last and should point to what comes
            // after this segment.
            leading_index->next = (trail_index == 0) ? ret_val.second : trail_index;
        }
    } else  { // bottomed out and have a complete set
        // These will not change because it represents,
        // the new start of the segment and what follows the end of the segement
        ret_val.second = leading_index->next;
        ret_val.first = leading_index; 
        
        // Invert Connection
        leading_index->next = trail_index;
    }
    
    
     return ret_val; 
    
}

//------------------------------------------------------------------------------
// Solution
//------------------------------------------------------------------------------
 ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
 
    ListNode<int> * index = l;
    ListNode<int> * new_start = 0;
    ListNode<int> * prev_seg_end = 0;
    
    while (index !=0) {
        
        
        // Try to invert, if succesful, e hvae a new top
        segment_t segment = invert(index,k);

        // Connect the previous segment to the start of the new segment, dependent on inverstion
        if (prev_seg_end!=0) prev_seg_end->next = (segment.first == 0) ? index : segment.first;
        
         // On first iteration, set the new top if inversion was succesful
        if (new_start==0) {
            new_start =(segment.first == 0) ? l : segment.first;
            
        }
        
        // Stash end of current segment
        prev_seg_end = index;
        
        // Move index to start of new segment
        index = segment.second;
         
    }
    return new_start;
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
  
    cout <<"\n\nTest Case 1"<< endl;
  
    int a[] =  {1, 2, 3, 4, 5};
    
    
    ListNode<int> * input = init(a,5);
    int k =3;
    
    disp(input);
    
    cout << "calculating..." << endl;
    ListNode<int> * result = reverseNodesInKGroups(input,k);
    cout << "TEST CASE 1: " <<  endl;
    disp(result);
  

  }
  
    // Test Case 2
  {
  
    cout <<"\n\nTest Case 2"<< endl;
  
    int a[] =  {1, 2, 3, 4, 5};
    
    
    ListNode<int> * input = init(a,5);
    int k =2;
    
    disp(input);
    
    cout << "calculating..." << endl;
    ListNode<int> * result = reverseNodesInKGroups(input,k);
    cout << "TEST CASE 2: " <<  endl;
    disp(result);
  

  }

 
  // Test Case 2
  {
  
    //cout << "\n\nTest Case 2 Start..." << endl;
    //int a[] =  {1234, 1234, 0};
    //int b[] =  {0};
    //
    //ListNode<int> * inputa = init(a,3);
    //ListNode<int> * inputb = init(b,1);
    //disp(inputa);
    //disp(inputb);
    //
    //cout <<"doing working..." << endl;
    //ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
    //cout << "TEST CASE 2: " <<  endl;
    //disp(result);
  

  }
  
  
  
  // Test Case 3
  {
  
    //cout << "\n\nTest Case 2 Start..." << endl;
    //int a[] =  {9999, 9999, 9999,9999,9999,9999,9999};
    //int b[] =  {1};
    //
    //ListNode<int> * inputa = init(a,7);
    //ListNode<int> * inputb = init(b,1);
    //disp(inputa);
    //disp(inputb);
    //
    //cout <<"doing working..." << endl;
    //ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
    //cout << "TEST CASE 3: " <<  endl;
    //disp(result);
  

  }
  
  // Test Case 4
  {
  
    //cout << "\n\nTest Case 2 Start..." << endl;
    //int a[] =  {9999, 9999, 9999,9999,9999,9999,9999};
    //int b[] =   {9999, 9999, 9999,9999,9999,9999,9999};
    //
    //ListNode<int> * inputa = init(a,7);
    //ListNode<int> * inputb = init(b,7);
    //disp(inputa);
    //disp(inputb);
    //
    //cout <<"doing working..." << endl;
    //ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
    //cout << "TEST CASE 3: " <<  endl;
    //disp(result);
  

  }
  
  // Test Case 4
  {
  
    //cout << "\n\nTest Case 1 Start..." << endl;
    //int a[] =  {9999};
    //int b[] =   {9999};
    //
    //ListNode<int> * inputa = init(a,1);
    //ListNode<int> * inputb = init(b,1);
    //disp(inputa);
    //disp(inputb);
    //
    //cout <<"doing working..." << endl;
    //ListNode<int> * result = addTwoHugeNumbers(inputa,inputb);
    //cout << "TEST CASE 3: " <<  endl;
    //disp(result);
  

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

 
