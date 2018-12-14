CAR_LENGTH = 0
CAR_WIDTH = 1
VERTICAL = True
HORIZONTAL = False


def find_orientation(cd, ls):
    ret_val = HORIZONTAL
    if (ls[2] - ls[0] + 1 == cd[CAR_LENGTH] and ls[3] - ls[1] + 1 == cd[CAR_WIDTH]):
        ret_val = VERTICAL

    return ret_val


def check_for_open(start_y, start_x, end_y, end_x, pl, motion_y=1, motion_x=1):
    for y in range(start_y, end_y+motion_y, motion_y):
        for x in range(start_x, end_x+motion_x, motion_x):
            if pl[y][x] == 1:
                return False


    return True


def check_path( parkingLot, luckySpot, orientation):
    ret_val = False

    if orientation == VERTICAL:
        if (check_for_open(0, luckySpot[1], luckySpot[0], luckySpot[3], parkingLot) or
                check_for_open(len(parkingLot) - 1, luckySpot[0], luckySpot[2], luckySpot[3], parkingLot, -1, 1)):
            ret_val = True
    else:
        if (check_for_open(luckySpot[0], 0, luckySpot[2], luckySpot[1], parkingLot) or
                check_for_open(luckySpot[0], len(parkingLot[0]) - 1, luckySpot[2],  luckySpot[3], parkingLot, 1, -1)):
           ret_val = True

    return ret_val


def parkingSpot(carDimensions, parkingLot, luckySpot):
    orientation = find_orientation(carDimensions, luckySpot)
    if not check_for_open(luckySpot[0], luckySpot[2], luckySpot[1], luckySpot[3], parkingLot):
        return False
    return check_path(carDimensions, parkingLot, luckySpot, orientation)




