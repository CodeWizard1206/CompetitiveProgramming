// Write a function that takes two strings X, Y as input and determines whether they
// can be made equal (matching) by making at the most a single character change. A
// “change” could be adding a new character or modifying a character to another
// character. If this can be done, return true; else return false.
// Input: Nono Non
// Output: true
// Input: 123 143
// Output: true
// Input: Arm Amar
// Output: false
// Input: Pale bale
// Output: true
// Input: Noon Naoon
// Output: true

#include<bits/stdc++.h>
typedef long int li;

using namespace std;

int checkSubSequence(string stringX, string stringY) {
    li xLen = stringX.length();
    li yLen = stringY.length();
    li maxLen = (xLen > yLen) ? xLen : yLen;
    li lastX = 0;

    for (li i = 0; i < yLen; ++i) {
        for (li j = lastX; j < xLen;++j) {
            if (stringY[i] == stringX[j]) {
                ++lastX;
                break;
            }
        }
    }

    return maxLen - lastX;
}

int main() {
    string stringX, stringY;
    cin>>stringX>>stringY;

    if (checkSubSequence(stringX, stringY) == 1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    
    return 0;
}