#include<iostream>
#include<vector>


using std::cout;
using std::endl;
using std::vector;


int binary_search(vector<int> &v, int n) {
   
   // Control the range of the vector we are searching
   int floor_index = -1;
   int ceiling_index = v.size();

   // Divide and conquer range being searched 
   // until we find n or determine it is not
   // there.
   while (floor_index+1 <ceiling_index) {
      // Make guess at mid-point of this range
      int distance = ceiling_index - floor_index;
      int half_distance = distance / 2;
      int guess_index = floor_index + half_distance;


      // See if we found it, if not adjust the
      // ceiling or the floor appropriately
      if (v[guess_index] == n)
         return guess_index;
      else if (v[guess_index] > n)
        ceiling_index = guess_index; 
      else
        floor_index = guess_index;
   }
   return -1;
}

// #### TESTS #####



void tc_2(void) {
   vector<int> v = {1,2,3,4,5,6,7,8,9,10,11};
   cout << binary_search(v,5) << endl;
   cout << binary_search(v,6) << endl;
   cout << binary_search(v,4) << endl;
   cout << binary_search(v,1) << endl;
   cout << binary_search(v,10) << endl;
   cout << binary_search(v,12) << endl;
}



void tc_1(void) {
   vector<int> v = {1,2,3,4,5,6,7,8,9,10};
   cout << binary_search(v,5) << endl;
   cout << binary_search(v,6) << endl;
   cout << binary_search(v,4) << endl;
   cout << binary_search(v,1) << endl;
   cout << binary_search(v,10) << endl;
   cout << binary_search(v,12) << endl;
}


int main(void) { 
   tc_1();
   tc_2();
}

