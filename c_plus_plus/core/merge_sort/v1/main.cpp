#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


typedef vector<int> vi_t;


vi_t merge_sort_util(vi_t &list_to_sort, int f, int c) {
    if (c-f == 1) {
        cout << "RETURNING: " << list_to_sort[c] << " " << c << " " << f << "-" << c << endl;
        vi_t tmp = {list_to_sort[f]};
        return tmp;
    }

    // Step 1: divide the list in half
    // We use integer division, so we'll never get a "half index"
    int mid_index = f+ ((c-f) / 2);
    
    cout << "ROUND: " << f << "-" << c << " |" << mid_index << " --> " << list_to_sort[mid_index] << endl;
    
    // Step 2: sort each half
    vi_t left  = merge_sort_util(list_to_sort, f, mid_index);
    vi_t right = merge_sort_util(list_to_sort, mid_index, c);

    // Step 3: merge the sorted halves
    vi_t sorted_list;
    int current_index_left = 0;
    int current_index_right = 0;

    // left's first element comes next if it's less than right's first element or if right is exhausted
    while (sorted_list.size() < (left.size() + right.size())) {
        if (current_index_left < left.size() && current_index_right >= right.size())  {
            sorted_list.push_back(left[current_index_left]);
            current_index_left += 1;
        } else if (current_index_left >= left.size() && current_index_right < right.size()) {
            sorted_list.push_back(right[current_index_right]);
            current_index_right++; 
        } else if (left[current_index_left] < right[current_index_right]) {
            sorted_list.push_back(left[current_index_left]);
            current_index_left += 1;
       }  else {
	    sorted_list.push_back(right[current_index_right]);
            current_index_right++;
       }
    }
    return sorted_list;
}


vi_t merge_sort(vi_t &list_to_sort) {
    // Base case: lists with fewer than 2 elements are already sorted
    if (list_to_sort.size()< 2) return list_to_sort;
    return merge_sort_util(list_to_sort,0,list_to_sort.size());
}



void disp(vi_t &v) {
   for (int i =0;i<v.size();i++) {
       cout << v[i] << " ";
   }  

  cout << endl;

}

void tc_1(){
   vi_t input = {5,3,7,8,1,2,4,9,0,6};
   disp(input);
   vi_t result = merge_sort(input);
   disp(result);


}

int main(void) {
  tc_1();          


}
