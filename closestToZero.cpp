/*
You have been given an N size integer Array A. you need to print the number with value closest to Zero.
If there are multiple candidates then print the number with greater value

Input: 

5
0 2 3 4 5

Output: 0

Note: Print the value of the element closest to zero, If there are multiple candidates then print the number with greater value.

*/

#include<bits/stdc++.h>
using namespace std;

int Solve (int N, vector <int> A) {
    int result = 100, temp = 0;
    vector <int> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = 0 - A[i];
    }
    for (int i = 0; i < N; i++) {
        if (B[i] <= 0) {
            if (result > A[i]) {
                result = A[i];
            }
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector <int> A(N);
    for (int a_i = 0; a_i < N; ++a_i) {
        cin >> A[a_i];
    }
    int out = Solve(N, A);
    cout << out << "\n";
}