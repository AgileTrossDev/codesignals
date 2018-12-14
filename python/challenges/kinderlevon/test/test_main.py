from lib.main import kinderLevon, build_links, traverse


class TestMain:

    def test_build_links(self):
        exp = []
        assert exp == build_links(1)

        exp = [[1]]
        assert exp == build_links(2)

        exp = [[1,2],[2]]
        assert exp == build_links(3)

        exp = [[1,2,3],[2,3],[3]]
        assert exp == build_links(4)

