from rv.aglo import Pod,robotVacuum,State
import pytest

class TestAglo:

    def disp_pods(self, state):

        for i in range(len(state.pods)):
            print("POD {}: {} {}".format(i, state.pods[i].x, state.pods[i].y))


    def test_move_1(self):
        room = [[1, 8, 5, 4],
                [3, 4, 1, 0],
                [3, 5, 2, 1],
                [0, 2, 1, 4]]
        maxDirt = 3

        state = State(room, maxDirt)

        # Initial State
        assert state.pods[0].x == 0 and state.pods[0].y == 0
        assert state.pods[1].x == 1 and state.pods[1].y == 0
        assert state.pods[2].x == 1 and state.pods[2].y == 1
        assert state.pods[3].x == 0 and state.pods[3].y == 1

        self.disp_pods(state)

        state.move()



        # cleaned, Rotated,  and moved
        assert [[-1, 5, 5, 4], [-1, 1, 1, 0], [3, 5, 2, 1], [0, 2, 1, 4]] == room
        assert state.cleaned == 2

        self.disp_pods(state)

        assert state.pods[3].x == 1 and state.pods[3].y == 0
        assert state.pods[0].x == 2 and state.pods[0].y == 0
        assert state.pods[1].x == 2 and state.pods[1].y == 1
        assert state.pods[2].x == 1 and state.pods[2].y == 1


        state.move()

        assert state.pods[2].x == 2 and state.pods[2].y == 0
        assert state.pods[3].x == 3 and state.pods[3].y == 0
        assert state.pods[0].x == 3 and state.pods[0].y == 1
        assert state.pods[1].x == 2 and state.pods[1].y == 1

        state.move()

        assert state.pods[1].x == 2 and state.pods[1].y == 1
        assert state.pods[2].x == 3 and state.pods[2].y == 1
        assert state.pods[3].x == 3 and state.pods[3].y == 2
        assert state.pods[0].x == 2 and state.pods[0].y == 2

        state.move()

        assert state.pods[0].x == 1 and state.pods[0].y == 1
        assert state.pods[1].x == 2 and state.pods[1].y == 1
        assert state.pods[2].x == 2 and state.pods[2].y == 2
        assert state.pods[3].x == 1 and state.pods[3].y == 2

        state.move()

        assert state.pods[3].x == 0 and state.pods[3].y == 1
        assert state.pods[0].x == 1 and state.pods[0].y == 1
        assert state.pods[1].x == 1 and state.pods[1].y == 2
        assert state.pods[2].x == 0 and state.pods[2].y == 2

        state.move()

        assert state.pods[2].x == 0 and state.pods[2].y == 2
        assert state.pods[3].x == 1 and state.pods[3].y == 2
        assert state.pods[0].x == 1 and state.pods[0].y == 3
        assert state.pods[1].x == 0 and state.pods[1].y == 3

        state.move()

        assert state.pods[1].x == 1 and state.pods[1].y == 2
        assert state.pods[2].x == 2 and state.pods[2].y == 2
        assert state.pods[3].x == 2 and state.pods[3].y == 3
        assert state.pods[0].x == 1 and state.pods[0].y == 3


        state.move()

        assert state.pods[0].x == 2 and state.pods[0].y == 2
        assert state.pods[1].x == 3 and state.pods[1].y == 2
        assert state.pods[2].x == 3 and state.pods[2].y == 3
        assert state.pods[3].x == 2 and state.pods[3].y == 3

        state.move()

        assert state.pods[3].x == 2 and state.pods[3].y == 1
        assert state.pods[0].x == 3 and state.pods[0].y == 1
        assert state.pods[1].x == 3 and state.pods[1].y == 2
        assert state.pods[2].x == 2 and state.pods[2].y == 2


        state.move()
        assert state.pods[2].x == 1 and state.pods[2].y == 1
        assert state.pods[3].x == 2 and state.pods[3].y == 1
        assert state.pods[0].x == 2 and state.pods[0].y == 2
        assert state.pods[1].x == 1 and state.pods[1].y == 2

    def test_robotVacuum_1(self):
        board = [[0, 5, 4, 10, 0, 8],
                 [7, 2, 7, 4, 7, 2],
                 [2, 2, 10, 1, 7, 6]]
        maxDirt = 10
        assert robotVacuum(board, maxDirt) == [18, 27, 13, 26]

    def test_robotVacuum_2(self):
        room = [[1, 8, 5, 4],
                [3, 4, 1, 0],
                [3, 5, 2, 1],
                [0, 2, 1, 4]]
        maxDirt = 3
        assert robotVacuum(room, maxDirt) == [8, 8, 13, 15]

    def test_robotVacuum_3(self):
        room = [[0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0]]
        maxDirt = 3
        assert robotVacuum(room, maxDirt) == [0, 0, 0, 0]

    def test_robotVacuum_4(self):
        room = [[5000 for column in range(3)] for row in range(3)]
        maxDirt = 1
        assert robotVacuum(room, maxDirt) == [20000, 10000, 5000, 10000]

    #@pytest.mark.timeout(10)
    def test_robotVacuum_5(self):
        room = [[0 for column in range(500)] for row in range(500)]
        maxDirt = 1
        assert robotVacuum(room, maxDirt) == [0, 0, 0, 0]




