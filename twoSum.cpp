/*

Given a Array of integer of size N. return indices of the two numbers such that
they add up to a specific number t. You may assume that each input would have exactly
one solution, and you may not use the same element twice.

Input format:

First line will contain a integer number T, defining number of test cases.
Second line will contain 2 integer number, N and t, where N is Size of array and t is target addition.
Third line will contain N space-separated array of integer numbers.

Input:

3
5 10
2 4 8 6 1
4 3
1 2 4 8
8 15
6 4 9 2 5

Output:

Case #1 : [1, 3]
Case #2 : [0, 1]
Case #3 : [0, 2]

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct resultArray {
	ll array[2];
};

void Solve(ll* );

int main() {
	ll T;
	cin>>T;
	struct resultArray testResult[T];
	for (ll i = 0; i < T; i++) {
		 Solve(testResult[i].array);
	}
	for (ll i = 0; i < T; i++) {
		cout<<"Case #"<<i+1<<" : ["<<testResult[i].array[0]<<", "<<testResult[i].array[1]<<"]"<<endl;
	}
	return 0;
}

void Solve(ll* pointerArray) {
	ll N, t;
	cin>>N>>t;
	ll number[N];
	for (ll x = 0; x < N; x++)
		cin>>number[x];
	
	for (ll x = 0; x < N-1; x++) {
		for (ll y = x+1; y < N; y++) {
			ll _temp = number[x] + number[y];
			if (_temp == t) {
				*pointerArray = x;
				*(pointerArray + 1) = y;
				x = N - 1;
				break;
			}
		}
	}
}
