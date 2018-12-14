from jg.algo import dejumpingGaps, build_visted_map, find_start, fall_move, find_possible_moves

class TestDejumpingGaps:

    def test_from_start(self):
        stage = ["######################################",
                 "                                      ",
                 "                                      ",
                 "                          ########    ",
                 "                          ########    ",
                 "               ####       ########    ",
                 "           #######################   E",
                 "S          ###########################",
                 "#####  ###############################",
                 "#####  ###############################"]

        v_map = build_visted_map(stage)
        start = [7, 0]

        result = find_possible_moves(start, stage, v_map)

        assert 3 == len(result)
        assert [7,1] == result[0]
        assert [7, 2] == result[1]
        assert [7, 3] == result[2]


    def test_loc_2(self):
        stage = ["######################################",
                 "                                      ",
                 "                                      ",
                 "                          ########    ",
                 "                          ########    ",
                 "               ####       ########    ",
                 "           #######################   E",
                 "S          ###########################",
                 "#####  ###############################",
                 "#####  ###############################"]

        v_map = build_visted_map(stage)
        v_map[7][0] = 1
        start = [7, 1]

        result = find_possible_moves(start, stage, v_map)

        assert 3 == len(result)
        assert [7, 2] == result[0]
        assert [7, 3] == result[1]
        assert [7, 4] == result[2]


    def test_loc_3(self):
        stage = ["######################################",
                 "                                      ",
                 "                                      ",
                 "                          ########    ",
                 "                          ########    ",
                 "               ####       ########    ",
                 "           #######################   E",
                 "S          ###########################",
                 "#####  ###############################",
                 "#####  ###############################"]

        v_map = build_visted_map(stage)
        v_map[7][1] = 1
        start = [7, 2]

        result = find_possible_moves(start, stage, v_map)

        assert 4 == len(result)

        assert [7, 3] == result[0]
        assert [7, 4] == result[1]
        assert [9, 5] == result[2]
        assert [7, 0] == result[3]



    def test_loc_4(self):
        stage = ["######################################",
                 "                                      ",
                 "                                      ",
                 "                          ########    ",
                 "                          ########    ",
                 "               ####       ########    ",
                 "           #######################   E",
                 "S          ###########################",
                 "#####  ###############################",
                 "#####  ###############################"]

        v_map = build_visted_map(stage)
        start = [9, 6]

        result = find_possible_moves(start, stage, v_map)
        print(result)
        assert 6 == len(result)

        assert [9, 5] == result[0]
        assert [7, 3] == result[2]
        assert [7, 4] == result[1]
        assert [7, 7] == result[3]
        assert [7, 8] == result[4]
        assert [7, 9] == result[5]





