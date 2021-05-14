"""
Given the Array of integers nums, you will chosse 2 different indices
i and j of that array. Return the maximum value of (nums[i] - 1) * (nums[j] - 1).

input: [3, 4, 5, 2]

output: 12

"""

nums = list(map(int, input().split()))
nums.sort()

limit = (len(nums) - 1)

result = int(((nums[limit-1] - 1) * (nums[limit] - 1)))
print(result)
