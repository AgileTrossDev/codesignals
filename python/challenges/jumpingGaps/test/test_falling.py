from jg.algo import dejumpingGaps, build_visted_map, find_start, fall_move

class TestDejumpingGapsFalling:





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
            if i == 0 or i > 7:
                assert row[7] == 0
            else:
                assert row[7] == 1


    def test_fall_to_end(self):
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
        start = [1, 37]

        assert [6, 37] == fall_move(start, stage, v_map)

        print(v_map)
        for i, row in enumerate(v_map):
            print("ROW: {} {}".format(i, row[0]))
            if i == 0 or i > 6:
                assert row[37] == 0
            else:
                assert row[37] == 1

    def test_fall_from_sky(self):
        stage = ["# ####################################",
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
        start = [-3, 1]

        assert [7, 1] == fall_move(start, stage, v_map)

        print(v_map)
        for i, row in enumerate(v_map):
            print("ROW: {} {}".format(i, row[0]))
            if  i > 7:
                assert row[1] == 0
            else:
                assert row[1] == 1


    def test_fall_case_walled_start(self):
        stage = ["# ####################################",
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
        v_map[9][6] = 1
        start = [8, 3]

        assert None == fall_move(start, stage, v_map)

        print(v_map)
        for i, row in enumerate(v_map):
            print("ROW: {} {}".format(i, row[0]))
            if  i > 7:
                assert row[8] == 0
            else:
                assert row[8] == 0



