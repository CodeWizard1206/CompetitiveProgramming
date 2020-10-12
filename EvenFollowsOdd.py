"""Given an Array A of non-negative integers, return an
array consisting of all even elements of A, followed by
all the odd elements of A.
You may return any answer array that satisfies this condition.

input: [3, 1, 2, 4]
output: [2, 4, 3, 1]

"""

numList = list(map(int, raw_input().split()))

listEven = list(filter(lambda x: x%2 == 0, numList))
listOdd = list(filter(lambda x: x%2 != 0, numList))

numList = listEven + listOdd

print(numList)
