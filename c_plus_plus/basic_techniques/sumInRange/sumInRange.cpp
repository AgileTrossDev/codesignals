// You have an array of integers nums and an array queries, where queries[i] is
// a pair of indices (0-based). Find the sum of the elements in nums from the
// indices at queries[i][0] to queries[i][1] (inclusive) for each query, then
// add all of the sums for all the queries together. Return that number modulo 109 + 7.
// 
// Example
// 
// For nums = [3, 0, -2, 6, -3, 2] and queries = [[0, 2], [2, 5], [0, 5]], the
// output should be
// sumInRange(nums, queries) = 10.
// 
// The array of results for queries is [1, 3, 6], so the answer is 1 + 3 + 6 = 10.
// 
// Input/Output
// 
// [time limit] 500ms (cpp)
// [input] array.integer nums
// 
// An array of integers.
// 
// Guaranteed constraints:
// 1 ≤ nums.length ≤ 105,
// -1000 ≤ nums[i] ≤ 1000.
// 
// [input] array.array.integer queries
// 
// An array containing sets of integers that represent the indices to query in the nums array.
// 
// Guaranteed constraints:
// 1 ≤ queries.length ≤ 3 · 105,
// queries[i].length = 2,
// 0 ≤ queries[i][j] ≤ nums.length - 1,
// queries[i][0] ≤ queries[i][1].
// 
// [output] integer
// 
// An integer that is the sum of all of the sums gotten from querying nums, taken modulo 109 + 7.

nt sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) {
  long long int result =0;

  
  std::vector<int> startIndex, endIndex;
  
  // Group sorted Start Indexes and End indexes
  for (int i = 0;i<queries.size();++i){
    startIndex.push_back(queries[i][0]);
    endIndex.push_back(queries[i][1]);   
  }
  
  sort (startIndex.begin(), startIndex.end());
  sort (endIndex.begin(), endIndex.end());
 
  // Perform the calculations by looping over entire input
  int mod =0,s_i= 0, e_i=0;
  for (int i = startIndex[s_i];i<nums.size();++i) {
   
    // Adjust the modifier for each query starting at this index
    //cout << "RES: " << result << " S:" << startIndex[s_i] << " E:" << endIndex[e_i] <<  " V:"; 
    while (s_i <startIndex.size() && startIndex[s_i] == i) {mod++; s_i++;} 
    
    // Update Sum
    //cout <<  nums[i]  << " M:";
    result = result + nums[i] * mod;
    
    // Decrement modifier for each query ending at this index
    //cout << mod << " NR:" << result << endl;
    while (e_i <endIndex.size() &&  endIndex[e_i] == i) {mod--; e_i++;}
    if (e_i >= endIndex.size()) break;
  }
  
  return ((1000000007+(result % 1000000007)) % 1000000007);
 
}
