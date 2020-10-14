/*

There is game of alphabet played between 2 players A and B, they are given a
list of letter/characters they both perform operations on those letter/characters
simultaneously 1 after another. A player can perform only 2 on the letter:

	1. if letter is a vowel, the player will convert it into a consonent.
	2. if letter is consonent, the player will remove it from list.
	
for performing removing operation the player will get 1 point, the player with maximum
points will win the game. Predict who will win the game if the game start with player A
to start first. If player A win print A, if player B wins print B. In case the game get
draw between both players print D.

Input :

First line will contain T as number of Test Cases.
Second line will contain n the size of list of letter.
Third line will contain the list of letter.

*NOTE : Second and Third line will be repeated T number of times.

Example:

Input:
3
5
cvito
3
eid
4
eded

Output:
Case #1 : A
Case #2 : B
Case #3 : D

Explanation:

	In case 1 player A wins as A start and remove 'c', then B will remove 'v' both will get 1 point for removal
	then a will convert i for 0 points, then b will remove the converted letter for 1 point here A is at 1 and B is 2,
	then a will remove 't' and get 1 point, b will convert 'o' for 0 point and then A will remove converted letter,
	now the total becomes A=3, B=2.
	
	In Case 2 A will convert 'e' and 'i' both for 0 point and B will remove both conversions and 1 point each, then
	A will remove 'd', total Becomes A = 1, B = 2. Hence B wins
	
	In case 3, A and B both will convert 'e' for 0 points and will 2 letters each and 2 points, total becomes A = B = 2.
	Hence the game is draw between both of them.

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

char Solve();

int main() {
	ll T;
	cin>>T;
	char testResult[T];
	for (ll i = 0; i < T; i++) {
		testResult[i] = Solve();
	}
	for (ll i = 0; i < T; i++) {
		cout<<"Case #"<<i+1<<" : "<<testResult[i]<<endl;
	}
	return 0;
}

char Solve() {
	ll N, A = 0, B = 0, x;
	cin>>N;
	char letters[N], currentPlaying = 'A';
	for (x = 0; x < N; x++) {
		cin>>letters[x];
	}
	x = 0;
	while (x < N) {
		if (letters[x] == 'a' || letters[x] == 'e' || letters[x] == 'i' || letters[x] == 'o' || letters[x] == 'u' || letters[x] == 'A' || letters[x] == 'E' || letters[x] == 'I' || letters[x] == 'O' || letters[x] == 'U') {
			++letters[x];
			if (currentPlaying == 'A')
				currentPlaying = 'B';
			else
				currentPlaying = 'A';
		} else if ( (letters[x] >= 'a' && letters[x] <= 'z') || (letters[x] >= 'A' && letters[x] <= 'Z')) {
			if (currentPlaying == 'A') {
				++A;
				currentPlaying = 'B';
			} else {
				++B;
				currentPlaying = 'A';
			}
			++x;
		}
	}
	if (A > B)
		return 'A';
	else if (A < B)
		return 'B';
	else
		return 'D';
}
