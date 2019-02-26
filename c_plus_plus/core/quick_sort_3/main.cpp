#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

typedef vector<int> d_t;

void swap(d_t& v, int l, int r){ 
    cout << "SWAPING: " << v[l] << " and " << v[r] << endl; 
    int tmp = v[l];
    v[l] = v[r];
    v[r] = tmp;
}

int partition(d_t &v, int l, int r) {
     int val = v[(l+r)/2];
     cout << l << " " << r << " VAL: " << val << endl;
     while (l<r) {
          while (v[l] < val) l++;
          while (l<r && val<v[r]) r--;
          cout << "MMM: " << l << " " << r << endl;
          if (l>=r) return r;
          swap(v,l,r);
          l++;
          r--;
     }
     return r;
}

void q_sort(d_t &v, int l, int r){
    if (l>=r) return;
    int index = partition(v,l,r);
    if (l<r) {
       q_sort(v,l,index-1);
       q_sort(v,index+1,r); 
    }
}


void disp(d_t& v) {
   cout << ">>>> ";
   for (int i =0;i<v.size();i++) 
       cout << v[i] << " ";
   cout << endl;
}


void tc_2() {
  d_t v = {3,2,1,5,4};
  disp(v);
  q_sort(v,0,v.size()-1);
  disp(v);
}
 
void tc_1() {

   d_t v = {3,2,2,1,4,2,5,4};
   disp(v);
   q_sort(v,0,v.size()-1);
   disp(v);
}


void tc_0(){
  d_t v= {3,2,2,1,4,2,5,4};
  disp(v);
  int index = partition(v,0,v.size()-1);
  disp(v);
  cout << "INDEX: " << index << endl;
}

int main(void) {
   tc_0();
   tc_1();
   tc_2();


}
