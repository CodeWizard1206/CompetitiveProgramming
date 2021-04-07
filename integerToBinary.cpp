// Write a program to convert a integer number into its equivalent binary number.

#include<bits/stdc++.h>
using namespace std;
typedef long int li;

string intToBin(li num) {
    li maxVal = 1;
    li length = 1;
    while (num - maxVal > 0) {
        if (num - maxVal > 0) {
            maxVal = maxVal * 2;
            length++;
        }
    }

    string binCode = "";

    while (num > 0) {
        if (num - maxVal >= 0) {
            binCode = binCode + "1";
            num = num - maxVal;
            maxVal = maxVal / 2;
        } else {
            binCode = binCode + "0";
            maxVal = maxVal / 2;
        }
    }

    if (binCode.length() != length) {
        do {
            binCode = binCode + "0";
        } while (binCode.length() != length);
    }

    return binCode;
}

int main() {
    li num;
    cin>>num;
    string result = intToBin(num);
    cout<<result;
    return 0;
}