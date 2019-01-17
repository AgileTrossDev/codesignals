/*
 * Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms
 * an island. For example, the below matrix contains 5 islands
 */



#include <iostream>

using std::cout;
using std::endl;
using std::min;
using std::max;

void disp_matrix(bool *mat, int s) { 
  for (int i = 0; i <s;i++) {
    for(int j = 0;j <s; j++) 
      cout << mat[i*j+j] << " ";
    cout << endl;     
  }

} 

void disp_matrix(bool **mat, int s) {
  for (int i = 0; i <s;i++) {
    for(int j = 0;j <s; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }

}


void init_visited(bool **v, int s) {
   for (int i = 0; i <s;i++) { 
    v[i] = new bool[s];
    for(int j = 0;j <s; j++) {
      v[i][j] = false;
    }
   }
}


void  fill_island(bool *m, bool **v, int s, int x, int y){
  cout << "CALLED: " << y << " " << x << endl;
  v[y][x] = true;
  disp_matrix(m,s);
  disp_matrix(v,s); 
  for (int i = max(0,y-1); i<=min(s,y+1);i++)
   for (int j = max(0,x-1);j<=min(s,x+1);j++) {
     if (i == y and j == x) continue;
     cout << "FI: Y: " << i << " X:" << j << " | " << ((( m[i*j+j]) == 1 && (v[i][j] == false))) <<endl;
     if (( m[i*j+j]) == 1 && (v[i][j] == false))  {
      fill_island(m, v,  s, j,i);
     } else {
        cout << "NOT" << endl;
        v[i][j] = true;
     }
   }
}



int search_for_islands(bool *m, bool **v, int s) { 
  int cnt = 0;
  for (int i = 0; i <s;i++) {
    for(int j = 0;j <s; j++) {
      cout <<"CHECKING: " << i << " " << j << endl;      
      if (( m[i*j+j]) == 1 && v[i][j] == false) {
        cnt++; 
        fill_island(m, v, s, i, j);
      }
    }
   }

  return cnt;
}

int execute(int s, bool *mat) {
  disp_matrix(mat,s);

  bool **visited = new bool*[s];
  init_visited(visited,s);

  return search_for_islands(mat,visited,s);
}


bool test_case_1() {
  bool mat[][5] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1} 
                  };
  bool (*m)[5] = mat;
  cout <<m[3][0] << endl;
  return execute(5, (bool *)m) == 5;

}
int main(void) {
  test_case_1();


}
