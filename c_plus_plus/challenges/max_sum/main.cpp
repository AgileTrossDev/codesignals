/*
 * Given array of integers, find the maximal possible sum of some of its k consecutive elements.
 *
 * Example
 *
 * For inputArray = [2, 3, 5, 1, 6] and k = 2, the output should be
 * arrayMaxConsecutiveSum(inputArray, k) = 8.
 * All possible sums of 2 consecutive elements are:
 *
 *     2 + 3 = 5;
 *         3 + 5 = 8;
 *             5 + 1 = 6;
 *                 1 + 6 = 7.
 *                     Thus, the answer is 8.
 *
 *                     Input/Output
 *
 *                         [execution time limit] 0.5 seconds (cpp)
 *
 *                             [input] array.integer inputArray
 *
 *                                 Array of positive integers.
 *
 *                                     Guaranteed constraints:
 *                                         3 ≤ inputArray.length ≤ 105,
 *                                             1 ≤ inputArray[i] ≤ 1000.
 *
 *                                                 [input] integer k
 *
 *                                                     An integer (not greater than the length of inputArray).
 *
 *                                                         Guaranteed constraints:
 *                                                             1 ≤ k ≤ inputArray.length.
 *
 *                                                                 [output] integer
 *                                                                         The maximal possible sum
 */
#include <vector>

#define INT_MIN 0

int arrayMaxConsecutiveSum(std::vector<int> inputArray, int k) { 
   int max_sum = INT_MIN;
   int running_sum = 0;
   
   for(int i=0;i<k;i++)
      running_sum += inputArray[i];
   
   max_sum = running_sum;

   int i = 0;  
   for (int j = k;j < inputArray.size(); j++) {
      running_sum = running_sum - inputArray[i];
      i++;
      running_sum = running_sum + inputArray[j];
      max_sum = std::max(running_sum, max_sum);    
   }

   return max_sum;

}
int main(void) {





}
