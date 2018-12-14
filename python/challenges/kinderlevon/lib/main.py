
def build_links(num_of_nodes):
    ret_val = []
    for i in range(num_of_nodes-1):
        ret_val.append([])
        for l in range(i+1,num_of_nodes):
            ret_val[i].append(l)

    return ret_val


def calc_children(num):
    ret_val = 0
    if num == 1:
        ret_val = 1
    elif num%2 == 1:
        ret_val = 2
    else:
        ret_val = num


    return ret_val

def traverse(bags, node, adj, ):
    pass

def kinderLevon(bags):

    best = 0, 0

    adj = build_links(len(bags))


