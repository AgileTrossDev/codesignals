from lib.main import build_list, find_combo, check_set, move_to_next_node,kinderLevon


class TestMain():

  def test_build_list(self):
    exp = []
    assert exp == build_list(1) 

    exp = [[1]]
    assert exp == build_list(2)

    exp = [[1,2],[2]]
    assert exp == build_list(3)

    exp = [[1,2,3],[2,3],[3]]
    assert exp == build_list(4)


  def test_find_combo(self):
   assert 1 == find_combo(1)
   assert 2 == find_combo(5)
   assert 2 == find_combo(1001)
   assert 4 == find_combo(6)
   assert 3 == find_combo(4)



  def test_check_set(self):
    cnt =5
    visted= []
    best = [0,0]
    res = check_set(cnt,visted,best)
    assert [5, 2] == res
    assert [5, 2] == check_set(5,visted,best) 
    assert [6, 4] == check_set(6,visted,best)
    assert [6, 4] == check_set(4,visted, best)
    assert [6, 4] == check_set(8, visted, best) 

    best = [100,1] 
    visted = []
    assert [6,4] == check_set(6, visted, best)
  
    best = [100,1]
    assert [100,1] == check_set(6, visted, best) 
  



  def test_move_to_next_node(self):


    path = []
    stack = [0]
    cnt = 0 
    input  = [5,6,7,8]
    assert 5 == move_to_next_node(path, stack, cnt, input)
    assert [0] == path
    assert [0] == stack

    stack.append(1)
    stack.append(2)
    stack.append(3)
    cnt =5 

    assert 13 == move_to_next_node(path,stack,cnt,input)
    assert [0,3] == path
    assert [0,1,2,3] == stack

    cnt = 13
    assert 12 == move_to_next_node(path,stack,cnt,input)
    assert [0,2] == path
    assert [0,1,2] == stack


  def test_kinderLevon(self):

    input = [1, 1, 1]
    assert 2 == kinderLevon(input)

    input = [1, 2, 3]
    assert 6 == kinderLevon(input) 




