#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::min;
using std::max;
using std::vector;

typedef vector<vector<bool> > map_t;
typedef vector<bool> map_row_t;

void build_visited(map_t &m, map_t &v) {

  for (size_t y = 0; y < m.size(); y++) {
   map_row_t row;   
   for (size_t x = 0; x< m[y].size();x++) {
      row.push_back(false);
    }
    v.push_back(row); 
  }
}


void fill_island(map_t &m, map_t &v, int x, int y) {
   v[y][x]=true;
   for (size_t j = max(0,y-1); j <= min(size_t(y+1),m.size()-1); j++) {
    for (size_t i = max(0,x-1); i <= min(size_t(x+1),m[y].size()-1); i++) {
       if (j==y && i ==x) continue;
       if (m[j][i] == true && v[j][i] == false) {
         fill_island(m,v,i,j);
       } else {
        v[j][i] = true;
       }
    }
   }
}

int execute(map_t &m) {
  int cnt = 0;
  map_t v;
  build_visited(m,v); 

   for ( size_t y = 0; y < m.size(); y++) {
     for ( size_t x = 0; x< m[y].size(); x++) {
       if (m[y][x] == true && v[y][x] == false) {
         cnt++;
         cout << "New Island (" << y << "," << x << ") " << m[y][x] << endl;
         fill_island(m,v,x,y);
       } else {
        v[y][x] = true;
       }
     }

   }

  return cnt;
}

bool test_case_1(void) {
   map_t m =  {{1,1,0,0,1},
            {0,1,0,0,1},
            {1,0,0,0,0},
            {0,0,1,0,1},
            {1,1,0,0,0}
           };

    return ( 4 == execute(m));


}

int main (void) {
   cout << "START" << endl;
   cout << "TEST CASE 1 : " << test_case_1() << endl;

   cout << "END" << endl;


}
