from math import ceil

# Max number of swipes = (Dirties Spot / MaxClean * 1.0)




def analyze_room(room,maxDirt):

    dirtiest = 0
    total = 0
    for row in room:
        for node in row:
            total += node
            if node>dirtiest:
                dirtiest = node


    passes = ceil(dirtiest/(maxDirt *1.0))


    return {"remaining": total, "passes": passes }




POD_STATES = [
    [[0,0], [1,0], [1,1], [0,3]],
    [[1,0], [1,1], [0,3], [0,0]],
    [[1,1], [0,3], [0,0], [1,0]],
    [[1,0], [1,1], [0,3], [0,0]]
]


def calc_location(moves, room):
    y = moves/len(room[0])





def look_up_pod_state(move):
    return POD_STATES[move]




def find_moves_to_end_of_row(room):
    return len(room[0]) - 2

def find_moves_to_travese_room(room):
    return find_moves_to_end_of_row(room) * len(room)


def find_moves_to_repeat_space(room):
    ret_val = find_moves_to_travese_room(room)

    return ret_val


def find_state(current_state, move_cnt ):
    return POD_STATES[(move_cnt%4)]






start_position (x,y)




def robotVacuum(room, maxDirt):

    stats = analyze_room(room, maxDirt)


    moves_to_repeat = find_moves_to_travese_room(room) * 2

    forward_pass =True


    while stats["remaining"] > 0:



        pass














