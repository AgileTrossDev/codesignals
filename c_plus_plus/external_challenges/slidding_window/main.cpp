#include <iostream>

using std::cout;
using std::endl;
using std::max;

int max_window(int arr[], int n, int k) {
 int beg = 0;
 int tail = k-1;
 int max_sum = 0;
 int running_sum = 0 ;   

 for (int i = 0; i<k; i++) 
   running_sum = running_sum + arr[i];

 max_sum = running_sum;

 while (tail<n) { 
    running_sum = running_sum - arr[beg];
    beg++;
    tail++;
    running_sum = running_sum +  arr[tail];
    cout << beg << " : " << tail << " = " << running_sum << endl; 
    max_sum = max(running_sum,max_sum);
 } 

  arr[0] = 0;
  return max_sum;
}


int main(void) {
   int input[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
   int n = 9;
   int k = 4;

   cout << "RESULT: " << max_window(input, n, k) << endl;
   cout << input[0] << endl;
}
