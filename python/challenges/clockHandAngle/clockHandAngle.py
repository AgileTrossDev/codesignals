def calc_minue_off_set(t):
   return 360*(int(t[1])/60 +int(t[2])/3600)

def calc_hour_offset(t):
   return 360/12*(int(t[0])+int(t[1])/60+int(t[2])/3600)
   
def clockHandAngle(time):
   t = time.split(":")
   
   if t[0] == "12":
      t[0] = 0
   return min (
               (abs(calc_hour_offset(t) - calc_minue_off_set(t))),
               360-(abs(calc_minue_off_set(t) - calc_hour_offset(t))) )
   
