/*

Given a integer array of numbers of size N, find the contiguous subarray(containing atleast one number)
which has the largest sum and return its sum.

Example:

Input : 
9
-2 1 -3 4 -1 2 1 -5 4

Output:
6

Explanation: [4, -1, 2, 1] has the largest sum = 6.

The problem is based on the concepts of dynamic programming and is best example of Kadane's Algorithm.

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int max(int , int );

int main() {
	ll N;
	cin>>N;
	int* numberSequence = (int*) malloc(N * sizeof(int));
	int* resultSequence = (int*) malloc(N * sizeof(int));
	int maxResult = 0;
	for (ll i = 0; i < N; ++i) {
		cin>>numberSequence[i];
	}
	resultSequence[0] = numberSequence[0];
	ll i = 0, j = 1;
	while (i < N-1) {
		if ( max(resultSequence[i], numberSequence[j]) ) {
			resultSequence[j] = resultSequence[i] + numberSequence[j];
		} else {
			resultSequence[j] = numberSequence[j];
		}
		(maxResult < resultSequence[j]) ? maxResult = resultSequence[j] : maxResult;
		++i;
		++j;
	}
	cout<<maxResult<<endl;
	return 0;
}

int max(int pastResult, int currentValue) {
	int sum = pastResult + currentValue;
	if (sum > currentValue) {
		return 1;
	} else {
		return 0;
	}
}
