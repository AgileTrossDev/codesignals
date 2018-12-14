/*


You are given an array parent of length n specifying a tree. The vertices of the tree are
numbered from 0 to n - 1 and parent[i] is the parent of the ith node. The root of the tree
is the vertex v which parent is the same vertex (i.e. parent[v] = v if and only if v is a root).

What will the parent array look like if the edges remain the same but tree is rooted at the other vertex newRoot?

Example

For parent = [0, 0, 0, 1] and newRoot = 1, the output should be
changeRoot(parent, newRoot) = [1, 1, 0, 1].

Check out the image below for better understanding:

*/
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

typedef std::vector<int> input_t;
void init_vector_of_ints(int arr[],int size, input_t &v) {
    v.clear();
    for (int i=0; i<size;i++)
        v.push_back(arr[i]);
}


void disp (input_t &v) {
    for (input_t::iterator itr = v.begin();itr!=v.end();++itr)
        cout << (*itr) << " ";
    
    cout << endl;
}



void traverse(std::vector<int> &parent, int index) {
   
    
    
    if (index != parent[index]) {
        
         // Not root, so bubble up next level in search of root,
         // inverting association on return trip
         (traverse(parent,parent[index]));
         //cout << "Reversing Element " << parent[index] << " to be child of " << index << endl; 
        parent[parent[index]] = index;
       
       // parent[tmp] = index;
       // return parent[index];
    } else {
        //cout << "ROOT FOUND: " << parent[index] << endl;
    }
    
   
   
     
  // return  index;
}

std::vector<int> changeRoot(std::vector<int> parent, int newRoot) {
    
   // new root becomes the root
   // new root's previous parent, must remain connected to  newroot, so it becomes a child of new root
   // old root must maintain it's previous connections, so it becomes a child of one it's siblings that tis connected to tree
    
    //int index =newRoot;
    //int prev_index = -1;
    //
    //while (true) {
    //    
    //    if (index == parent[index]  ){
    //        // Existing Root Found. It now becomes a child of one it's sibblings
    //       cout << "I: " << index << " P:" << prev_index << endl;
    //        parent[index] =   prev_index;
    //        break;   
    //    }
    //    
    //    // Haven't found root yet, so bubble up tree
    //    prev_index = index;
    //    index = parent[index];
    //   
    //}
    //
    //
    
    traverse(parent,newRoot);
   // disp(parent);
   
    
    // Finalize new Root
    //parent[parent[newRoot]] = newRoot;
    parent[newRoot] = newRoot;
     
    return parent;


}


int main (void) {
    
    {
     int tmp[] ={0,0,0,1};
    
    input_t input;
    init_vector_of_ints(tmp,4,input);
    input_t res= changeRoot(input,1);
    disp(res);
    
   //cout << zigzag(input) << endl;
    }
    
    
    
    {
        
        // 0 -> 1 ->3
        //        -> 4
        //        -> 5
        //   -> 2 -> 6
        //        -> 7 -> 8

/*
 *    2, 0, 7, 1, 1, 1, 2, 7, 7
 *    7- > 2-> 0 -> 1 -> 3/4/5
 *          -> 6
 *      ->8
 *    
 *
 *
 *
 *
 */


        
         //0  1  2  3  4  5  6  7  8
        // 2                    7
     int tmp[] ={0, 0, 0, 1, 1, 1, 2, 2, 7};
    
     input_t input;
    init_vector_of_ints(tmp,9,input);
    input_t res= changeRoot(input,7);
    disp(res);
    }
    
    
    
   /*
    
    
          5 -> 0 -> 2 -> 14
                 -> 7
                 -> 10 -> 4
                       -> 8
                       -> 9
                 
               3 -> 1
                 -> 12
                 -> 13 -> 11
               6
            
          
    0  1  2  3   4  5  6  7   8   9 10  11 12 13 14
    5, 3, 0, 5, 10, 5, 5, 0, 10, 10, 0, 13, 3, 3, 2
   10, 3, 0, 5, 10, 0, 5, 0,  8, 10, 8, 13, 3, 3, 2
   
   8 is new parent
   5 is old node, it's new parent 0.  Why?
   0 did point to old node, so it changes to to 10?
   10 was newNodes parent, so it becomes a child?
    
    */
     {
     int tmp[] ={5, 3, 0, 5, 10, 5, 5, 0, 10, 10, 0, 13, 3, 3, 2};
    
    input_t input;
    init_vector_of_ints(tmp,15,input);
    input_t res= changeRoot(input,8);
    disp(res);
    
   //cout << zigzag(input) << endl;
    }
    
}