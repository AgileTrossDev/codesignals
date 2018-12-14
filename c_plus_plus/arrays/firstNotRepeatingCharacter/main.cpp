// Lessons Learned:
// Once again I misiterpretted the requirements.  I was shooting for O(N), but really the requirement was iterate
// over the string once.  I wasn't sure how the test was being graded, so I just started with a brute force, O(N)
// solution, hoping that 2N would be interpretted as N.  Turns out my solution passes, however it could be more
// effecient.  I was looping over the string twice here. I could have done a O(NM) algorithm, which probably
// would have been allowed.  Where M would be the size of my tracking datastructure, which could have been
// sorted better, so that M <N.  


// Note: Write a solution that only iterates over the string once and uses O(1) additional memory, since this is what
// you would be asked to do during a real interview.
// 
// Given a string s, find and return the first instance of a non-repeating character in it. If there
// is no such character, return '_'.
// 
// Example
// 
// For s = "abacabad", the output should be
// firstNotRepeatingCharacter(s) = 'c'.
// 
// There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.
// 
// For s = "abacabaabacaba", the output should be
// firstNotRepeatingCharacter(s) = '_'.
// 
// There are no characters in this string that do not repeat.
// 
// Input/Output
// 
// [time limit] 500ms (cpp)
// [input] string s
// 
// A string that contains only lowercase English letters.
// 
// Guaranteed constraints:
// 1 ≤ s.length ≤ 105.
// 
// [output] char
// 
// The first non-repeating character in s, or '_' if there are no characters that do not repeat.

#include <vector>
#include <utility> 
#include <iostream>

using std::cout;
using std::endl;

char firstNotRepeatingCharacter(std::string s) {
   // cout << "STRING: " << s << endl;
    char ret_val = '_';
  
    std::vector<std::pair<int, int> > counter (26, std::make_pair(0, 0));
    int current_pick = s.size()+1;

    for (int i= 0;i <s.length();++i ){
        //cout << (s[i]-'a') << endl;
        //counter[(s[i]-'a')].second = counter[(s[i]-'a')].second+1;
        if((counter[(s[i]-'a')].second++) == 1) {
            
            counter[(s[i]-'a')].first = i;
            //cout << "First courrence of " << s[i] << " " << i <<endl;
        }
        
    }
    
    for (int i= 0;i <s.length();++i ){
        //cout << (s[i]) << " " << (counter[(s[i]-'a')].first) << " " << (counter[(s[i]-'a')].second) << endl;
        counter[(s[i]-'a')].first = i;
        if ( (counter[(s[i]-'a')].second == 1) && (counter[(s[i]-'a')].first < current_pick))
            current_pick = counter[(s[i]-'a')].first;
        
    }
    
    return (current_pick == (s.size()+1) ? '_' : s[current_pick]);

}

int main (void) {
   cout << firstNotRepeatingCharacter( "abacabaabacaba") << endl;
    cout << firstNotRepeatingCharacter( "abacabad") << endl;
    
}