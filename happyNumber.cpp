/*

Write an algorithm to determine if a number is "happy". A happy number is a number
defined by the following process. Starting with a positive integer, replace the
number by the sum of the squares of its digits, and repeat the process until the
number is equals 1, or it loops endlessly in a cycle which does not include 1. Those
numbers for which this process ends in 1 are happy numbers.

Sample:

Input : 19	Output : true

Explanation:
(1^2) + (9^2) = 82
(8^2) + (2^2) = 68
(6^2) + (8^2) = 100
(1^2) + (0^2) + (0^2) = 1

*/
#include<bits/stdc++.h>
using namespace std;
const int limit = 1000000;

int addDigitSquare(int );

int main() {
	int N, i = 0;
	cin>>N;
	if (N >= 1) {
		while(i < limit) {
			if (N <= 9)
				N = pow(N,2);
				if (N == 1) {
					cout<<"true"<<endl;
					break;
				}
			else {
				N = addDigitSquare(N);
				if (N == 1) {
					cout<<"true"<<endl;
					break;
				}
			}
			++i;
		}
		if (i == limit)
			cout<<"false"<<endl;
	} else {
		cout<<"false"<<endl;
	}
	return 0;
}

int addDigitSquare(int N) {
	if (N/10 == 0)
		return pow(N,2);
	else {
		int n1 = N%10;
		N = N/10;
		return addDigitSquare(N) + pow(n1, 2);
	}
}