#include <iostream>

using std::cout;
using std::endl;

struct Node {
    Node(int v):val(v), left(0), right(0), cnt(0){};

    Node * add_node(int v) {
        Node * n;
	if (left == 0) {
           n = new Node(v);
           cout << "ADDING LEFT " << v << endl;
           left = n;
        } else if (right ==0) {
           n = new Node(v);
           cout << "ADDING RIGHT " << v  << endl;
           right = n;
        } else if (left->cnt == right->cnt) {

           n = left->add_node(v);
        } else {
           n = right->add_node(v);
        }
        cnt++;
        return n;
    }
 

    void disp() {
       cout << val << endl;
       if(left !=0)  left->disp();
       if(right !=0) right->disp();
    } 

    void disp_border(int side=0) {

        if (side ==0 ) {
            cout << val << endl;
            if(left !=0)  left->disp_border(1);
            if(right!=0) right->disp_border(2);
        }
  
        if (side ==1) {
           cout << val << endl;
           if(left!=0) left->disp_border(1);
           if(right!=0) right->disp_border(3);
        }

        if (side ==2) {
           if(left!=0) left->disp_border(3);
           if(right!=0) right->disp_border(2);
           cout << val << endl;
        }

        if (side ==3) {
           
           if(left!=0) left->disp_border(3);
           if(right!=0) right->disp_border(2);
           if(left ==0 && right == 0) cout << val <<endl;
      

        }
               


    } 

    int val;
    Node * left;
    Node * right;
    int cnt;

};




int main(void){
    Node * root = new Node(0);
    for (int i =1; i<31; i++)  root->add_node(i);
 

    root->disp(); 
    root->disp_border(); 



}
