

class MyGraph:

    def __init__(self):
        self.data = {}

    def add_node(self, n):
        if n not in self.data:
            self.data[n] = []

    def add_edge(self, a, b, bi = False):
        self.add_node(a)
        self.add_node(b)

        self.data[a].append(b)

        if bi:
            self.data[b].append(a)

    def disp(self):
        print("Displaying Graph")
        for k, v in self.data.items():
            print("{}: {}".format(k,v))
