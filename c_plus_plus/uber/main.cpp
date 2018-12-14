#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

#define TY 0;
#define TX 1;
#define BY 2;
#define BX 3;

typedef vector<int> vint_t;
typedef vector<vint_t> lot_t ;


void set_start(vin_t &start_x, vin_t &start_y, vin_t &end_x, vint_t &end_y, vint_t &spot, lot_t &lot) {
   if (spot[TX]-spot[BX] > spot[TY] - spot[BY]) { 
     // Horizontal path
     start_x = {0, spot[TX]}
     start_y = {car[TY],car[TY]};
     end_y = { car[BY], car[BY]};
     end_x = car[BX], lot[0].size()-1;
  } else {
     // vertical path
     start_x =spot[TX],spot[TX]
     start_y = 0, spot[TY] 
     end_x = spot[BX], spot[BX]
     end_y = spot[BY], lot.size()-1;
  }


}

bool traverse_lot(vin_t &start_x, vin_t &start_y, vin_t &end_x, vint_t &end_y, lot_t &spot){
   for (i=0;i<2;i++) { 
      bool set_good = true;
      for (int y = start_y[i];y<=end_y[i];y++){
        for (int x = start_x[i]; x <= end_x[i];x++){
          if (lot[y][x]== 1) {
            set_good= false;
            break;
          }
        }
        if (! set_good) break;
        return true;
       }
   }
   return false;

}

bool process(vin_t &car, vin_t &spot,  lot_t &lot) {

   vint_t start_x, start_y, end_y, end_x;
   set_start(start_x, start_y, end_x,end_y, spot);
   return traverse_lot(start_x, start_y, end_x,end_y, lot);

}



bool testcase_1(){
  return false;

}



int main() {

  bool res = testcase_1();
  cout << "Test Case #1: " << testcase_1() << endl;

}
