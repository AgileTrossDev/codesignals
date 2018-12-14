// Given an array of integers, find the maximum possible sum you can get from
// one of its contiguous subarrays. The subarray from which this sum comes must
// contain at least 1 element.
// 
// Example
// 
// For inputArray = [-2, 2, 5, -11, 6], the output should be
// arrayMaxConsecutiveSum2(inputArray) = 7.
// 
// The contiguous subarray that gives the maximum possible sum is [2, 5], with a sum of 7.
// 
// Input/Output
// 
// [time limit] 500ms (cpp)
// [input] array.integer inputArray
// 
// An array of integers.
// 
// Guaranteed constraints:
// 3 ≤ inputArray.length ≤ 105,
// -1000 ≤ inputArray[i] ≤ 1000.
// 
// [output] integer
// 
// The maximum possible sum of a subarray within inputArray.

int arrayMaxConsecutiveSum2(std::vector<int> inputArray) {
  
  int maxsum = 0, i=0,j=0;
  
  
  while (i<inputArray.size()) {
    
    maxsum = maxsum + inputArray[i];
    i++;
    
    // Quickly fast forward over values increasing the maxsum
    while(i<inputArray.size() && maxsum +(inputArray[i+1]) > maxsum)
      maxsum = maxsum + inputArray[++i];
    
    // Quickly trim start values decreasing the maxsum
    while(j<inputArray.size() && (maxsum -inputArray[j]) > maxsum)
      maxsum = maxsum - inputArray[j++];
    
    
    
    
  }
  

}