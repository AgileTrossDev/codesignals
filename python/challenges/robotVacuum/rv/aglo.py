class Pod:

    def __init__(self, x, y, s):
        self.total = 0
        self.loc_x = x
        self.loc_y = y
        self.spot = s

    def collect(self, amt):
        self.total += amt

    def move(self, d, m):
        if d == RobVac.HORIZONTAL:
            self.loc_x += m
        else:
            self.loc_y += m

        if self.spot == 0:
            self.loc_x += 1
        if self.spot == 1:
            self.loc_y += 1
        if self.spot == 2:
            self.loc_x -= 1
        if self.spot == 3:
            self.loc_y -= 1

        self.spot += 1
        if self.spot > 3:
            self.spot = 0


class RobVac:
    LEFT = -1
    RIGHT = 1
    UP = -1
    DOWN = 1
    HORIZONTAL = 0
    VERTICAL = 1

    def __init__(self, max_collect):
        self.pods=[Pod(0, 0, 0), Pod(1, 0, 1), Pod(1, 1, 2), Pod(0, 1, 3)]
        self.max_collect = max_collect
        self.last_move = self.HORIZONTAL
        self.direction = [1, 1]

    def get_pod_stats(self):
        ret_val = []
        for pod in self.pods:
            ret_val.append(pod.total)
        return ret_val

    def perform_pod_collect(self, the_pod, board):
        ret_val = False
        if board[the_pod.loc_y][the_pod.loc_x] > self.max_collect:
            # Clean max dirt, someone else will have to clean the rest
            board[the_pod.loc_y][the_pod.loc_x] -= self.max_collect
            the_pod.collect(self.max_collect)
        elif board[the_pod.loc_y][the_pod.loc_x] == 0:
            # Found uncounted clean square
            ret_val = True
            board[the_pod.loc_y][the_pod.loc_x] = -1
        elif board[the_pod.loc_y][the_pod.loc_x] > 0:
            # We are about to clean a square!
            the_pod.collect(board[the_pod.loc_y][the_pod.loc_x])
            ret_val = True
            board[the_pod.loc_y][the_pod.loc_x] = -1

        return ret_val


    def find_pod(self,spot):
        ret_val = -1
        for i, pod in enumerate(self.pods):
            if spot == pod.spot:
                ret_val = i
        return ret_val

    def right_boarder_check(self,board):
        i = self.find_pod(1)
        return self.pods[i].loc_x >= (len(board[0]) - 1)

    def left_boarder_check(self,board):
        i = self.find_pod(0)
        return self.pods[i].loc_x <= 0

    def top_boarder_check(self,board):
        i = self.find_pod(0)
        return self.pods[i].loc_y <= 0

    def bot_boarder_check(self,board):
        i = self.find_pod(2)
        return self.pods[i].loc_y >= (len(board) - 1)

    def next_dir(self, board):
        ret_val = 0
        if self.last_move == RobVac.HORIZONTAL:
            if not self.left_boarder_check(board) and not self.right_boarder_check(board):
                # Can move in either horizontal direction, so continue
                ret_val = self.direction[0]
            elif (self.left_boarder_check(board) and self.direction[0] == RobVac.RIGHT ) or\
                (self.right_boarder_check(board) and self.direction[0] == RobVac.LEFT):
                ret_val = self.direction[0]
            elif (self.left_boarder_check(board) or self.right_boarder_check(board)):

                # Reached horizontal boarder,
                self.direction[0] = self.direction[0] * -1

                if (self.top_boarder_check(board) and self.direction[1] == RobVac.UP) or\
                   (self.bot_boarder_check(board) and self.direction[1] == RobVac.DOWN):
                    # Reached horizontal boarder, but need to reverse vertical and horizontal
                    self.direction[1] = self.direction[1] * -1

                self.last_move = RobVac.VERTICAL
                ret_val = self.direction[1]
        else:
            # Last move was vertical, so now move horizontal
            self.last_move = RobVac.HORIZONTAL
            ret_val = self.direction[0]

        return ret_val

    def move(self, board):
        ret_val = 0
        d = self.next_dir(board)
        for the_pod in self.pods:
            if self.perform_pod_collect(the_pod, board):
                ret_val += 1
            the_pod.move(self.last_move, d)

        return ret_val


def robotVacuum(room, maxDirt):

    bot = RobVac(maxDirt)
    squares = len(room[0]) * len(room)
    cleaned = 0

    # Loop until board is clean
    while cleaned != squares:
        cleaned+=bot.move(room)

    return bot.get_pod_stats()


