"""
As a good secret agent, you know that you can't be communicating with other agents using a common alphabet or any kind of simple messaging system. Because of that, you and the other secret agents are using a small code alphabet to send minimal messages to each other, in order to coordinate your secret meetings.

You've received an encoded message in the form of a string incomingMessage, which represents an inquiry from another secret agent, proposing a day, time, and location for your next secret meeting. Your task is to decode the message, and give a response indicating whether the meeting is possible or not.

How to decipher the message:

This process can be quite complicated, so the following description would probably be tough to follow for an average person, but the agency knows that you possess the exceptional skill and patience to make it through easily!

Your alphabet consists of 20 symbols, and you can use the following key for encoding and decoding (but don't tell anyone!)

"0" = "a"
"9" = "e"
"8" = "i"
"7" = "o"
"6" = "u"
"5" = "y"
"4" = "w"
"10" = "t"
"11" = "d"
"12" = "s"
"13" = "n"
"14" = "m"
"15" = "r"
"16" = "b"
"17" = "k"
"18" = "p"
"*" = "morning"
"@" = "afternoon"
"#" = "night"
"?" = "-"

Each encoded message is made up of a series of these symbols, separated by "." characters. The decoded message should be in the form day-time-location.

For an extra layer of security, the "_" symbol is used to augment the code of all the numbers that follow it. More specifically, the codes should all be increased by codeNumberDiff, from that point onward. These modifiers are cumulative, so the codes can be augmented more than once.

Being an Agent means that you need to be cautious about your movements, so there are only a few combinations of days, times, and locations that will work:

If the day is "today", you can only meet in the park (regardless of the time).
If the day is "tomorrow", then you can either meet at the "bar" at "night", or in the "park" during the "afternoon".
If the day is "twodays" (the day after tomorrow), then you can only meet at the "restaurant" in the "morning".
No other combinations are possible.
To answer the other agent, you must send an encrypted message with a "yes" or "no" (remember to send it encrypted). Return a 2-element array, containing the decrypted message and your encrypted response!

Example:

For incomingMessage = "10.7.11.0.5.?.#.?._.15.-1.14" and codeNumberDiff = 1, the output should be ["today-night-bar", "13.7"]

The first parts can be decoded using the key above ("10.7.11.0.5" translates to "today" and "#" translates to "night"), but since there's a "_" symbol in the last part, all of the following codes should be augmented by 1 (since codeNumberDiff is 1). So the message goes from "15.-1.14" to "16.0.15", which translates to "bar".

The answer for the message is "no", because for today you can only meet in the park (not the bar). So after encrypting your response, the result is "13.7".

For incomingMessage = "10.4.7.11.0.5._.10.?.*.?._.11.5.8.6.-4.2.11.-4.9.6" and codeNumberDiff = 2, the output should be ["twodays-morning-restaurant", "5.9.12"]

There are two "_" symbols in the message, so after the first one appears, all codes should be increased by 2; after the second one, all codes should be increased by 4.

Decrypting the message, it shows that the meeting will be in two days, in the morning at the restaurant, which is a valid combination, so you answer with a encrypted "yes" ("5.9.12").

Input / Output

[execution time limit] 4 seconds (py3)

[input] string incomingMessage

The secret encoded message that you've received from your secret agent colleague.

Guaranteed constraints:
incomingMessage[i] ∈ {"0" - "9", ".", "?", "_", "-", "#", "*", "@"}

[input] integer codeNumberDiff

An integer representing how much you'll need to modify all following codes for each instance of the "_" symbol.

Guaranteed constraints:
-1000 ≤ codeNumberDiff ≤ 1000

[output] array.string

A 2-element array containing the decrypted message from the other secret agent, as well as your encrypted response.
[Python3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name

"""

def _can_we_meet(msg):
    day = msg[0]
    time = msg[1]
    loc = msg[2]

    if day == "today" and loc == "park":
        return "5.9.12"

    if day == "tomorrow" and ((loc == "bar" and time == "night") or (loc == "park" and time == "afternoon")):
        return "5.9.12"

    if day == "twodays" and loc == "restaurant" and time == "morning":
        return "5.9.12"

    return "13.7"


def _symbol_look_up(index, off_set, aug):
    key = str(index + off_set * aug)
    tbl = { "0": "a", "9": "e", "8": "i", "7": "o", "6": "u", "5": "y", "4": "w",
            "10": "t", "11": "d", "12": "s", "13": "n", "14": "m", "15": "r",
            "16": "b", "17": "k", "18": "p"}
    return tbl[key]


def _special_look_up(symbol):
    tbl = { "*": "morning", "@": "afternoon", "#": "night", "?": "-", "_": ""}
    return tbl[symbol]


def _to_int(val):
    try:
        return int(val)
    except ValueError:
        pass

    return None


def secretAgentsMeetingProposal(incomingMessage, codeNumberDiff):

    aug = 0
    word = ""
    msg = []
    symbol = ""
    for c in incomingMessage:
        print("Loop: {} | {}".format(c, symbol))
        if c == "_":
            aug += 1
            symbol += "_"
        elif c == ".":
            val = _to_int(symbol)
            if val is not None:
                word += _symbol_look_up(val, codeNumberDiff, aug)
            else:
                word += _special_look_up(symbol)
            print("WORD: ", word)
            symbol = ""
        else:
            symbol += c


    if symbol != "":
        val = _to_int(symbol)
        if val is not None:
            word += _symbol_look_up(val, codeNumberDiff, aug)
        else:
            word += _special_look_up(symbol)
        print("WORD: ", word)
        symbol = ""


    result = _can_we_meet(word.split("-"))
    return [word, result]

