# NOTE: Coordinate arrays are in the format of [y,x]



def build_visted_map(stage):
    return ([[0 for i in range(len(stage[0]))] for j in range(len(stage))])


def find_start(stage):
    for y, row in enumerate(stage):
        if "S" in row:
            x = row.find("S")
            return [y,x]


def fall_move(start, stage, v_map):

    x = start[1]
    y = start[0]
    max_y = len(stage)-1
    v_map[y][x] = 1

    # Loop until we have fallen as much as we can
    # or until we are one level above bottom
    while y < max_y-1 and (stage[y+1][x] == ' '):
        print ("C: ", stage[y][x])
        if v_map[y+1][x] == 0:
             y += 1
             v_map[y][x] = 1
        else:
            # Visited
            return None

    # See if we are back where we are started or at the end
    if y <= (max_y - 1) and (stage[y + 1][x] == 'S'):
        return None
    elif y <= (max_y - 1) and ((stage[y + 1][x] == 'E') or (stage[y + 1][x] == ' ')):
        y += 1
        v_map[y][x] = 1

    return [y, x]



def find_possible_moves(start, stage, v_map):

    p_moves = []

    return p_moves











def dejumpingGaps(stage):
    v_map = build_visted_map(stage)

    start = find_start(stage)