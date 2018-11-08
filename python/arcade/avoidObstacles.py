"""
You are given an array of integers representing coordinates of obstacles situated on a straight line.

Assume that you are jumping from the point with coordinate 0 to the right. You are allowed only to
make jumps of the same length represented by some integer.

Find the minimal length of the jump enough to avoid all the obstacles.

Example

For inputArray = [5, 3, 6, 7, 9], the output should be
avoidObstacles(inputArray) = 4.

Check out the image below for better understanding:



Input/Output

[execution time limit] 4 seconds (py3)

[input] array.integer inputArray

Non-empty array of positive integers.

Guaranteed constraints:
2 ≤ inputArray.length ≤ 1000,
1 ≤ inputArray[i] ≤ 1000.

[output] integer

The desired length.

[Python3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name
"""

def find_largest_continguous(input):
  """
  Returns the length of the largest contiguous hop
  """
  gap =0
  current = 1
  for i in range(1,len(input)):
    if (input[i] - input[i-1] == 1):
      current +=1
    if (current>gap):
      gap = current
      
    # CONSIDER: Breaking early if gap spans past end
      
  return gap+1



def attempt(input, gap):
  
  print("Attempt: {} {} ".format( gap, input[-1]))
  
  location = gap
  index = 0
  while (location <= input[-1]):
    
    print ("  LOCAT: ",location)
    
    print("  PTR:",input[index])

    print("LOG:{} {} {} ".format(location,input[index], (location >input[index])))
    
    # Fast forward to next pending obstacle
    # CONSIDER: adding input to remember start
    while location >input[index]:
      index +=1
      print("  PTR:",input[index])

    print ("  INDEX: ",index)
    
    if (location == input[index] ):
      # Hit an obstacle
      return False
    
    # Max next Hop
    location += gap
    
  return True




def avoidObstacles(inputArray):
  print ("Input:",inputArray)
  
  # Sort Array and then find largest continguous block
  inputArray.sort()
  min_hop = find_largest_continguous(inputArray)
  
  # Now Attempt traversal until we find it.
  while not attempt(inputArray,min_hop):
    min_hop +=1
    
  
  return min_hop


### GRAVEYARD ####

# def find_start(inputArray, min_hop,prev = 0):
#   
#   for i in range(prev,len(inputArray)):
#     if (inputArray[i]> min_hop ):
#       return i
#       
#   return len(inputArray)
# 
# 
# def find_end(inputArray):
#   return inputArray[-1]


### Main ###

input = [5, 3, 6, 7, 9]
print(avoidObstacles(input))

print (" ")

input = [2,3]
print(avoidObstacles(input))

print(" ")

