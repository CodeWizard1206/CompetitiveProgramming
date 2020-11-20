/*

You are given with string, your task is to print the sum of
ASCII values of each character of the string.

Input:
hello

Output:
532

*/

#include<bits/stdc++.h>
using namespace std;

int Solve(char* s_arr, int length) {
	int sum = 0;
	for(int i = 0; i < length; ++i)
		sum += s_arr[i];
	
	return sum;
}

int main() {
	string str;
	cin>>str;
	char* s_arr = (char*) calloc(str.length(), sizeof(char));
	strcpy(s_arr, str.c_str());
	cout<<Solve(s_arr, str.length())<<endl;
	return 0;
}
