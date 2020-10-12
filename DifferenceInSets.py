"""
Given 2 Array A and B of positive integers. Your task is to find numbers
which are present in the first array, but not present in the second array.

input: 6 5
1 2 3 4 5 10
2 3 1 0 5

output: 4 10

"""

listM = list(map(int, raw_input().split()))
listN = list(map(int, raw_input().split()))

resultList = listM + listN

for i in listM :
	if i in listN :
		resultList = list(filter(lambda x: x != i, listM))

print(resultList)
