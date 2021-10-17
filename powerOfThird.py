# Cristina appeared for a corporate Hackathon. She has cleared first round of this and would
# like to take next challenge which is coding round. The program statement comes to her is
# "Write a program, to find numbers which are in between integer 2 and integer "N" and such
# that sum of its digits raised to the third power is equal to the number with the input given
# below."

# Example 1:
# Input:
# 200                    --> Integer "N"
# Output:
# 153                    --> result - An integer value.

# such that sum of its digits raised to the third power is equal to the number.

# Explanation:
# 200 is the given integer value. 153 is the only number in between integer 2 and 200
# which satisfies the sum of its digits raised to the third power is equal to the number.
# Hence, the output is 153.

# Example 2:
# Input:
# 100
# Output:
# No Number Found

# Explanation:
# 100 is the given Integer value.There is not a single number which satisfies the sum of
# its digit raised to the third power is equal to the number. Hence, the output is "No Number Found".

# Exampple 3:
# Input:
# 5000
# Output:
# 153 370 371 407

# Exampple 4:
# Input:
# 10001
# Output:
# Wrong Input

# Explanation:
# Input is out of range. hence the output is "Wrong Input".

# Range of Input:
# 2<=N<=10000

import math

def solution(number) :
    temp = number
    sum = 0
    while (temp != 0) :
        t = temp%10
        t = math.pow(t, 3)
        sum += t
        temp = temp//10
    if sum == number :
        return True
    else :
        return False

def main() :
    n = int(input())
    ret = [];
    if (n < 2 or n > 10000) :
        print("Wrong Input")
        return

    for i in range(2, n):
        if (solution(i)) :
            ret.append(str(i))
    
    if len(ret) == 0 :
        print("No Number Found")
    else :
        print(' '.join(ret))

if __name__ == "__main__" :
    main()