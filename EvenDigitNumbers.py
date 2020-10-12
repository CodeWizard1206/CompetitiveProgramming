"""

Given an Array nums of integers, return how many of them contain an even
number of digits.

input: [12, 345, 2, 6, 7896]
output: 2

"""

numList = list(map(str, raw_input().split()))
count = 0

for i in numList:
	if len(i)%2 == 0:
		count += 1
	
print(count)
