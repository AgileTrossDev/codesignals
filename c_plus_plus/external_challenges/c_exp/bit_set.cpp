#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

enum Stages: int{ STAGE_1 = 1, STAGE_2 = 2, STAGE_3 = 4, STAGE_4 = 8 };

bool in_set(int num, Stages s) {
   cout << s <<" "  <<(~s) << endl;
   return (num & s) == true;
}

int update_set(int num,Stages s ) {
  
  int r = num | s;
  cout <<"UPDATING... " << num << " or " << s << " to " << r << endl;
  num = num | s;
  return r;


}

bool complete_set(int n) {
   return (n == (STAGE_1|STAGE_2|STAGE_3|STAGE_4));


}


int main(void) {
   int num = 1;

   //update_set(num, STAGE_1);
   //update_set(num, STAGE_2);
   //update_set(num, STAGE_3);
   //update_set(num, STAGE_4);
   cout << "NUM: " << num << endl;

   cout << in_set(num,STAGE_1) << endl;
   if (! in_set(num,STAGE_1))
     num = update_set(num, STAGE_1);
   
   cout <<"AFTER UPDATE: |" << num << " | " << (0 | STAGE_2) << endl;

   if (complete_set(num))
     cout << "COMPLETE" << endl;
   else
     cout << "NONT COMPLETE" << endl;

   num = update_set(num, STAGE_1);
   num = update_set(num, STAGE_2);
   num = update_set(num, STAGE_3);
   num = update_set(num, STAGE_4);

   if (complete_set(num))
     cout << "COMPLETE" << endl;
   else
     cout << "NONT COMPLETE" << endl;



}
