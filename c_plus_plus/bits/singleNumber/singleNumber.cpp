int singleNumber(std::vector<int> nums) {
  int res = 0;
  for (int num : nums) {
    // XORing all numbers.  Pairs will cancel,
    // and the singe/odd/non-pair will not 
    // cancel.
    res = res^num;
  }
  return res;
}
