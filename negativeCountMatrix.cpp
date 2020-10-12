/*

Given a m*n matrix grid which is stored in non-increasing order both rowwise and column-wise.
Return the number of negative numbers in grid.

example:
input: [[4, 3, 2, -1],
	[3, 2, 1, -1],
	[1, 1, -1, -2],
	[-1, -1, -2, -3]]
	
output: 8

*/
#include<iostream>
using namespace std;

int main() {
	long int row, column, negativeCount = 0;
	cin>>row>>column;
	long int mat[row][column];
	for(long int i = 0; i < row; i++) {
		for (long int j = 0; j < column; j++) {
			cin>>mat[i][j];
			if (mat[i][j] < 0) {
				negativeCount++;
			}
		}
		
	}
	cout<<endl<<negativeCount<<endl;
	return 0;
}