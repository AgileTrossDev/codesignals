"""
You are given an array of integers. On each move you are allowed to increase
exactly one of its element by one. Find the minimal number of moves required
to obtain a strictly increasing sequence from the input.

Example

For inputArray = [1, 1, 1], the output should be
arrayChange(inputArray) = 3.

Input/Output

[execution time limit] 4 seconds (py3)

[input] array.integer inputArray

Guaranteed constraints:
3 ≤ inputArray.length ≤ 105,
-105 ≤ inputArray[i] ≤ 105.

[output] integer

The minimal number of moves needed to obtain a strictly increasing sequence from inputArray.
It's guaranteed that for the given test cases the answer always fits signed 32-bit integer type.

[Python3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name
"""

def find_largest(input):
  ret = 0
  val = -10000
  for i in range(len(input)):
    if (input[i] > val):
      ret =i
      val = input[i]
    

def cal_largest(input, li):
  return inputArray[li] + (len(inputArray)-1 - li) 
  


def arrayChange(inputArray):

  moves_count = 0
  
  for i in range(1,len(inputArray)):
    if (inputArray[i-1] >= inputArray[i]): 
      moves_count += inputArray[i-1] - inputArray[i] +1
      inputArray[i] = inputArray[i-1]+1
    
  return moves_count
  
  
  
  


inputArray = [1, 1, 1]
print("RESULT: ", arrayChange(inputArray))


  
  
  


