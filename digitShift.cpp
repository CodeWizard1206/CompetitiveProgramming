// EasyWay is an online exam for new graduates of any discipline to find entry level jobs in their
// fields. The website generates the roll number of its registered students with the help of the
// students application numbers. The process includes a key K for generating an individual roll number.
// To generate the roll number, each digit in the application number is replaced by the Kth digit that
// comes after it in the application number. The series of digits is considered in a cycle fashion for
// the last K digits.

// Write an algo. to generate the roll number from the given application number.

// Input: 
// The input consists of two space-separated positive integers, applicaNum and key. representing the
// application number and key {k} respectively.

// Output:
// print an integer representing the roll number.

// Constraints:

// 0 <= applicaNum <= (10^9)

// Example:

// Input:
// 43251 3

// Output:
// 25143

// Explanation:
// Replace 4 with 2; 3 with 5; 5 with 4; and 1 with 3
// So the output is ; 25143.

#include<bits/stdc++.h>
using namespace std;

int main() {
    long int N;
    string applicaNum;

    cin>>applicaNum>>N;

    int *numArray = new int[applicaNum.length()];

    if (N > applicaNum.length()) {
        N = N % applicaNum.length();
    }

    long int K = N - 1;

    for (long int i = 0; i < applicaNum.length(); ++i) {
        numArray[i] = applicaNum[K] - '0';
        ++K;

        if (K == applicaNum.length()) {
            K = 0;
        }
    }

    for (long int i = 0; i < applicaNum.length(); ++i) {
        cout<<numArray[i];
    }

    return 0;
}