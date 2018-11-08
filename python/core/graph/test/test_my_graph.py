from lib.my_graph import MyGraph

class TestMyGraph():


    def test_disp(self):
        a = MyGraph()
        a.add_edge("a","b",False)
        a.add_edge("a", "c", False)
        a.add_node("d")
        a.add_edge("d", "b", True)
        assert a.disp() is None





