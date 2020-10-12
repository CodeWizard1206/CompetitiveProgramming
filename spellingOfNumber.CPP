// Given a number n, if n <= 9 or n >=1 then print the spelling of that number else print less than 1 or greater than 9.

// test Case 1:
// input : 9
// output: nine

// test Case 2 :
// input : 11
// output : greater than 9

#include<bits/stdc++.h>
using namespace std;


int main() {
	string spellings[9] = {
		"ONE",
		"TWO",
		"THREE",
		"FOUR",
		"FIVE",
		"SIX",
		"SEVEN",
		"EIGHT",
		"NINE"
	};
	int num;
	cout<<"Enter a Number : ";
	cin>>num;
	if (num < 1) {
		cout<<"Number is less than 1!"<<endl;
	} else if (num > 9) {
		cout<<"Number is greater than 9!"<<endl;
	} else {
		cout<<spellings[--num]<<endl;
	}
	return 0;
}