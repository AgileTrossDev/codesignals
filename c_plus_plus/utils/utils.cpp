#include <iostream>
#include <stdlib.h>
#include <cstdint>
// Stable Divide and Conquer Sort with memory usage
using std::cout;
using std::endl;



nt gen_input(int*& array);
void disp(int array[],int size);



int gen_input(int*& array) {
  int size = rand() %100+1;
  array = new int[size];
  for(int i= 0; i<size;i++)
       array[i]=rand()%100;
  return size;
}

void disp(int array[], int size) {
  cout <<"Listing array..." << " ";
  for(int i=0;i<size;++i)
    cout << array[i] << " ";
  cout << endl;
}








