// Note: Try to solve this task in-place (with O(1) additional memory), since
// this is what you'll be asked to do during an interview.
// 
// You are given an n x n 2D matrix that represents an image. Rotate the image
// by 90 degrees (clockwise).
// 
// Example
// 
// For
// 
// a = [[1, 2, 3],
//      [4, 5, 6],
//      [7, 8, 9]]
// 
// the output should be
// 
// rotateImage(a) =
//     [[7, 4, 1],
//      [8, 5, 2],
//      [9, 6, 3]]
// 
// Input/Output
// 
//     [time limit] 500ms (cpp)
// 
//     [input] array.array.integer a
// 
//     Guaranteed constraints:
//     1 ≤ a.length ≤ 100,
//     a[i].length = a.length,
//     1 ≤ a[i][j] ≤ 104.
// 
//     [output] array.array.integer
//     
    
#include<vector>
#include<iostream>
using std::cout;
using std::endl;
    
void disp (std::vector<std::vector<int> > & a) {
 
  for (int i = 0;i<a.size();++i) {
      for (int j = 0;j<a.size();++j) {
        cout << a[i][j] << "|";
      }
      cout << endl;
      
  }
 
 
  
}

void rotate_cord( int &x, int &y, int left_side_edge,int right_side_edge) {
  
  if (x == left_side_edge){
    // Top, rotate to Right
    //cout <<" top " ;
    x = y;
    y = right_side_edge; 
  }else if (y == right_side_edge ){
    //cout << " right " ;
    // Right Side, rotate to bottom
    y = right_side_edge- x + left_side_edge;
    x = right_side_edge;
  }else if   (x == right_side_edge) {
    // Bottom, rotating to left side
    //cout << " bottom " ;
     x = y;
    y = left_side_edge;
    
  }else if   (y == left_side_edge) {
    // Left SIDE, rotate to top
    //cout << " left " ;
    y = right_side_edge-x  + left_side_edge;
    x = left_side_edge;
  }
}


int rotate_element(std::vector<std::vector<int> > &a, int x,int y, int val,int n1, int n2, int depth=0) {
  
  
  // Rotoate the coordinates, store the value
  // there, then update the value
  rotate_cord(x,y,n1,n2);
  
  //cout << "  Rotating Val: " << val << " into " << x <<"," <<y <<  " ( " << n1 <<"," << n2 << ")" <<endl;
  int tmp = a[x][y];
  a[x][y] = val;
  
  if (depth == 3) { // rotation complete, bubble up last value
   return val; 
  } else { // rotate the next side
    return rotate_element(a,x,y, tmp,n1,n2, (++depth));
  }
};
    
std::vector<std::vector<int> > rotateImage( std::vector<std::vector<int> > a) {
    
    int n = a[0].size();
    int rotations = 0;
    
    while (rotations<  (n/2)) {      
      for (int y = rotations; y< (n-rotations-1);++y) {
        //cout <<"Rotation Start: " << rotations << "," << y << " " << endl;
        a[rotations][y] = rotate_element(a,rotations,y,a[rotations][y],rotations,(n-rotations-1));
      //  disp(a);
      }  
     rotations++;
  
    }
    return a;
}

int main (void) {
  

  {
    std::vector<std::vector<int> > input;
    std::vector<int> row1,row2,row3;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);
    row2.push_back(4);
    row2.push_back(5);
    row2.push_back(6);
    row3.push_back(7);
    row3.push_back(8);
    row3.push_back(9);
    input.push_back(row1);
    input.push_back(row2);
    input.push_back(row3);
    
    cout <<"Start: " << endl;
    disp(input);
    
    std::vector<std::vector<int> >  b= rotateImage(input);
    
    cout << "\n\nFinal: " << endl;
    disp(b);
    
  }
  
  
  {
   
   //Input  
   // [[10,9,6,3,7], 
   // [6,10,2,9,7], 
   // [7,6,3,8,2], 
   //  [8,9,7,9,9], 
   // [6,8,6,8,2]] 
   // 
    //   Expected Output:
    //
    // [[6,8,7,6,10], 
    // [8,9,6,10,9], 
    // [6,7,3,2,6], 
    // [8,9,8,9,3], 
    // [2,9,2,7,7]]
  
 
    std::vector<std::vector<int> > input;
    std::vector<int> row1,row2,row3,row4,row5;
    row1.push_back(10);
    row1.push_back(9);
    row1.push_back(6);
    row1.push_back(3);
    row1.push_back(7);
    
    row2.push_back(6);
    row2.push_back(10);
    row2.push_back(2);
    row2.push_back(9);
    row2.push_back(7);
    
    row3.push_back(7);
    row3.push_back(6);
    row3.push_back(3);
    row3.push_back(8);
    row3.push_back(2);
    
    row4.push_back(8);
    row4.push_back(9);
    row4.push_back(7);
    row4.push_back(9);
    row4.push_back(9);
    
    row5.push_back(6);
    row5.push_back(8);
    row5.push_back(6);
    row5.push_back(8);
    row5.push_back(2);
    
    input.push_back(row1);
    input.push_back(row2);
    input.push_back(row3);
    input.push_back(row4);
    input.push_back(row5);
    
    cout <<"Start: " << endl;
    disp(input);
    
    std::vector<std::vector<int> >  b= rotateImage(input);
    
    cout << "\n\nFinal: " << endl;
    disp(b);
    
    
    
    
    
    
  }
  
  
  
  




  
  
  //
  //int x=0,y=1,n1=0,n2=2;
  //rotate_cord(x,y,n1,n2);  
  //cout << x << "," << y << endl;
  //rotate_cord(x,y,n1,n2);  
  //cout << x << "," << y << endl;
  //rotate_cord(x,y,n1,n2);  
  //cout << x << "," << y << endl;
}

