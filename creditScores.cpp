// The new bank, "YoursPay", has a list of N customers' bank account balances. The list consists
// of both positive and negative balances. The positive balance signifies the current year's customers
// and the negative balance signifies last year's customers. The bank has decided to offer shortlisted
// customers credit scores to their credit cards. The credit scores will be the sum of the two balances
// from the list with the smallest product when multiplied. If the credit score is positive then the credit will
// be provided to the current year's customer, otherwise it will go to the last years customer.

// Write an algo. to find the credit score.

// Input:
// The first line of input consists of an integer numCustomer, representing the number of banking customers(N).
// The second line of input consists of N space separated integers balance1, balance2,....., balanceN, representing
// the customer's bank balances.

// Output:
// Print an Integer representing the credit score.

// Costraints:
// 2 <= numCustomer <= (10^9)
// -(10^9) <= balance[i] <= (10^9)
// -(10^9) <= i <= numCustomer

// Example:
// Input:
// 5
// 1 8 -5 7 5

// Output:
// 3

// Explanation:
// The two balances with the smallest product are 8 and -5 (8 * -5 = 40)
// The sum is 8 + (-5) = 3
// Hence the output is 3.

#include<bits/stdc++.h>
typedef long int li;
using namespace std;

void findMinProduct(li* a, li N) {
    li min = 1000000000, min_i = 0, min_j = 0;

    for (li i = 0; i < (N-1); ++i) {
        for (li j = (i+1); j < N; ++j) {
            if (min > (a[i] * a[j])) {
                min = a[i] * a[j];
                min_i = i;
                min_j = j;
            }
        }
    }

    if (min_i <  min_j) {
        li diff = a[min_i] + a[min_j];
        cout<<diff;
    } else {
        li diff = a[min_i] + a[min_j];
        cout<<diff;
    }
}

int main() {
    li N;
    cin>>N;

    li *list = new li[N];

    for (li i = 0; i < N; ++i) {
        cin>>list[i];
    }

    findMinProduct(list, N);
    return 0;
}