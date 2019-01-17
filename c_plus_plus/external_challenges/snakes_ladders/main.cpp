#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <climits>

using std::vector;
using std::map;
using std::queue;
using std::cout;
using std::endl;
using std::make_pair;

typedef vector<int> edges_t;
typedef vector<edges_t> adj_t;
typedef vector<bool> visited_t;
typedef map<int,int> snakes_t;
typedef queue<int> tracker_t;
typedef map<int,int> best_t;

#define BOARD_WIDTH 6
#define BOARD_HEIGHT 5


void build_adj(adj_t &adj, snakes_t &snakes) { 

   for (snakes_t::iterator itr = snakes.begin(); itr != snakes.end(); itr++) {
      adj[itr->first].push_back(itr->second);

   } 

   for (int i=1; i<adj.size();i++) {
       if (!adj[i].empty()) continue;
       for (int j = i+1;j<i+7;j++) {
          if (j>30) break;
          adj[i].push_back(j);
       }
   }
}


void disp(adj_t &adj) {
   for (int i=1; i<adj.size();i++){
      cout << "NODE: " << i << " -> ";
      for (int j=0;j<adj[i].size();j++) {
         cout << adj[i][j] << " ";
      } 
      cout << endl;
   }
}


void init_best(best_t &best) {
   for (int i=0;i<BOARD_HEIGHT*BOARD_WIDTH+1;i++) {
       best[i] = INT_MAX;
   }
}

void disp_best(best_t &best) {
   best_t::iterator itr = best.begin();

   while(itr != best.end()) {
      cout << itr->first << ": " << itr->second << endl;
      itr++;
   }

}


void exec(snakes_t &snakes) {
  visited_t visited(BOARD_WIDTH*BOARD_HEIGHT+1, false);
  best_t best;
  
  adj_t adj(BOARD_WIDTH * BOARD_HEIGHT+1);
  build_adj(adj,snakes);
  disp(adj);

  init_best(best);
 
  tracker_t tracker;

  // Initial State of first roll
  for(int i =1; i < 7; i++) {
    tracker.push(i);
    best[i]  = 1;
  } 

  while (!tracker.empty()){

     // Process next unvisited location
     int cur_loc = tracker.front();
     tracker.pop();
     if (visited[cur_loc]) continue;
     visited[cur_loc] = true;

     cout << "PROCESSING LOC: " << cur_loc << " " << best[cur_loc] << endl;

     int next_roll = best[cur_loc] +1;
     cout << "NEXT ROLL: " << next_roll << endl;
     for (int i=0; i <  adj[cur_loc].size(); i++) {
        cout << "CHECKING: " << adj[cur_loc][i] << " B: " << best[adj[cur_loc][i]] << endl;       
        if(next_roll < best[adj[cur_loc][i]]){ 
             cout << "UPDATING: " <<adj[cur_loc][i] << endl;
             best[adj[cur_loc][i]] = next_roll;
        }
        tracker.push(adj[cur_loc][i]);
     } 


  }
  
   disp_best(best);
   cout << "RESULT: " << best[30] << endl;  



}


void test_case_1() {
   snakes_t snakes;
   snakes.insert(make_pair(11,26));
   snakes.insert(make_pair(3,22));
   snakes.insert(make_pair(5,8));
   snakes.insert(make_pair(20,29));
   snakes.insert(make_pair(27,1));
   snakes.insert(make_pair(21,9));

   exec(snakes);

}


int main(void) {

   test_case_1();



   cout << "EXITING..." << endl;

}
