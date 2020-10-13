/*In this problem, we define "set" is a collection of distinct numbers. For two sets A and B,
we define their sum set is a set S(A,B) = {a + b|a belongs to A, b belongs to B}. In other word,
set S(A, B) contains all elements which can be represented as sum of an element in A and an element
in B. Given two sets A,C your task is to find set B of positive integers less than or equals 100
with maximum size such that S(A, B) = C. It is guaranteed that there is unique such set.

Input Format

The first line contains N denoting the number of elements in set A, the following line contains N space
separated integers a(i) denoting the elements of set A.

The third line contains M denoting the number of elements in set C, the following line contains M space
separated integers c(i) denoting the elements of set C.

Output Format

Print all elements of B in increasing order in a single line, separated by space.

Constraints

    1 <= N,M <= 100
    1 <= a(i), c(i) <= 100

Input : 
2
1 2
3
3 4 5

Output: 
2 3

Explanation:

If e is an element of set B, then e+2 is an element of set C, so we must have e <= 3. Clearly, e cannot be 1 because
1+1 = 2 is not an element of set C. Therefore, B = {2,3}.

*/
#include<iostream>
using namespace std;

int main() {
    int temp = 0,A,C;
    cin>>A;
    int *arrA = malloc(sizeof(int)*A);
    
    for(int i=0;i<A;i++)
        cin>>arrA+i;

    cin>>C;
    int *arrC = malloc(sizeof(int)*C);
    
    for(int i=0;i<C;i++)
        cin>>arrC+i;
    
    int *arrB = malloc(sizeof(int)*101);

    for(int i=0;i<C;i++) {
        for(int j=0;j<A;j++) {
            temp = arrC[i]-arrA[j];
            if(temp>=0)
                arrB[temp]++;
        }
    }

    for(int i=0;i<101;i++) {
        if(arrB[i]==A)
            cout<<i;
    }
    return 0;
}