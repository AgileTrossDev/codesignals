"""

In the popular Minesweeper game you have a board with some mines and those cells that don't contain a mine have
a number in it that indicates the total number of mines in the neighboring cells. Starting off with some
arrangement of mines we want to create a Minesweeper game setup.

Example

For

matrix = [[true, false, false],
          [false, true, false],
          [false, false, false]]
the output should be

minesweeper(matrix) = [[1, 2, 1],
                       [2, 1, 1],
                       [1, 1, 1]]
Check out the image below for better understanding:



Input/Output

[execution time limit] 4 seconds (py3)

[input] array.array.boolean matrix

A non-empty rectangular matrix consisting of boolean values - true if the corresponding cell contains a mine,
false otherwise.

Guaranteed constraints:
2 ≤ matrix.length ≤ 100,
2 ≤ matrix[0].length ≤ 100.

[output] array.array.integer

Rectangular matrix of the same size as matrix each cell of which contains an integer equal to the number of mines
in the neighboring cells. Two cells are called neighboring if they share at least one corner.

[Python3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name



"""


def minesweeper(matrix):

  result = [[0]*len(matrix[0]) for i in range(len(matrix))]

  for r, row in enumerate(matrix):
    for x,record in enumerate(matrix[r]):
      

      if (record == True):
        
        # Right side        
        if (x+1 < len(matrix[r])):
          result[r][x+1] =result[r][x+1]+ 1
          
          
        # Left Side
        if (x-1 >= 0):
          result[r][x-1] += 1
          
        # Bottom
        if (r+1 < len(matrix)):
          result[r+1][x] += 1
          
        
        # Top 
        if (r-1 >= 0):  
          result[r-1][x] += 1
          
        
        # Upper Left  
        if (r-1 >= 0 and x-1 >= 0) :  
          result[r-1][x-1] += 1
          
        
        # Upper Right
        if (r-1 >= 0 and x+1 <len(matrix[r])) :  
          result[r-1][x+1] += 1
          
          
        # Lower Ledt
        if (r+1  <len(matrix) and x-1 >= 0) :  
          result[r+1][x-1] += 1
          
        
        # Lower Right
        if (r+1 < len(matrix) and x+1< len(matrix[r])) : 
          result[r+1][x+1] += 1
          
         
  return result



### MAIN ###

matrix = [[True, False, False],
          [False, True, False],
          [False, False, False]]


print(minesweeper(matrix))