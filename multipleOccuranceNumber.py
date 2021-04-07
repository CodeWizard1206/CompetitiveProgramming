# Given an integer array of size n, find all elements that appear more than
# (n/3) times. Note : The algorithm should run in linear time and in O(1)
# space.

# Example :

# Input : 3 2 3
# Output : [3]

# Input : 1, 1, 1, 3, 3, 2, 2, 2
# Output: [1,2]

dict = {}

numList = list(map(int, input().split()))

limit = (len(numList)/3)

output = list()

for i in numList :
    if i in dict :
        dict[i] += 1
    else :
        dict.update({i : 1})

for element in dict :
    if (dict[element] > limit) :
        output.append(element)

print(output)