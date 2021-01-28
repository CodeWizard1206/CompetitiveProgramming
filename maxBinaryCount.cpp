// A digital machine generates binary data which consist of a string of 0s and 1s.
// A maximum signal M, in the data, consists of the maximum number of either 1s or
// 0s appearing consecutively in the data but M can't be at the beginning or end of the
// string. Design a way to find the length of the maximum signal.

// Input:

// The first line of the input consists of an integer N, representing the length of
// the binary string. The Second line consists of a string of length N consisting
// of 0s and 1s only.

// Output:

// Print an integer representing the length of the maximum signal.

// Example:

// Input: 6
// 101000

// Output: 1

// Explanation:

// For 101000, M can be 0 at the second index or at the third index so in both
// cases max length = 1.

// Example:

// Input: 9
// 101111110

// Output:6

// Example:

// Input: 10
// 0010110111

// Output: 2

#include<bits/stdc++.h>
using namespace std;

char* substring(char* string, long int size, long int start, long int end) {
    long int newSize = size - (start + end);
    char* newString = (char*) malloc(newSize * sizeof(char));

    for (long int i = 0, j = start;i < newSize; ++i, ++j )
        newString[i] = string[j];

    return newString;

}

long int solve(char* string, long int size) {
    long int* counter = (long int*) malloc(size * sizeof(long int));
    counter[0] = 0;
    for (long int i = 1; i < size; ++i) {
        if (string[i] == string[i-1]) {
            counter[i] = counter[i-1] + 1;
        } else {
            counter[i] = 1;
        }
    }

    sort(counter,counter + size);
    return (counter[size-1]);
}

int main() {
    long int N, left = 0, right = 0;
    cin>>N;
    
    char* binaryString = (char*) malloc(N * sizeof(char));

    for (long int i = 0; i < N; ++i)
        cin>>binaryString[i];

    for (long int i = 0; binaryString[i] == binaryString[i+1]; ++i)
        ++left;
        
    for (long int i = N-1; binaryString[i-1] == binaryString[i]; --i)
        ++right;

    binaryString = substring(binaryString, N, left+1, right+1);
    N = (N - (left + right + 2));

    long int M = solve(binaryString, N);
    cout<<M<<endl;

    return 0;
}