from jg.algo import dejumpingGaps, build_visted_map, find_start, fall_move, find_possible_moves, build_adjancy_map

class TestBuildAdjancyMap:


    def test_case_1(self):
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
        start = find_start(stage)
        list = build_adjancy_map(start, stage, v_map)

        print("THE LIST: ",list)
        assert list["found"] == True