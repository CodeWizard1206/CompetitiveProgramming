# You have a string S consisting of digits and signs '?'. You want to replace the question signs
# in S with digits to get a number that meets the following conditions:
#     1. The number must be divisible by k.
#     2. The number should not contain any leading zeros.

# Additionally, it is given that the number must be as small as possible.
# You need to find the number that meets all the given conditions. If there exists no sych number
# print -1. Since the number can be very large return it modulo 10^9+7.

# FFunctional Description
# Complete the findMinimum function in the editor below. It has the following pparameter(s).

# k -> integer : The integer we are going to  check for divisible by.
# s -> string : The input number as string.
# findMinimum() -> The function must return an integer denoting the smallest acceptable number that meets the given conditions.

# Constraints :
# 1 <= k <= 10^3
# 1 <= len(s) <= 10^3

# Input format for custom testing:

# The first line an integer, k, denoting the number we are going to check for divisibility by k.
# The next line contains a string, s, denoting the input number as string.

# Sample Case:

# Case #1:
#     Input:
#         5
#         ?5
#     Output:
#         15
#     Explanation:
#         we replace '?' with 1;

# Case #2:
#     Input:
#         30
#         1?0
#     Output:
#         120
#     Explanation:
#         we replace '?' with 2;
# Case #3:
#     Input:
#         13
#         1??
#     Output:
#         104
#     Explanation:
#         we replace first '?' with 0, and second '?' with 4;


def solution(num: str, indexes: list, i: int, div: int):
    if i < len(indexes):
        for x in range(10):
            t = list(num)
            if (indexes[i] == 0 and x == 0) :
                x += 1
            t[indexes[i]] = str(x)
            num = ''.join(t)
            ret = solution(num, indexes, i+1, div)
            if (ret == -1):
                if (int(num)%div == 0) :
                    return int(num)
            elif ret != None :
                return ret
    else:
        #if ? character count limit reached go back to check generated number.
        return -1


def findMinimum(num: str, k: int) -> int:
    #getting index values of ? character for keeping track
    indexes = [i for i, char in enumerate(num) if char == '?']
    result = solution(num, indexes, 0, k)
    if (result == None) :
        return -1
    else :
        return result%10000000007


def main():
    k = int(input())
    s = str(input())
    print(findMinimum(s, k))


if __name__ == '__main__':
    main() #Call main function; part of systematic coding approach