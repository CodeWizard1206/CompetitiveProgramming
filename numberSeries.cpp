/*
Given a natural number n (where 1<= n <= 9), find the sum
of the series having n numbers such that the series is n, nn, nnn,
...., nnnn....n times.
Hence, the required sum is 
	n + nn + nnn + .... + nnnn...n
	
constraints:
	1 <= n <= 9
Input: 2
output: 24

input: 4
output: 4936
*/

#include<bits/stdc++.h>
using namespace std;
int length = 1;

int sumOfSeries(int N, int size) {
	if (length<size) {
		++length;
		return (N + sumOfSeries((N*10)+size, size));
	} else {
		return N;
	}
}

int main() {
	int N;
	cin>>N;
	if (N<1 || N>9) {
		cout<<"INVALID INPUT"<<endl;
		return 1;
	}
	cout<<sumOfSeries(N, N)<<endl;
}