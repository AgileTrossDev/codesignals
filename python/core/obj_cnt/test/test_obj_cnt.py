from lib import obj_cnt as obj

# OOOOXXO
# OXOXOOX
# XXXXOXO
# OXXXOOO

class TestObjCnt:
    def test_is_valid(self):
        data = "OOOOXXO OXOXOOX XXXXOXO OXXXOOO"
        visited = [0 for i in range(len(data))]

        assert not obj.is_valid(-1,data,visited)
        assert not obj.is_valid(0, data, visited)
        assert not obj.is_valid(1, data, visited)
        assert not obj.is_valid(2, data, visited)
        assert obj.is_valid(4, data, visited)
        assert obj.is_valid(5, data, visited)
        assert not obj.is_valid(6, data, visited)
        assert not obj.is_valid(7, data, visited)
        assert obj.is_valid(9, data, visited)
        assert not obj.is_valid(30, data, visited)
        assert not obj.is_valid(31, data, visited)


    def test_fill(self):
        data = "OOOOXXO OXOXOOX XXXXOXO OXXXOOO"
        visited = [0 for i in range(len(data))]

        width = data.find(" ")

        #obj._fill(0, data, visited, width)
        #print(visited)

        #obj._fill(1, data, visited, width)
        #print(visited)

        #obj._fill(2, data, visited, width)
        #print(visited)

        #obj._fill(3, data, visited, width)
        #print(visited)


        #obj._fill(4, data, visited, width)
        #print(visited)

        obj._fill(4, data, visited, width)
        exp = [0 for i in range(len(data))]
        exp[3]=1
        exp[4] = 1
        exp[5]=1
        exp[6]=1
        exp[12]=1
        exp[13]=1

        print(visited)
        print(exp)



        assert exp == visited



    def test_exex(self):
        data = "OOOOXXO OXOXOOX XXXXOXO OXXXOOO"
        assert 4 == obj.exec(data)

        data = "XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO"
        assert 6 == obj.exec(data)



    def test_update_queue(self):
        data = "OOOOXXO OXOXOOX XXXXOXO OXXXOOO"
        width = data.find(" ")

        visited = [0 for i in range(len(data))]
        q= []
        index =4
        obj.update_queue(index, data, width, q, visited)
        assert q == [3,5,12]

        visited = [0 for i in range(len(data))]
        q = []
        index = 30
        obj.update_queue(index, data, width, q, visited)
        assert q == [29, 22]


