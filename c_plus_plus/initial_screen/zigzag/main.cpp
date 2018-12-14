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


int zigzag(std::vector<int> a) {
    
    
  int zigzag(std::vector<int> a) {
     
    std::vector<int>::iterator itr_a =a.begin(),itr_b=a.begin();
   
    
    itr_b++;
    
    int max =0;
    int counter =1; // Always one element in a zigzag

    bool expect_greater_than = true;    

    
    for (;itr_b !=a.end();++itr_a,++itr_b) {
        
        if ((*itr_a) > (*itr_b)){  // A is greater than B
           
            if (expect_greater_than == true) {// weren't expecting this occurence, so reset count
                counter =2;
            } else { // expecting this path, so increment counter 
                counter++;
            }
            // Now expecting B to be greater
            expect_greater_than = true;
            
        } else if ((*itr_a) < (*itr_b)){
            if (expect_greater_than == true) {
                counter++;
            } else {
                counter =2;
            }
            expect_greater_than = false;
        } else { // equal... so reset
            counter =1;
        }
        if (counter > max) {max = counter;}
        
        
               
    }
    
    
    
    return max;
}

   
    
    
}



int main (void) {
    
    {
     int tmp[] ={9, 8, 8, 5, 3, 5, 3, 2, 8, 6};
    
    input_t input;
    init_vector_of_ints(tmp,10 ,input);
    
    cout << zigzag(input) << endl;
    }
    
       {
     int tmp[] ={4,4};
    
    input_t input;
    init_vector_of_ints(tmp,2 ,input);
    
    cout << zigzag(input) << endl;
    } 
}