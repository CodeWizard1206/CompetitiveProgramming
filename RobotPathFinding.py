# Your country's space agency has just landed a rover on a new planet, which can be thought of as a grid of squares containing 109 columns (numbered starting from 1 from west to east) and
# 109 rows (numbered starting from 1 from north to south). Let (w, h) denote the square in the w-th column and the h-th row. The rover begins on the square (1, 1).

# The rover can be maneuvered around on the surface of the planet by sending it a program, which is a string of characters representing movements in the four cardinal directions.
# The robot executes each character of the string in order:
# N: Move one unit north.
# S: Move one unit south.
# E: Move one unit east.
# W: Move one unit west.
# There is also a special instruction X(Y), where X is a number between 2 and 9 inclusive and Y is a non-empty subprogram. This denotes that the robot should repeat the subprogram Y a total of X times.
# 
# For example:
# 2(NWE) is equivalent to NWENWE.
# 3(S2(E)) is equivalent to SEESEESEE.
# EEEE4(N)2(SS) is equivalent to EEEENNNNSSSS.

# Since the planet is a torus, the first and last columns are adjacent, so moving east from column 109 will move the rover to column 1 and moving south from row 109 will move the rover to row 1.
# Similarly, moving west from column 1 will move the rover to column 109 and moving north from row 1 will move the rover to row 109. Given a program that the robot will execute,
# determine the final position of the robot after it has finished all its movements.

# Input
# The first line of the input gives the number of test cases, T. T lines follow. Each line contains a single string: the program sent to the rover.

# Output
# For each test case, output one line containing Case #x: w h, where x is the test case number (starting from 1) and w h is the final square (w, h) the rover finishes in.

# Limits
# Time limit: 10 seconds per test set.
# Memory limit: 1GB.
# 1 ≤ T ≤ 100.
# The string represents a valid program.
# The length of each program is between 1 and 2000 characters inclusive.

# Test set 1
# The total number of moves the robot will make in a single test case is at most 104.

# Test set 2
# No additional constraints.

# Sample

# Input
 	
# Output
 
# 4
# SSSEEE
# N
# N3(S)N2(E)N
# 2(3(NW)2(W2(EE)W))

  
# Case #1: 4 4
# Case #2: 1 1000000000
# Case #3: 3 1
# Case #4: 3 999999995

  
# In Sample Case #1, the rover moves three units south, then three units east.

# In Sample Case #2, the rover moves one unit north. Since the planet is a torus, this moves it into row 109.

# In Sample Case #3, the program given to the rover is equivalent to NSSSNEEN.

# In Sample Case #4, the program given to the rover is equivalent to NWNWNWWEEEEWWEEEEWNWNWNWWEEEEWWEEEEW.


from collections import deque

stringStack = deque()
directions = ""
XList = []
YList = []

def decodeString(encodedString):
    global directions
    global stringStack
    returnableString = ""
    for i in range(0,len(encodedString)):
        if (encodedString[i] >= "0" and encodedString[i] <= "9"):
            if (len(returnableString) != 0):
                stringStack.append(returnableString)
                returnableString = ""
            stringStack.append(encodedString[i])

        elif (encodedString[i] >= "A" and encodedString[i] <= "Z"):
            returnableString = returnableString + encodedString[i]

        elif (encodedString[i] == ')'):
            top = stringStack.pop()
            while (top <= "0" or top > "9"):
                returnableString = top + returnableString
                top = stringStack.pop()

            multiplier = int(top)
            returnableString  = "".join([returnableString for s in range(multiplier)])
            stringStack.append(returnableString)
            returnableString = ""

    while (stringStack.__len__() != 0):
        returnableString = stringStack.pop() + returnableString

    if (len(returnableString) == 0):
        directions = stringStack.pop()
    else:
        directions = returnableString

def pathFinder():
    global directions
    global XList
    global YList
    X = 1
    Y = 1
    encodedString = list(''.join(directions))
    for i in range(len(encodedString)):
        if (encodedString[i] == 'N'):
            if (Y == 1):
                Y = pow(10, 9)
            else:
                Y = Y - 1
        elif (encodedString[i] == 'S'):
            if (Y == pow(10, 9)):
                Y = 1
            else:
                Y = Y + 1
        elif (encodedString[i] == 'E'):
            if (X == pow(10, 9)):
                X = 1
            else:
                X = X + 1
        elif (encodedString[i] == 'W'):
            if (X == 1):
                X = pow(10, 9)
            else:
                X = X - 1
    
    XList.append(X)
    YList.append(Y)


def main():
    global XList, YList
    noOfTestCases = int(input())
    for i in range(noOfTestCases):
        dir = input()
        decodeString(list(''.join(dir)))
        pathFinder()

    for i in range(noOfTestCases):
        print("Case #{}: {}, {}".format(i+1, XList[i], YList[i]))

if __name__ == '__main__':
    main()
