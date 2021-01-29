# Andrew manages a pipe warehouse. He wishes to aotumate the process of transferring the pipes
# from the warehouse to the carrier truck. There are N pipes in the warehouse placed vertically
# along a wall. In the automated system, a drone picks the pipes by length and carries them to
# the carrier truck. In each turn, the drone moves from left to right to find the pipes whose
# lengths are greater than the pipe on thier left. After finding the pipe, the drone takes the
# pipe to the carrier truck. The drone repeats this process until it has no more pipes to picks

# write an algo. to output the list of pipes that will remain in the warehouse after the drone
# has completed this process.

# Input: 
# The first line of the input consists of an integer numOfPipes, representing the number of pipes
# in the warehouse(N). The second line consists of N space-separated integers len[0], len[1], len[2],
# len[3],......, len[N-1], representing the length of the pipes.

# Output:
# Print space-separated integers representing the list of the remaining pipes in the warehouse.

# Constraints
# 2 <= numOfPipes <= (10^5)
# 1 <= len[0], len[1],..., len[N-1] <= (10^5)

# Example:
# Input:
# 5
# 3 2 4 6 5

# Output:
# 3 2

# Explanation;

# In the first turn, the drone picks the pipe with length 4 as 4 > 2. So, the remaining pipes are
# 3, 2, 6 and 5.
# In the next turn, the drone picks the pipe with length 6 as 6 , 2. So, the remaining pipes are 3,
# 2 and 5.
# In the next turn, the drone picks the pipe with length 5 as 5 > 2. So, the remaining pipes are 3
# and 2.
# Now, there are no more pipes left which can be carried to the carrier truck. So, the remaining pipes
# in the warehouse are 3 and 2.

N = int(input())

pipes = list(map(int, input().split()))

looper = len(pipes)

for i in range(0, looper) :
    lim = len(pipes)
    for j in range(1, lim) :
        if (pipes[j-1] < pipes[j]) :
            pipes.pop(j)
            break;

print(' '.join(map(str, pipes)))
