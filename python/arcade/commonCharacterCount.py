"""

Given two strings, find the number of common characters between them.

Example

For s1 = "aabcc" and s2 = "adcaa", the output should be
commonCharacterCount(s1, s2) = 3.

Strings have 3 common characters - 2 "a"s and 1 "c".

Input/Output

[execution time limit] 4 seconds (py3)

[input] string s1

A string consisting of lowercase English letters.

Guaranteed constraints:
1 ≤ s1.length ≤ 15.

[input] string s2

A string consisting of lowercase English letters.

Guaranteed constraints:
1 ≤ s2.length ≤ 15.

[output] integer

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


def commonCharacterCount(s1, s2):

  h1 = build_hash(s1)
  h2 = build_hash(s2)

  sh = [h2,h1] if (len(h1) > len(h2)) else [h1,h2]

  ret_val = 0
  for key, val in sh[0].items():
    if key in sh[1]:
      ret_val += val if val < sh[1][key] else sh[1][key]
  

  return ret_val






 
  pass



