"""
You have a string s that consists of English letters, punctuation marks, whitespace characters,
and brackets. It is guaranteed that the parentheses in s form a regular bracket sequence.

Your task is to reverse the strings contained in each pair of matching parentheses, starting
from the innermost pair. The results string should not contain any parentheses.

Example

For string s = "a(bc)de", the output should be
reverseParentheses(s) = "acbde".

Input/Output

[execution time limit] 4 seconds (py3)

[input] string s

A string consisting of English letters, punctuation marks, whitespace characters and brackets. It
is guaranteed that parentheses form a regular bracket sequence.

Constraints:
5 ≤ s.length ≤ 55.

[output] string

[Python3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name
"""


def reversesub(s, begin, end):
  """
    Input: index location for start and end parentheses
  """
  return s[0:begin] + s[begin+1:end][::-1] + s[end+1:]
 

def reverseParentheses(s):
 
  sub_start = 0
 
  for i,c in enumerate(s):
    if (c == '('):
      sub_start =i
        
    if(c== ')'):
      s= reversesub(s,sub_start,(i))
      s= reverseParentheses(s)
      break
 
  return s
  
  
  
#        abcabcab(bac)  
#        012345678901234567890  
input = "abc(cba)ab(bac)c"

print("Input: ", input)
#print (reversesub("abcabcab(bac)c",8,12))




print("RESULT: ", reverseParentheses(input))
print("      : ","abcabcabcabc")