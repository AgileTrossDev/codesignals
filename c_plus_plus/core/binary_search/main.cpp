#include<iostream>
#include<vector>


using std::cout;
using std::endl;
using std::vector;


int binary_search_util(vector<int> &v, int n, int start, int elements, int &calls) {
    //cout <<  start << " " << elements << " NEXT: " << elements/2 <<  endl;

    if (elements ==1 && n != v[start] ) return -1;
    int mid = elements/2+start;
  
   // cout << "MID: " << mid << " " << v[mid] << endl;

    calls++;

    if (v[mid] == n) {
	return mid;	
    } else if (v[mid]<n) {
      return binary_search_util(v,n,mid+1,elements/2,calls);
    } 

    return binary_search_util(v,n,start,elements/2,calls);
}

int binary_search(vector<int> &v, int n) {
   int calls =0;
   int result = binary_search_util(v,n,0,v.size(),calls);

   cout << "SEARCHING: " << n  << " TOTAL CALLS: " << calls << " RESULT: " << result << endl;


   return result;
   

}




// #### TESTS #####



void tc_2(void) {
   vector<int> v = {1,2,3,4,5,6,7,8,9,10,11};
   binary_search(v,5);
   binary_search(v,6);
   binary_search(v,4);
   binary_search(v,1);
   binary_search(v,10);
   binary_search(v,12);
}



void tc_1(void) {
   vector<int> v = {1,2,3,4,5,6,7,8,9,10};
   binary_search(v,5);
   binary_search(v,6);
   binary_search(v,4);
   binary_search(v,1);
   binary_search(v,10);
   binary_search(v,12);
}


int main(void) { 
   tc_1();
   tc_2();
}
