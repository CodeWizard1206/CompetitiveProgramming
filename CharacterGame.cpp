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
    li lenDiff = xLen - yLen;

    if (lenDiff >= -1 && lenDiff <= 1) {

        li lastX = 0, i;

        for (i = 0; i < xLen; ++i) {
            //if stringY is checked but not stringX, completely then return false.
            if (i < xLen-1 && lastX >= yLen)
                return 0;

            for (li j = lastX; j < lastX+2 && j < yLen;++j) { //With this condition this oinner loop will execute
                                                            // at-max 2 times not more than that for each iteration of outer loop.
                if (stringX[i] == stringY[j]) {
                    lastX = j+1;
                    break;

                } else if (j == lastX+1) { // This block is only accessed in the last iteration of inner loop.
                    if (stringX[i+1] != stringY[j-1] && stringX[i+1] != stringY[j]) {
                        //if contiguous 2 characters from stringX mismatches with
                        //contiguous 2 charcters of stringY then result is returned as false(0).
                        return  0;

                    } else if (stringX[i+1] == stringY[j-1]) {
                        //if the (ith + 1) character matches with previous jth character continue to check
                        //next 2 charcters and skip these 2 for the next iteration.
                        lastX = j;
                        i += 1;
                        break;
                    } else {
                        //if the (ith + 1) character matches with jth character continue to check
                        //next 2 charcters and skip these 2 for the next iteration.
                        lastX = j+1;
                        ++i;
                        break;
                    }
                }
            }
        }

        if (i >= xLen && lastX < yLen-1)  //if stringX is checked but not stringY, completely then return false.
            return 0;

    } else {
        return 0;
    }

    return 1;

    //With this approach if i check for strings like :
    // stringX : abcdefgh
    //stringY : ijklmnop

    //The outer loop will run only 1 times and inner loop 2 times for each outter loop,
    // i.e., for i = 0 :
    //              j 1-time
    //              j 2-time
    // then return false;
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