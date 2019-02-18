#include<iostream>
#include<vector>
#include "meeting.cpp"

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::max;

typedef vector<Meeting> sched_t;


sched_t merge_schedules_util(const sched_t &s, size_t f, size_t c) {
    
    // Step 0: Check for recusion base case
    if (c-f == 1) {
        sched_t tmp = {s[f]};
        return tmp;
    }

    // Step 1: divide the list in half
    // We use integer division, so we'll never get a "half index"
    size_t mid_index = f+ ((c-f) / 2);
    
    // Step 2: sort each half
    sched_t left  = merge_schedules_util(s, f, mid_index);
    sched_t right = merge_schedules_util(s, mid_index, c);

    
    // Step 3: merge the sorted halves
    sched_t sorted_list;
    size_t current_index_left = 0;
    size_t current_index_right = 0;
    int sorted_cnt = 0;

    // left's first element comes next if it's less than right's first element or if right is exhausted
    while (sorted_cnt < (left.size() + right.size())) {
        if (current_index_left < left.size() && current_index_right >= right.size())  {
            //cout << "No More elements on Right, so just add Left" << endl;
            if(sorted_list.back().getEndTime() < left[current_index_left].getStartTime()) {
                sorted_list.push_back(left[current_index_left]);
            } else {
                sorted_list.back().setEndTime(left[current_index_left].getEndTime());
            }
            current_index_left += 1;
            sorted_cnt++;
        } else if (current_index_left >= left.size() && current_index_right < right.size()) {
            //cout << "No more elements on Let, so just add Right"<< endl;
            if(sorted_list.back().getEndTime() < right[current_index_right].getStartTime()) {
                sorted_list.push_back(right[current_index_right]);
            } else {
                sorted_list.back().setEndTime(right[current_index_right].getEndTime());
            }
            current_index_right++;
            sorted_cnt++;
        } else if (left[current_index_left].getStartTime() < right[current_index_right].getStartTime() && left[current_index_left].getEndTime() < right[current_index_right].getStartTime() ) {
            //cout <<  "No over-lap and Left is the best" << endl;
            sorted_list.push_back(left[current_index_left]);
            current_index_left += 1;
            sorted_cnt++;
       }  else if (left[current_index_left].getStartTime() > right[current_index_right].getStartTime() && right[current_index_right].getEndTime() < left[current_index_left].getStartTime() )  {
            //cout << "No over-lap and Right is the best" << endl;
            sorted_list.push_back(right[current_index_right]);
            current_index_right++;
            sorted_cnt++;
       } else {
           //cout << "MERGING " << endl;
            int start = min( right[current_index_right].getStartTime(),left[current_index_left].getStartTime());
                int finish = max( right[current_index_right].getEndTime(),left[current_index_left].getEndTime());
            Meeting new_t(start,finish);
            sorted_list.push_back(new_t);
            current_index_left++;
            current_index_right++;
            sorted_cnt++;
            sorted_cnt++;
       }
    }
    return sorted_list;

}

sched_t merge_schedules(const sched_t &s) {
      if (s.size() <2) return s;
      return  merge_schedules_util(s,0,s.size());
}


void disp_meeting (const sched_t &s) {
   for(int i = 0; i<s.size();i++){
       cout << s[i].getStartTime() << " " << s[i].getEndTime() << endl;
   }
}

int main(void){
  cout << "START" << endl;
  vector<Meeting> v = {Meeting(0, 1), Meeting(3, 5), Meeting(4, 8), Meeting(10, 12), Meeting(9, 10)};

  cout << "ORIGINAL:" << endl;
  disp_meeting(v);
  sched_t result = merge_schedules(v);

  cout << "\nFINAL: " << endl;
  disp_meeting(result);
    
    
    
    // Test Case 2:
    const auto meetings = vector<Meeting> {Meeting(1, 10), Meeting(2, 5), Meeting(6, 8),
        Meeting(9, 10), Meeting(10, 12)};
    
    
    cout << "TC 2" << endl;
    cout << "Original: " << endl;
    disp_meeting(meetings);
    
    cout << "Actual: " << endl;
    const auto actual = merge_schedules(meetings);
    disp_meeting(actual);
    
    const auto expected = vector<Meeting> {Meeting(1, 12)};
    cout << "Expected: " << endl;
     disp_meeting(expected);
   

  cout << "END" << endl;

}
