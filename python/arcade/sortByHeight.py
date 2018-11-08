"""
Some people are standing in a row in a park. There are trees between them which cannot be moved. Your task is to rearrange
the people by their heights in a non-descending order without moving the trees. People can be very tall!

Example

For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190].

Input/Output

[execution time limit] 4 seconds (py3)

[input] array.integer a

If a[i] = -1, then the ith position is occupied by a tree. Otherwise a[i] is the height of a person standing in the ith position.

Guaranteed constraints:
1 ≤ a.length ≤ 1000,
-1 ≤ a[i] ≤ 1000.

[output] array.integer

Sorted array a with all the trees untouched.

[Python3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name



"""
def is_bigger(x,y):
 # Returns true if X is greater than Y 
 return False if (x<y) else True

def can_swap(x,y):
  # Returns False if either value is -1
  return False if (-1 in [x,y]) else True

def swap(alist,x,y):
  temp = alist[x]
  alist[x] = alist[y]
  alist[y] = temp  

def quickSortHelper(alist,first,last):
   
  # Skip over trees in pivot points
  while (first<last and -1 == alist[first]  ):
    first +=1
   
  if first<last:
    # indexes haven't overlapped, so continue sorting
    splitpoint = partition(alist,first,last)
    quickSortHelper(alist,first,splitpoint-1)
    quickSortHelper(alist,splitpoint+1,last)
   

def find_leftmark(leftmark, rightmark, alist, pivotvalue):
  while leftmark <= rightmark and (not is_bigger(alist[leftmark], pivotvalue) or (not is_bigger(alist[leftmark], pivotvalue))):
    leftmark += 1
    
  return leftmark
  
  
def find_rightmark(leftmark, rightmark, alist, pivotvalue):
  while rightmark >= leftmark and (is_bigger(alist[rightmark], pivotvalue) or  not can_swap(alist[rightmark], pivotvalue)):
    rightmark = rightmark -1

  return rightmark


def partition(alist,first,last):

  pivotvalue = alist[first]
  print("First Pivot: ",pivotvalue )

  leftmark = first+1
  rightmark = last

  done = False
  while not done:
    leftmark =  find_leftmark(leftmark, rightmark, alist, pivotvalue)
    rightmark = find_rightmark(leftmark, rightmark, alist, pivotvalue)
      
    if rightmark < leftmark:
      done = True
    elif (can_swap(alist[leftmark],alist[rightmark])):
       swap(alist,leftmark,rightmark) 

  # Place Pivot value into final location
  if (can_swap(alist[first],alist[rightmark])):
    swap (alist,first,rightmark)
  
  return rightmark


def sortByHeight(a):
  # Modified Quick Sort input
  quickSortHelper(a,0,len(a)-1)
  return a



### MAIN ####

input = [-1, 150, 190, 170, -1, -1, 160, 180]
print(input)

#print(is_bigger(180,150))
#print(can_swap(180,150))

#print(find_leftmark(2, 7, input, 150))
#print(find_rightmark(2, 7, input, 150))



print(find_leftmark(3, 7, input, 190))


#print(partition(input,1,7))
#print("Second....")
#print(partition(input,2,7))


print("\n\n\n...\n\n")



res = sortByHeight(input)
print(res)