/*
Given a array nums of n integers where n > 1, return an array output such that output[i], is equal
to the product of all the elements of nums except nums[i].

Example: 

input : [1, 2, 3, 4];
output : [24, 12, 8 ,6];

Note : Please solve it without division and in O(n) complexity.

*/
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

int main() {
	long int n;
	long int productOfAll = 1;
	
	cin>>n;
	
	long int arrayOfNumbers[n];
	
	for (int i = 0; i < n; i++) {
		cin>>arrayOfNumbers[i];
		productOfAll = productOfAll * arrayOfNumbers[i];
	}
	
	for (int i = 0; i < n; i++) {
		cout<<(productOfAll * pow(arrayOfNumbers[i],-1))<<"\t";
		arrayOfNumbers[i] = (productOfAll * pow(arrayOfNumbers[i],-1));
	}
	
	/*for (int i = 0; i < n; i++) {
		cout<<resultArray[i]<<"\t";
	}*/
	cout<<endl;
	
	return 0;
}
