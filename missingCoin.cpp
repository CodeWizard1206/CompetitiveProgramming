/*

A teacher a came to the class with a large box that has several coins. Each coin
has a number printed on it. Before coming to the class, she ensured that ALL
the numbers occur an EVEN number of times. However, while coming to the class,
one coin fell down and get lost. she wants to find out the number on the missing
coin.

Input : The original number of Coins N and the actual number on each coin,
separated by N-1 spaces.

Sample Input:

8
5 7 2 5 2 5

Sample Output:

5

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	long int N;
	cin>>N;
	int* coins = (int*) malloc((N-1) * sizeof(int));
	int size = 0;
	for (int i = 0; i < (N-1); i++) {
		cin>>coins[i];
		if (size < coins[i])
			size = coins[i];
	}
	int* counts = (int*) malloc(size * sizeof(int));
	for (int i = 0; i < (N-1); i++) {
		++counts[(coins[i] - 1)];
	}
	for (int i = 0; i < size; i++) {
		if (counts[i] != 0 && counts[i]%2 != 0) {
			cout<<i+1<<endl;
			break;
		}
	}
	return 0;
}
