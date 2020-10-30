#The i-the person has weight people[i], and each boat can carry a maximum
#weight of limit. Each boat carries at most 2 people at the same time,
#provided the sum of the weight of those people is at most limit.

#Return the minimum number of boats to carry every given person. (It is
#guaranteed each person can be carried by a boat.)
#

#Input: people = [3, 2, 2, 1], limit = 3
#Output: 3

def main():
	people = list(map(int, raw_input().split()))
	limit = int(raw_input())
	boatCount = 1
	
	for i in range(1, len(people)):
		if (people[i-1]+people[i]) <= limit:
			people[i] = people[i-1]+people[i]
		else:
			boatCount += 1
	
	print(boatCount);
	

if __name__ == "__main__":
	main()
