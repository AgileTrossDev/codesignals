"""
Given a string, find out if its characters can be rearranged to form a palindrome.

Example

For inputString = "aabb", the output should be
palindromeRearranging(inputString) = true.

We can rearrange "aabb" to make "abba", which is a palindrome.

Input/Output

[execution time limit] 4 seconds (py3)

[input] string inputString

A string consisting of lowercase English letters.

Guaranteed constraints:
1 ≤ inputString.length ≤ 50.

[output] boolean

true if the characters of the inputString can be rearranged to form a palindrome, false otherwise.

[Python3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name


"""


def build_hash(s):
  the_hash = {}

  for c in s:
    if c in the_hash:
        the_hash[c] += 1
    else:
        the_hash[c] = 1

  return the_hash
  
  
  

def palindromeRearranging(inputString):
  hash = build_hash(inputString)
  
  odds = 0
  
  for key,val in hash:
    if (val%2 != 0 ):
      odds +=1
      
    if (odds>1):
      return False
    
  
    
    
    
  return True
    
    

    



inputString = "aabb"

print("Result:", palindromeRearranging(inputString))
  
