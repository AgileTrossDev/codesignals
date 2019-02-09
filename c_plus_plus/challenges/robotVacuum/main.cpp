#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;


typedef vector<vector<int> > room_t; 
typedef vector<vector<int> >::iterator room_iter;

int R_STATES[][4] = {{0,1,2,3},
                     {3,0,1,2},
                     {2,3,0,1},
                     {1,2,3,0} }; 
struct loc_t {
  int x;
  int y:
  loc_t(int ix,int iy): x(ix), y(iy) {};
  loc_t(const loc_t& i): x(i.x), y(i.y) {};

};

struct Pods {  
  int upper_left;
  int r_state;
  loc_t locs[4];

  Pods(void): locs({loc_t(0,0),loc_t(1,0),loc_t(1,1),loc_t(0,1)}) {
    upper_left = 0;
    r_state = 0;
  }

};

void disp(room_t& room ) {

  cout << "Display room state..." << endl;



}





size_t clean(Pods& state, room_t& room){
  return 0;

}


vector<int> robotVacuum(room_t room, int maxDirt) {
  vector<int> result;

  size_t squares = room[0].size() * room.size();
  size_t cleaned = 0;
  Pods pod_state;

  while(cleaned < squares) {
    cleaned = clean(pod_state, room);


  }


 return result;

}


int main() {
  cout << "START" << endl;


  cout << "END" << endl;
 
};

