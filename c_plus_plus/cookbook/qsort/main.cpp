#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

typedef vector<int> iv_t;

void disp(iv_t &v);


void swap(iv_t &v, int l, int r) {
 cout << "SWAPPING " << v[l] << l << " " << v[r] << r << endl;
          int tmp = v[l];
          v[l] = v[r];
          v[r] = tmp;
}

int partition(iv_t &v, int l, int r) {
    int key = l;

     while (l<=r) {
       while (v[l] <= v[key]) l++;
       while (v[key] < v[r]) r--;

       if (l<r) {
          swap(v,l,r);
          l++;
          r--;
       }

     }
     disp(v);
     if (key !=r ) {
       swap(v,key,r);
       return r;
     }
     return l;
}

void qsort(iv_t &v, int l, int r) {
    if (l>=r) return;
    int p = partition(v,l,r);
    cout << p << " " << l << " " << r << endl;
    qsort(v,l,p-1);
    qsort(v,p,r);

}

void disp(iv_t& v) {
   for (int i=0;i<v.size();i++)
     cout << v[i] << " ";
   cout << endl;

}

void tc_1(){
   iv_t v = {5,1,7,2,8,3,9,4,10,6};

   qsort(v,0,v.size());
   cout << "\nFinal: " << endl;
   disp(v);

}

int main(void) {
   tc_1();


}
