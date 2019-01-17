#include<iostream>
#include<vector>
#include<algorithm>


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;


typedef vector<vector<int> > tracker_t;

std::string longestPalindromeSubsequence(std::string input) {
  
   tracker_t tracker(26);
   vector<int> max_p;
  
   // Build histogram
   for (int i = 0; i < input.length(); i++) {
        //cout << i << " " << input[i] << endl;
        if (input[i] == ' ') continue;
	int c = input[i] - 'A'; 
        tracker[c].push_back(i);
   }
   //cout <<"HISTOGRAM COMPLETE: " << tracker.size() << endl;
   //for(int i =0;i<tracker.size();i++)  cout << i << ": " << tracker[i].size() << endl;

 
   // Traverse historgram looking for potential palindromes
   for (int i = 0; i < tracker.size(); i++) {
     if (tracker[i].size() < 2) continue;
 
     //cout << "P-Found at " << i << endl;

     // Found next palindrome
     vector<int> tmp;
     tmp.push_back(tracker[i][0]); 
     tmp.push_back(tracker[i].back());
    
     int beg = tmp[0];
     int tail = tmp[1];

     //cout << "P-Found at " << i << ": " << tmp[0] << " - " << tmp[1] <<  endl; 

     // Now look for sub-palindromes contained with-in.
     for (int j = beg + 1; j < tail; j++) {
      if (input[j] == ' ') continue;
      int la = input[j]-'A';

      //cout << " LA " <<la << " : " << input[j] << " |  " << j << endl;
      // cout << "LOOKING AT:" << (char(la+'A')) << endl;
      //
      if (tracker[la].size() < 2) continue;
      //cout << " LA " <<la << " : " << input[j] << " |  " << j << endl;

      //  See if sub-palindrome fits within current window
      int s = 0; 
      int e = tracker[la].size()-1;
      //cout << " S: " << s << " " << e << endl;
      while (s < tracker[la].size() && tracker[la][s] < beg) s++;
      while (e >= 0 && tracker[la][e]>tail) e--;
      if (tracker[la][s]>beg && tail> tracker[la][e] && tracker[la][s] < tracker[la][e]) {
        // Adding sub-palindrome
        tmp.push_back(tracker[la][s]);
        tmp.push_back(tracker[la][e]);
        beg = tracker[la][s];
        tail = tracker[la][e];
      }
     }

     // Find mid....
     int mid_index= beg  + 1;
     tmp.push_back(mid_index);
     //cout << "STRING SIZE: " << tmp.size() << endl;
     if(tmp.size() > max_p.size()) max_p = tmp;

   }

   sort(max_p.begin(),max_p.end());
  
   string ret_val;
   for (int i=0;i<max_p.size();i++) {
     ret_val += input[max_p[i]];
   }

   return ret_val;
}


int main(void) {
   string result = longestPalindromeSubsequence("STAR DESTROYER");
   cout << "RESULT: " << result << endl;
}
