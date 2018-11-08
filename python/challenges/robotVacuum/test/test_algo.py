from rv.aglo import Pod,RobVac,robotVacuum


class TestAlgo:

    def test_pod_construct(self):
        a = Pod(0, 0, 0)
        a = Pod(0, 1, 1)
        a = Pod(1, 0, 2)
        a = Pod(1, 1, 3)


    def test_pod_collect(self):
        a = Pod(0, 0, 0)
        assert a.total == 0
        a.collect(1)
        assert a.total == 1
        a.collect(5)
        assert a.total == 6

    def test_pod_move(self):
        a = Pod(0, 0, 0)
        assert a.loc_x == 0 and a.loc_y == 0 and a.spot == 0

        a.move(RobVac.HORIZONTAL,1)
        assert a.loc_x == 2 and a.loc_y == 0 and a.spot == 1

        a.move(RobVac.HORIZONTAL,1)
        assert a.loc_x == 3 and a.loc_y == 1 and a.spot == 2

        a.move(RobVac.HORIZONTAL, -1)
        assert a.loc_x == 1 and a.loc_y == 1 and a.spot == 3

        a.move(RobVac.VERTICAL, 1)
        assert a.loc_x == 1 and a.loc_y == 1 and a.spot == 0

        a.move(RobVac.VERTICAL, 1)
        assert a.loc_x == 2 and a.loc_y == 2 and a.spot == 1

        a.move(RobVac.VERTICAL, -1)
        assert a.loc_x == 2 and a.loc_y == 2 and a.spot == 2


    def test_RobVac_create(self):
        a = RobVac(5)
        assert a.max_collect == 5


    def test_get_pod_stats(self):
        a = RobVac(5)
        assert a.get_pod_stats() == [0,0,0,0]



    def test_right_boarder_check(self):
        a = RobVac(5)

        board=  [[0, 5, 4,10, 0, 8],
        [7, 2, 7, 4, 7, 2],
        [2, 2,10, 1, 7, 6]]

        assert not a.right_boarder_check(board)
        a.pods[1].loc_x = 1
        assert a.pods[1].loc_x == 1
        assert not a.right_boarder_check(board)
        a.pods[1].loc_x = 4
        assert a.pods[1].loc_x == 4
        assert not a.right_boarder_check(board)

        a.pods[1].loc_x = 5
        assert a.pods[1].loc_x == 5
        assert a.right_boarder_check(board)

        a.pods[1].loc_x = 6
        assert a.pods[1].loc_x == 6
        assert a.right_boarder_check(board)

    def test_left_boarder_check(self):
        a = RobVac(5)
        board = [[0, 5, 4, 10, 0, 8],
                 [7, 2, 7, 4, 7, 2],
                 [2, 2, 10, 1, 7, 6]]

        assert a.left_boarder_check(board)
        a.pods[0].loc_x = 1
        assert a.pods[0].loc_x == 1
        assert not a.left_boarder_check(board)
        a.pods[0].loc_x = 4
        assert a.pods[0].loc_x == 4
        assert not a.left_boarder_check(board)

        a.pods[0].loc_x = 5
        assert a.pods[0].loc_x == 5
        assert not a.left_boarder_check(board)


    def test_top_boarder_check(self):
        a = RobVac(5)
        board = [[0, 5, 4, 10, 0, 8],
                 [7, 2, 7, 4, 7, 2],
                 [2, 2, 10, 1, 7, 6]]


        assert a.top_boarder_check(board)

        a.pods[0].loc_y = 1
        assert a.pods[0].loc_y == 1
        assert not a.top_boarder_check(board)

        a.pods[0].loc_y = -1
        assert a.pods[0].loc_y == -1
        assert a.top_boarder_check(board)

        a.pods[0].loc_y = 4
        assert a.pods[0].loc_y == 4
        assert not a.top_boarder_check(board)

        a.pods[0].loc_y = 5
        assert a.pods[0].loc_y == 5
        assert not a.top_boarder_check(board)

    def test_bot_boarder_check(self):
        a = RobVac(5)
        board = [[0, 5, 4, 10, 0, 8],
                 [7, 2, 7, 4, 7, 2],
                 [2, 2, 10, 1, 7, 6]]

        assert not a.bot_boarder_check(board)

        a.pods[2].loc_y = 1
        assert a.pods[2].loc_y == 1
        assert not a.bot_boarder_check(board)

        a.pods[2].loc_y = -1
        assert a.pods[2].loc_y == -1
        assert not a.bot_boarder_check(board)

        a.pods[2].loc_y = 2
        assert a.pods[2].loc_y == 2
        assert a.bot_boarder_check(board)

        a.pods[2].loc_y = 3
        assert a.pods[2].loc_y == 3
        assert a.bot_boarder_check(board)


    def test_rv_next_dir(self):
        a = RobVac(5)
        board = [[0, 5, 4, 10, 0, 8],
                 [7, 2, 7, 4, 7, 2],
                 [2, 2, 10, 1, 7, 6]]

        print ("1st MOVE - Should be Horizontal to RIGHT")
        assert a.last_move == RobVac.HORIZONTAL
        assert not a.right_boarder_check(board)
        assert RobVac.RIGHT == a.next_dir(board)
        assert a.last_move == RobVac.HORIZONTAL

        print("2nd MOVE - Should be Horizontal to RIGHT")
        a.pods[0].loc_x = 1
        assert not a.right_boarder_check(board)
        assert RobVac.RIGHT == a.next_dir(board)
        assert a.last_move == RobVac.HORIZONTAL

        print("3rd Move - Should be Vertical Down")
        a.pods[1].loc_x = 5
        assert a.right_boarder_check(board)
        assert RobVac.DOWN == a.next_dir(board)
        assert a.last_move == RobVac.VERTICAL

        print("Third MOVE")
        assert RobVac.LEFT == a.next_dir(board)
        assert a.last_move == RobVac.HORIZONTAL

        print("Fourth MOVE")
        a.pods[0].loc_x = 4
        a.pods[0].loc_y = 2
        a.pods[1].loc_x = 5
        a.pods[1].loc_2 = 2
        a.pods[2].loc_y = 3
        a.pods[2].loc_x = 5
        a.direction[0] = RobVac.RIGHT
        assert a.bot_boarder_check(board)
        assert a.right_boarder_check(board)
        assert RobVac.UP == a.next_dir(board)
        assert a.last_move == RobVac.VERTICAL

    def test_rv_move(self):
        a = RobVac(5)
        board = [[0, 5, 4, 10, 0, 8],
                 [7, 2, 7, 4, 7, 2],
                 [2, 2, 10, 1, 7, 6]]

        assert a.pods[0].loc_x == 0
        assert a.pods[0].loc_y == 0
        assert a.pods[0].spot == 0

        assert a.pods[1].loc_x == 1
        assert a.pods[1].loc_y == 0
        assert a.pods[1].spot == 1

        assert a.pods[2].loc_x  == 1
        assert a.pods[2].loc_y == 1
        assert a.pods[2].spot == 2

        assert a.pods[3].loc_x  == 0
        assert a.pods[3].loc_y == 1
        assert a.pods[3].spot == 3

        a.move(board)

        assert a.pods[0].loc_x == 2
        assert a.pods[0].loc_y == 0
        assert a.pods[0].spot == 1

        assert a.pods[1].loc_x == 2
        assert a.pods[1].loc_y == 1
        assert a.pods[1].spot == 2

        assert a.pods[2].loc_x  == 1
        assert a.pods[2].loc_y == 1
        assert a.pods[2].spot == 3

        assert a.pods[3].loc_x  == 1
        assert a.pods[3].loc_y == 0
        assert a.pods[3].spot == 0

        print(board)
        assert [0, 5, 2, 5] == a.get_pod_stats()
        assert [[-1, -1, 4, 10, 0, 8],
                 [2, -1, 7, 4, 7, 2],
                 [2, 2, 10, 1, 7, 6]] == board



    def test_perform_pod_collect(self):
        board = [[0, 5, 4, 10, 0, 8],
                 [7, 2, 7, 4, 7, 2],
                 [2, 2, 10, 1, 7, 6]]

        a = RobVac(5)
        p = a.pods[0]

        assert a.perform_pod_collect(p,board)
        assert [0,0,0,0] == a.get_pod_stats()
        assert board[0][0] == -1

        p.loc_x = 1
        assert a.perform_pod_collect(p, board)
        print(board)
        assert [5, 0, 0, 0] == a.get_pod_stats()
        assert board[0][1] == -1

        p.loc_x = 2
        assert a.perform_pod_collect(p, board)
        print(board)
        assert [9, 0, 0, 0] == a.get_pod_stats()
        assert board[0][2] == -1

        p.loc_x = 3
        assert not a.perform_pod_collect(p, board)
        print(board)
        assert [14, 0, 0, 0] == a.get_pod_stats()
        assert board[0][3] == 5

    def test_robotVacuum(self):
        board = [[0, 5, 4, 10, 0, 8],
                 [7, 2, 7, 4, 7, 2],
                 [2, 2, 10, 1, 7, 6]]

        maxDirt = 10


        assert robotVacuum(board, maxDirt) == [18, 27, 13, 26]

        room = [[1, 8, 5, 4],
               [3, 4, 1, 0],
               [3, 5, 2, 1],
               [0, 2, 1, 4]]
        maxDirt =  3
        assert robotVacuum(room, maxDirt) == [8, 8, 13, 15]



        room = [[0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0]]
        maxDirt = 3
        assert robotVacuum(room, maxDirt) == [0, 0, 0, 0]

        room = [[5000 for column in range(3)] for row in range(3)]
        maxDirt = 1
        assert robotVacuum(room, maxDirt) == [20000, 10000, 5000, 10000]

        room = [[0 for column in range(500)] for row in range(500)]
        maxDirt = 1
        assert robotVacuum(room, maxDirt) == [0, 0, 0, 0]




