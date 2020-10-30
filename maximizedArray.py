#Given two arrays A and B of equal size. the advantage of A with respect to B
#is the Number of indices i for which A[i] > B[i].
#
#Return any permutation of A that maximizes it's advantage with respect to B.
#
#Input: A = [2, 7, 11, 15], B = [1, 10, 4, 11]
#Output: [2, 11, 7, 15]
#

def main():
	A = list(map(int, raw_input().split()))
	B = list(map(int, raw_input().split()))
	
	if len(A) != len(B):
		print("INVALID INPUT")
		return
	else:
		length = len(A)
		for i in range(0, length):
			for j in range(i, length):
				if (j == i and A[j] > B[i]):
					break
				else:
					if (A[j] > B[i]):
						A[i], A[j] = A[j], A[i]
						break;
	print(A)
	return

if __name__ == "__main__":
	main()
