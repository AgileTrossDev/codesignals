#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

#define nullptr NULL

struct Node {
  Node(int v): val(v), next(nullptr) {};
  int val;
  Node * next;


};


struct LinkList {
   LinkList():root(nullptr) {};
   ~LinkList() {
     Node * index =root->next;
     while (index) {
       delete root;
       root = index;
       index = root->next;
     }

   } 

  Node* add_node(int v) {
       if (!root) {
         root = new Node(v);
         return root;
      }
 
      Node * index = root;
      while (index->next) 
          index = index->next;

      index->next = new Node(v);

      return index->next;  

  }

  Node * find_tail() {
     Node * index = root;
     while (index->next) 
        index = index->next;
   
     return index;

  }

 Node * find_node(int v) {
	Node * index =root;
       while(index->val != v) index = index->next;

       return index;

  }


  void disp() {
      Node * index = root;
      while (index != nullptr)  {
          cout << index->val << endl;
          index = index->next;
      }
  }

  bool detect_loop () {
    if (!root) return false;

    Node * slow = root;

    Node * fast = root->next;     
    if (!fast) return false;
    fast = fast->next;

    while(fast && fast != slow) {
       //cout << "SLOW: " << slow->val << " FAST: " << fast->val << endl;
       slow = slow->next;
       fast = fast->next;
       if(fast) fast = fast->next;
    }
    //cout << "COMPLETE" << endl; 
    bool ret_val = slow ==fast;
    return ret_val;

  }

  void correct_loop() {

    if (!root) return;
    Node * slow = root; 
    Node * fast = root;

    while(fast &&  fast->next != nullptr)  {
       slow = slow->next;
       fast = fast->next->next;
       if (slow == fast) break;
       cout << " S: " << slow->val << " F: " << fast->val << endl;
   }

   if (slow !=fast) return;

   cout << "LOOP FOUND: " << slow->val << endl;
 
   fast = root;
   bool found = false;
   Node * index;
   while(!found) {
     index = slow;
     while(index->next !=slow && index->next != fast) index=index->next;

     if (index->next == fast) break;
     fast=fast->next;


   }
   index->next=nullptr;

   cout << "Y" << endl;
  }
  
  Node * root;

};


int main(void) {
   LinkList ll;
   for(int i =0;i<10;i++) 
          ll.add_node(i);


   Node * tail = ll.add_node(10); 
   ll.disp();   
   cout << "TAIL: "  << tail->val << endl;
  
   cout << "IS LOOP: " << ll.detect_loop() << endl;
   
   // Make loop
   tail->next = ll.find_node(3);

   cout << "IS LOOP: " << ll.detect_loop() << endl; 
   ll.correct_loop();

   cout << "COMPLETE: " << ll.detect_loop() << endl;
   cout << "DISPLAYING..." << endl;
   ll.disp(); 

   
   cout << "done" << endl;
   return 0;
}



