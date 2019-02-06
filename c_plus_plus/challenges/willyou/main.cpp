#include<iostream>
using std::cout;
using std::endl;

bool willYou(bool y, bool b, bool l) {
    return ((y && b && l) ||(!y && !b && !l)) ? false : true;
}


void call(int i, bool y, bool b, bool l){
     cout << "TC: " << i << " " << willYou(y,b,l) << endl;

}

int main(void) {
    call(1, true,true,true);
    call(2,true,true,false);
    call(3,true,false,true);
    call(4,true,false,false);
    call(5,false,false,false);
    call(6,false,true,true);
    call(7,false,true,false);
    call(8,false,false,true);

}

