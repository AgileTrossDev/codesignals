/*
Takeaways
The main things you’re being asked to think about in this task are:

Arithmetic operations aren’t always constant time. Multiplying big numbers is much slower than multiplying small numbers.

Operations are not all the same speed. Integer modulus is very fast, addition and multiplication are fast, while division is (relatively) slow.

Some number theory: You can multiply the residues of numbers, instead of the numbers themselves. But you cannot divide by residues, or divide the residues unless you have certain guarantees about divisibility.

The idea of precomputing certain operations, which is where the prefixProduct comes in.

Other problems that use the cumulative or prefix techniques are finding the lower and upper quartiles of an array, or finding the equilibrium point of an array. (I cover prefix sums in a lot more detail in this article.)

https://codesignal.com/productexceptself-solution/

*/

int productExceptSelf(std::vector<int> nums, int m) {
    
      vector<int> prefixProduct (nums.size(),1);
      int suffixProduct = 1;    

      // setup the cumulative product from left and right
      for (int i =1; i<nums.size(); i++) {
        // Need parenthesis, as % has higher precedence than *
        prefixProduct[i] = (prefixProduct[i-1] * nums[i-1]) % m;      
      }  
   

  int total = 0;
  for (int i=nums.size()-1; i>=0;i--) {
    // start at the end, with prefixProduct -1
    // and scan right
    total += (prefixProduct[i]*suffixProduct) % m;
    
    // now multiply suffixProduct by the number that
    // was excluded
    suffixProduct = (suffixProduct * nums[i]) % m;
  }

  return total % m;

}



