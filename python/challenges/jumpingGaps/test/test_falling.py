from jg.algo import dejumpingGaps, build_visted_map, find_start, fall_move

class TestDejumpingGapsFalling:

    def test_build_visted_map(self):

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

        map = build_visted_map(stage)

        assert len(map) == len(stage)
        assert len(map[0]) == len(stage[0])
        assert len(map) == 10
        assert len(map[0]) == 38




    def test_find_start(self):


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

        s = find_start(stage)

        assert [7, 0] == s




    def test_fall_move_from_above_to_start(self):
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
        start = [1, 0]

        assert None== fall_move(start, stage, v_map)

        print(v_map)
        for i, row in enumerate(v_map):
            print("ROW: {} {}".format(i,row[0]))
            if i == 0 or i >7:
                assert row[0] == 0
            elif i < 8:
                assert row[0] == 1


    def test_fall_move_from_above_to_floor(self):
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
        start = [1, 5]

        assert [9, 5]== fall_move(start, stage, v_map)

        print(v_map)
        for i, row in enumerate(v_map):
            print("ROW: {} {}".format(i, row[0]))
            if i == 0:
                assert row[5] == 0
            else:
                assert row[5] == 1


    def test_fall_to_ledge(self):
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
        start = [1, 7]

        assert [7, 7] == fall_move(start, stage, v_map)

        print(v_map)
        for i, row in enumerate(v_map):
            print("ROW: {} {}".format(i, row[0]))
            if i == 0:
                assert row[5] == 0
            else:
                assert row[5] == 1





