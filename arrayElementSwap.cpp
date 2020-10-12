/*

You are given a list of N unique positive numbers ranging from 0 to (N-1). Write an algorithm
to replace the value of each number with its corresponding index value in the list.

input : 

the first line of the input consist of an integer size, representing the size of the list(N).
the next line consists of N space separated integers representing the given list of numbers.

output:

print N space separated integers representing the list obtained by replacing the values of the
numbers with their corresponding index values in the list.

constraints
0 <= size <= 10^5
0 <= arr[i] <= 10^5
0 <= i < size

note:  all the numbers in the list are unique

example:
input:4
3 2 0 1
output: 2 3 1 0

input:6
4 3 0 5 1 2
output: 2 4 5 1 0 3

*/
#include<iostream>
using namespace std;

int main() {
	long int size;
	cin>>size;
	long int arr[size],resultArr[size];
	for(long int i = 0; i < size; i++) {
		cin>>arr[i];
		resultArr[arr[i]] = i;
	}
	for(long int i = 0; i < size; i++) {
		cout<<resultArr[i]<<"  ";
	}
	cout<<endl;
	return 0;
}