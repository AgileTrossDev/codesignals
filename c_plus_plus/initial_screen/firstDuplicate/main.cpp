// First attempt i knew it was too slow, and it didn't pass unit test.  They were requesting O(n) and constant memory.
// To tract duplicates in a separate array was constant M because the inputs were limited.


// Note: Write a solution with O(n) time complexity and O(1) additional space complexity, since this is what
// you would be asked to do during a real interview.
// 
// Given an array a that contains only numbers in the range from 1 to a.length, find the first duplicate number
// for which the second occurrence has the minimal index. In other words, if there are more than 1 duplicated
// numbers, return the number for which the second occurrence has a smaller index than the second occurrence of
// the other number does. If there are no such elements, return -1.
// 
// Example
// 
// For a = [2, 3, 3, 1, 5, 2], the output should be
// firstDuplicate(a) = 3.
// 
// There are 2 duplicates: numbers 2 and 3. The second occurrence of 3 has a smaller index than than second occurrence of 2 does, so the answer is 3.
// 
// For a = [2, 4, 3, 5, 1], the output should be
// firstDuplicate(a) = -1.
// 
// Input/Output
// 
// [time limit] 500ms (cpp)
// [input] array.integer a
// 
// Guaranteed constraints:
// 1 ≤ a.length ≤ 105,
// 1 ≤ a[i] ≤ a.length.
// 
// [output] integer
// 
// The element in a that occurs in the array more than once and has the minimal index for its second occurrence. If there are no such elements, return -1.



#include <vector>

int firstDuplicate_slow(std::vector<int> a) {
    int dup_index = a.size()+1;
    for (int itr_1 = 0; itr_1 < a.size();++itr_1) {
        for (int itr_2 = (itr_1+1); itr_2 < a.size();++itr_2){
            if ((a[itr_1] == a[itr_2] )  && itr_2  < dup_index) {
                dup_index= itr_2;
            }
        }
    }
    
    return (dup_index<(a.size()+1) ? a[dup_index] : -1 );

}
int firstDuplicate(std::vector<int> a) {
    int dup_index = a.size()+1;
    
    std::vector<int> counter((a.size()+1),0);
    
    for (int itr_1 = 0; itr_1 < a.size();++itr_1) {
       if (counter[a[itr_1]] == 1 && itr_1 < dup_index) {
        dup_index = itr_1;
       } else {
        counter[a[itr_1]]++;
       }
    }
    
    return (dup_index<(a.size()+1) ? a[dup_index] : -1 );

}



int main (void) {
    
    
}


