
"""
Given N * M string array of O's and X's
Return the number of 'X' total shapes. 'X' shape consists of one or more adjacent X's (diagonals not included).

OOOXOOO
OXXXXXO
OXOOOXO

answer is 1 , shapes are  :
(i)     X
    X X X X
    X     X


XXX
OOO
XXX

answer is 2, shapes are
(i)  XXX

(ii) XXX

01234
XXX XXX XXX
"""



def is_valid(index, data, visited):
    return ((index >=0 and index <len(data)) and (visited[index] == 0 and data[index] == "X") )


def update_queue(index, data,width,q,visited):
    line_end=data.find(" ", index)
    line_start = data.find(" ", index - width, index)

    if (index - 1) > line_start and not visited[index - 1]:
        q.append(index - 1)

    if (index + 1) < line_end and not visited[index + 1]:
        q.append(index + 1)

    if (index + width + 1) < len(data) and not visited[index + width + 1]:
        q.append(index + width + 1)

    if (index - (width + 1)) > 0 and not visited[ (index - (width + 1))]:
        q.append(index - (width + 1))


def _fill(index, data, visited, width, adj = []):
    update_queue(index, data,width,adj,visited)

    while adj:
        a = adj.pop()
        if is_valid(a, data, visited):
            visited[a] = 1
            _fill(a, data, visited, width, adj)
        else:
            visited[a] = 1


def exec(input):
    width = input.find(" ")
    visited = [0 for i in range(len(input))]
    cnt = 0

    for index, x in enumerate(input):
        if visited[index] == 0:
            visited[index] = 1
            if x == 'X':
                cnt += 1
                _fill(index, input, visited, width)
    return cnt

