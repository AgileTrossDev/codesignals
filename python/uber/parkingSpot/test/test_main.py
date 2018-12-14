from lib.main import find_orientation, VERTICAL, HORIZONTAL, check_for_open, check_path


class TestMain:

    def test_find_orientation(self):
        cd =  [3, 2]
        ls = [1, 1, 2, 3]
        assert HORIZONTAL == find_orientation(cd, ls)

        cd = [3, 2]
        ls = [1, 1, 3, 2]
        assert VERTICAL == find_orientation(cd, ls)

    def test_open(self):
        pl = [[1, 0, 1, 0, 1, 0],
               [0, 0, 0, 0, 1, 0],
               [0, 0, 0, 0, 0, 1],
               [1, 0, 1, 1, 1, 1]]

        assert check_for_open(1, 0, 2, 3, pl)
        assert not check_for_open(0, 0, 1, 1, pl)
        assert check_for_open(0, 5, 1, 5, pl)
        assert check_for_open(1, 5, 0, 5, pl, -1, 1)
        assert not check_for_open(3, 5, 0, 5, pl, -1, 1)

        assert not check_for_open(0, 0, 1 , 3, pl, 1, 1)

        print ("SICK")
        assert not check_for_open(0, 5, 1, 3, pl, 1, -1)


    def _test_check_path(self):
        pl = [[1, 0, 1, 0, 1, 0],
              [0, 0, 0, 0, 1, 0],
              [0, 0, 0, 0, 0, 1],
              [1, 0, 1, 1, 1, 1]]
        ls = [1, 1, 2, 3]
        assert check_path(pl, ls, HORIZONTAL)

        ls = [0, 5, 1, 5]
        assert  check_path(pl, ls, HORIZONTAL)

        print ("BAD")
        ls = [0, 3, 1, 3]
        assert not check_path(pl, ls, HORIZONTAL)


carDimensions: [2, 1]
parkingLot: [[1,0,1],
 [1,0,1],
 [1,1,1]]
luckySpot: [1, 1, 2, 1]



carDimensions: [2, 1]
parkingLot: [[1,1,1,1],
 [1,0,0,0],
 [1,0,1,0]]
luckySpot: [1, 2, 1, 3]