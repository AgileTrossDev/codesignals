# Max number of swipes = (Dirties Spot / MaxClean * 1.0)






class Pod:

    def __init__(self,x,y,s):
        self.x = x
        self.y = y
        self.spot = s
        self.total = 0


class State:

    def __init__(self,room, max_clean):
        self.pods = [Pod(0,0,1), Pod(1,0,1), Pod(1,1,1), Pod(0,1,3)]
        self.cleaned = 0
        self.room = room
        self.max_clean = max_clean
        self.upper_right_index = 0
        self.direction_x = 1
        self.direction_y = 1



    def result(self):
        return [self.pods[0].total, self.pods[1].total, self.pods[2].total, self.pods[3].total]

    def clean(self):
        for pod in self.pods:
            if self.room[pod.y][pod.x] == 0:
                self.cleaned += 1
                self.room[pod.y][pod.x] = -1
            elif self.room[pod.y][pod.x] <= self.max_clean and self.room[pod.y][pod.x] > 0:
                self.cleaned += 1
                pod.total += self.room[pod.y][pod.x]
                self.room[pod.y][pod.x] = -1
            elif self.room[pod.y][pod.x] != -1:
                self.room[pod.y][pod.x] -= self.max_clean
                pod.total += self.max_clean


    def rotate(self):

      tmp_x = self.pods[0].x
      tmp_y = self.pods[0].y

      for i, pod in enumerate(self.pods):
        if i < 3:
          pod.x = self.pods[i+1].x
          pod.y = self.pods[i + 1].y

      self.pods[3].x = tmp_x
      self.pods[3].y = tmp_y

      if  self.upper_right_index <= 0:
         self.upper_right_index = 3
      else:
         self.upper_right_index -= 1


    def move(self):
        change = False
        x_move = 0
        y_move = 0

        # Determine if horizontal direction is flipping
        if (self.pods[self.upper_right_index].x == (len(self.room[0])-2) and self.direction_x>0):
            self.direction_x = -1
            change = True
        elif (self.pods[self.upper_right_index].x == 0 and self.direction_x < 0):
            self.direction_x = 1
            change = True

        if change:
            # Determine if vertical direction is flipping
            if (self.pods[self.upper_right_index].y == (len(self.room) - 2) and self.direction_y > 0):
                self.direction_y = -1
            elif (self.pods[self.upper_right_index].y == 0 and self.direction_y < 0):
                self.direction_y = 1

            # Moving vertically
            x_move = 0
            y_move = self.direction_y
        else: # Moving Horizontally
            x_move = self.direction_x
            y_move = 0


        # Stash original location of Pod 0
        tmp_x = self.pods[0].x
        tmp_y = self.pods[0].y

        # Loop over Pods, cleaning, rotating and moving
        for i, pod in enumerate(self.pods):

            # Clean current location
            if self.room[pod.y][pod.x] == 0:
                self.cleaned += 1
                self.room[pod.y][pod.x] = -1
            elif self.room[pod.y][pod.x] <= self.max_clean and self.room[pod.y][pod.x] > 0:
                self.cleaned += 1
                pod.total += self.room[pod.y][pod.x]
                self.room[pod.y][pod.x] = -1
            elif self.room[pod.y][pod.x] != -1:
                self.room[pod.y][pod.x] -= self.max_clean
                pod.total += self.max_clean

            # Rotate and move first 3 Pods
            if i < 3:
                pod.x = self.pods[i + 1].x
                pod.y = self.pods[i + 1].y
                pod.x += x_move
                pod.y += y_move

        # Set Last Pod to location of original location of first pod and then rotate
        self.pods[3].x = tmp_x + x_move
        self.pods[3].y = tmp_y + y_move

        # Update to the new upper right
        if self.upper_right_index <= 0:
            self.upper_right_index = 3
        else:
            self.upper_right_index -= 1




def robotVacuum(room, maxDirt):
    squares = len(room) * len(room[0])
    state = State(room, maxDirt)

    while state.cleaned < squares:
        state.move()
        print(room)

    return state.result()

