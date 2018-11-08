from lib import algo


class TestAlgo:

    def test_lookup(self):
        assert "e" == algo._symbol_look_up(9, 1, 0)
        assert "d" == algo._symbol_look_up(9, 1, 2)


    def test_secretAgentsMeetingProposal(self):

        assert ["today-night-bar", "13.7" ] == algo.secretAgentsMeetingProposal("10.7.11.0.5.?.#.?._.15.-1.14" , 1)

