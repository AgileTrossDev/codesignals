#include<iostream>

using std::cout;
using std::endl;

#define dim 3

void disp (int arr[dim][dim]) {
    for (int i = 0; i<dim; i++){
      for(int j =0; j<dim; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }


}

void disp(int arr[],int row, int col) {
     for (int i = 0; i<row; i++){
      for(int j =0; j<col; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }

}

int main(void) {
    
   int arr[dim][dim] = { {1,2,3},{4,5,6},{7,8,9}};

   disp(arr);
   disp(arr[0],dim,dim);


   cout << "START" << endl;



   cout << "END" << endl;



}
