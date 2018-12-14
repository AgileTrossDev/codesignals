# NOTE: Coordinate arrays are in the format of [y,x]



def build_visted_map(stage):
    return ([[0 for i in range(len(stage[0]))] for j in range(len(stage))])


def find_start(stage):
    for y, row in enumerate(stage):
        if "S" in row:
            x = row.find("S")
            return [y,x]


def fall_move(start, stage, v_map):
    # Returns None if fallen some where it shouldn't or the location after Fall

    ("FALLING: {} {}".format(start[0],start[1]))

    x = start[1]
    y = start[0]
    max_y = len(stage)-1

    if(y <0):
        y = 0

    if v_map[y][x] == 1:
        #print("VISTED FALL")
        return None
    elif  stage[y][x] == "#":
        return None

    v_map[y][x] = 1

    # Loop until we have fallen as much as we can
    # or until we are one level above bottom
    while y < max_y-1 and (stage[y+1][x] == ' '):
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
    x = start[1]
    y = start[0]

    # Make sure we visited current location
    if v_map[y][x] == 0:
        v_map[y][x] = 1

    print("START: {} {} {} ".format(y, x,v_map[y][x] ))

    for mod_y in range(-3, 1):

        if stage[y+mod_y][x] == "#":
            # Hit a wall
            break
        print ("mod_y:", mod_y)
        # Loop over jump possibilieis and then add all the moves that
        # can be made from this y-coordinate (X-move plus Fall)
        for mod_x in range (-1, -4, -1):
            print ("x_mod",mod_x)
            if (x + mod_x) < 0:
                # Off Board
                break
            elif stage[y+mod_y][x+mod_x] == "#":
                # Hit a wall
                break

            print ("NEG GOOD: {} {}".format(y + mod_y, (x + mod_x)))

            res = fall_move([y + mod_y, x+mod_x], stage, v_map)
            if res is not None:
                print ("APPENDING: {}".format(res))
                p_moves.append(res)

        # Loop over jump possibilieis and then add all the moves that
        # can be made from this y-coordinate (X-move plus Fall)
        for mod_x in range (1, 4):
            print("x_mod", mod_x)
            if ((x + mod_x) >= len(stage[0])):
                # Off Board
                break
            elif stage[y+mod_y][x+mod_x] == "#":
                # Hit a wall
                break

            print ("POS GOOD: {} {}".format(y+mod_y,(x + mod_x)))

            res = fall_move([y+mod_y, x+mod_x], stage, v_map)
            if res is not None:
                print ("APPENDING: {}".format(res))
                p_moves.append(res)

    return p_moves


def build_adjancy_map(start,stage,v_map, list = {}):
    if stage[start[0]][start[1]] == "E":
        list["found"] = True

    list = {**list, **({start[0]: {start[1]: find_possible_moves(start, stage, v_map)}})}

    for new_node in list[start[0]][start[1]]:
        build_adjancy_map(new_node, stage, v_map, list)

    return list




def dejumpingGaps(stage):
    v_map = build_visted_map(stage)
    start = find_start(stage)
    list = build_adjancy_map(start,stage,v_map)


