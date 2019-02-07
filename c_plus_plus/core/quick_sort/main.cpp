#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

typedef vector<int> iv_t;

void disp(iv_t &a);

void swap(iv_t &a, int l, int r) {
    int tmp = a[l];
    a[l] = a[r];
    a[r] = tmp;
}


// Finds middle of zone, and swaps elements if they are bigger/smaller than index
int partition(iv_t &a, int l, int r){

    // Find value to pivot around
    int pivot = a[(r+l)/2];

    while (l<r) {
         // Find elements to swap on either side of partition.
         while(pivot > a[l]) l++;
         while(pivot < a[r]) r--;

         if(l>=r) return r;   // No elements to swap
         swap(a,l,r);
    }
    return r;
}



// Partiions the input and then divides and conquers it.
void quick_sort(iv_t &a, int l , int r){
    if (l>=r) return;

    int index = partition(a,l,r);

    quick_sort(a,l,index);
    quick_sort(a,index+1,r);
}


void disp(iv_t &a){
   for (int i =0; i<a.size();i++)  cout << a[i] << " ";
   cout << endl;
}



void tc_2(){
   iv_t a = {9,8,7,6,5,4,3,2,1,0};

   disp(a);
   quick_sort(a,0,a.size()-1);
   disp(a);
}



void tc_1(){
   iv_t a = {6,1,9,2,8,4,3,0,5,7};
   disp(a);
   quick_sort(a,0,a.size()-1);
   disp(a);   
}


int main(void){
   tc_1();
   tc_2();
}
