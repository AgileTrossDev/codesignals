#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::vector;
using std::cout;
using std::endl;

typedef vector<int> connections_t;
typedef vector<connections_t> adj_lst_t;
typedef vector<bool> visited_t;
typedef stack<int> tracker_t;

bool is_connected(adj_lst_t &adj_list, int start, int finish) {
   visited_t visited(adj_list.size(), false);
   tracker_t tracker;

   if (start == finish) return true;
   tracker.push(start);

   while(!tracker.empty()){
       int cur = tracker.top();
       tracker.pop();
       if (visited[cur]) continue;
       visited[cur] = true;
       for (int i =0;i<adj_list[cur].size();i++){
         if (adj_list[cur][i] == finish) return true;
         tracker.push(adj_list[cur][i]);
         
       }
    }

    return false;

}




void tc_3() {

     adj_lst_t adj = {
            {1},   // 0
            {2,1},   // 1
            {1,2},   // 2
            {4,3},   // 3
            {1,3},   // 4

   };

   bool result = is_connected(adj,0,4);
   cout << "TC 3 RESULT: " << result << endl;




}



void tc_2() {

     adj_lst_t adj = {
            {1},   // 0
            {2,1},   // 1
            {3,2},   // 2
            {4,3},   // 3
            {1,3},   // 4

   };

   bool result = is_connected(adj,0,4);
   cout << "TC 2 RESULT: " << result << endl;




}


void tc_1(){

   adj_lst_t adj = {
            {1,5,8},   // 0
            {0,9,2},   // 1
            {6,7,9},   // 2
            {1,5,8},   // 3
            {2,5,8},   // 4
            {3,7,6},   // 5
            {5,1,2},   // 6
            {6,3,7},   // 7
            {4,2,3},   // 8
            {0,3,2}    // 9
 
   };

   bool result = is_connected(adj,0,9);
   cout << "TC 1 RESULT: " << result << endl;
}


int main(void){
   tc_1();
   tc_2();
   tc_3();

}
