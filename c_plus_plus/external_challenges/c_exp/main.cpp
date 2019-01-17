#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#define M 3
#define N 3


typedef vector<vector<int> > ds_t;
typedef vector<vector<int> >::iterator ds_itr_t;
typedef vector<int>::iterator ds_row_itr_t;

void disp_array(int a[M][N]){
  for (int i = 0; i<M ; i++) {
    for (int j =0; j< N; j++)
        cout << a[i][j] << " ";
    cout << endl;
  }
}


void disp_vector(ds_t &d) {
   for (ds_itr_t i = d.begin();i != d.end();i++ ) {
     for (ds_row_itr_t j = (*i).begin(); j != (*i).end(); j++)
        cout << (*j) << " ";
 
     cout << endl;
   }


}

int main(void) {
  cout << "START" << endl;

  int blah[M][N] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };


  ds_t burp = { {9,8,7},{6,5,4},{3,2,1}};

 disp_array(blah);
 disp_vector(burp);

  cout << "END" << endl;



}

