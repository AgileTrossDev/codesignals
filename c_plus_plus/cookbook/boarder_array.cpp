#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::min;
using std::max;
using std::vector;

typedef vector<vector<int> > board_t;

void do_action(int val) {
  cout << val << endl;

}


void traverse_border(board_t & board, int x, int y ) {

   cout << "Boarder at (" <<x << "," << y << ") " << board.size() << "x" << board[0].size() << endl;
   cout << y+1 << " "<<  x+1 << endl;
   for (size_t i = max(0,y-1);i<=min(board.size()-1,((size_t)y+1));i++) {
    for (size_t j = max(0,x-1);j<=min(board[i].size()-1,((size_t)x+1));j++) {
       if(i==y && j == x)
         continue;
       cout << board[i][j] << "(" << i << ","<<j<<")"<< " ";
    }
   }
   cout << endl;
}


int main(void) {
   vector<vector<int> > board;   
   for (int i = 1; i <6; i++) {
     vector<int> v;
     for (int j = 1; j< 6; j++) { 
       v.push_back(i*j);
     } 
     board.push_back(v);
    }
    cout << "BOARD COMPLETED" << endl;
    traverse_border(board,0,0);
    traverse_border(board,1,1);
    traverse_border(board,4,4);
}


