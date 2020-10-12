/*

Given 2 string stringOne and stringTwo, your task is to find the longest common subsequence of character in the 2 strings
example :
stringOne : aabaabaa
stringTwo : babaabab

output : abaaba

*/
#include<bits/stdc++.h>

using namespace std;

int main() {
	long int x, y;
	string result = "";
	cin>>x>>y;
	long int commonMatrix[x+1][y+1];
	char stringX[x], stringY[y], pointerMatrix[x][y];

	for (int i = 0; i < x; i++) {
		cin>>stringX[i];
	}

	for (int i = 0; i < x; i++) {
		cin>>stringY[i];
	}

	for (int i = 0; i < y+1; i++) {
		commonMatrix[0][y] = 0;
	}

	for (int i = 0; i < x+1; i++) {
		commonMatrix[x][0] = 0;
	}
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (stringX[i] == stringY[j]) {
				commonMatrix[i+1][j+1] = (commonMatrix[i][j] + 1);
				pointerMatrix[i][j] = 'D';
			} else if (commonMatrix[i+1][j] >= commonMatrix[i][j+1]) {
				commonMatrix[i+1][j+1] = commonMatrix[i+1][j];
				pointerMatrix[i][j] = 'L';
			} else {
				commonMatrix[i+1][j+1] = commonMatrix[i][j+1];
				pointerMatrix[i][j] = 'U';
			}
		}
	}
	
	x--;
	y--;
	
	while (x >= 0 && y >= 0) {
		if (pointerMatrix[x][y] == 'D') {
			result = result + stringY[y];
			x--;
			y--;
		} else if (pointerMatrix[x][y] == 'U') {
			x--;
		} else if (pointerMatrix[x][y] == 'L') {
			y--;
		}
	}
	reverse(result.begin(), result.end());	
	cout<<endl<<result;
	return 0;
}
