from jg.algo import dejumpingGaps, build_visted_map, find_start, fall_move

class TestDejumpingGaps:

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

