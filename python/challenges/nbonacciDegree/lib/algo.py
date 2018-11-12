
def b():

    a = False
    cnt = 0
    while not a:
        b = 3
        print ("THERE")
        while b!=0:
            cnt +=1
            b -= 1
            print ("HERE")

        if cnt >30:
            a = True

    return cnt




def nbonacciDegree(s):
    # Input Validation
    if (len(s)<2):
        return -1

    seq_length = 1
    seq_start = 0
    seq_end = seq_start + seq_length
    good = False
    cnt = 0

    while not good:
        cnt = cnt + 1
        loop_flag = True
        while loop_flag:
            # Find the sum of sequence
            # TODO: Calc check, but adding next, sub first.
            seq_sum = sum(s[seq_start:(seq_start + seq_length)])

            print(" INNER: {} {} {} {} {}".format(seq_sum, seq_start,seq_length,seq_end,len(s)))

            # Validate sequence sum is equal to next node
            if seq_sum != s[seq_end]:
                # Does not match
                loop_flag = False

                # Resize Sequence and start over
                seq_start = 0
                seq_length += 1
                seq_end = seq_start + seq_length

                # If we reached end, then not a valid input
                if seq_end >= len(s):
                    print ("WE ARE BAD")
                    return -1
                else:
                    print("TRYING AGAIN: {} {}".format(good, loop_flag))
            else:
                # Matches
                print (" MATCH")
                seq_start += 1
                seq_end = seq_start + seq_length
                if (seq_end >= len(s)):
                    # Reached End
                    loop_flag = False
                    good = True
                    print(" WE ARE GOOD")




        print("LOOP({}) {}".format(cnt, good))


    return seq_length





def foo_bar(s):






    while not good:

        print ("CHECKING INNER({}) {} ".format(cnt, good))
        loop = True
        while loop:
            print ("LOOP: {} {} {}".format(seq_start, seq_length, seq_end))



            # Validate sequence sum is equal to next node
            if seq_sum != s[seq_length]:
                # Does not match
                loop = False

                # Resize Sequence
                seq_start = 0
                seq_length += 1
                seq_end = seq_start + seq_length

                # If we reached end, then not a valid input
                if (seq_end >= len(s)):
                    print ("WE ARE BAD")
                    return -1
                else:
                    print("TRYING AGAIN: {} {}".format(good, loop))
            else:
                # Matches
                seq_start += 1
                seq_end = seq_start + seq_length
                if (seq_end >= len(s)):
                    # Reached End
                    loop = False
                    good = True
                    print("WE ARE GOOD")



        print("OUTSIDE {} {} {} ".format(good, loop, (not good)))




        print("EXITING {} {}".format(good, loop))
        return seq_length










