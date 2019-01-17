import math

def build_list(n):
 r = []
 for i in range(n-1):
    a = []
    for j in range(i+1,n):
      a.append(j)
    r.append(a)
    
 return r
 

def find_combo(val):
  if val == 1:
    return 1
  if val%2 == 1:
    return 2

  r = []
  for i in range(1,math.ceil(math.sqrt(val))+1):
    c = val/i
    if c.is_integer():
      if i not in r:
        r.append(i)
      if int(val/i) not in r:
        r.append(int(val/i))

  return len(r)
 
 
def check_set(cnt,visted,best):
  if cnt not in visted:
    tmp = find_combo(cnt)
    visted.append(cnt)
    if cnt < best[0] and tmp == best[1]:
      best[0] = cnt
    elif tmp>best[1]:
      best[0] = cnt
      best[1] = tmp
      
  return best


# Appends next step to path and returns new path value
def move_to_next_node(path, stack, cnt, input):
  while len(path)> 0 and path[-1] == stack[-1]:
    # We have explored all links from this node
    cnt = cnt - input[path[-1]]
    path.pop()
    stack.pop()
    #print("POPPED: {} {} ".format(path, stack))

  if len(stack) >0:
    # Add next node to try to path
    path.append(stack[-1])
    cnt  =  (cnt + input[path[-1]])

  return cnt


# Input - Array containing bag info
# Start - Starting index of traverse
# Graph - Array or Arrays contianings node links
# Set   - Totals that have already been calculated
# Best  - array[0] = cnt, array[1] = matches
def traverse(input,start,graph,visted,best):

    # Tracks progress of BFS path from this start location and total cnt
    stack = [start]
    path = []
    cnt = 0
    loops = 0
    # Loop over links from stemming from start node
    # Update Set and append Node to stack
    while len(stack) > 0:            
        loops +=1
        #print("TOP: {} {} {} {}".format(path,stack,cnt,visted))
        cnt = move_to_next_node(path, stack, cnt, input)    

        if len(path) == 0 or path[-1] >= len(graph):
          #print("TERM")
          continue
           
        for link in graph[path[-1]]: 
          best = check_set((cnt + input[link]), visted, best)
          #print("PUSHING: {}".format(link))
          stack.append(link)



    return best
    
    
def kinderLevon(input):
 
  if len(input) == 1:
    return input[0]

  # Build list of all links in the graph
  graph = build_list(len(input))
  
  # A set of cnts previous calculated
  visted = []
  
  # array[0] = best cnt, array[1] = high matches
  best = [0,0]
  
  # Traverse Each Node
  for index,val in enumerate(input):
    best = traverse(input, index, graph, visted, best)
      
  return best[0]
