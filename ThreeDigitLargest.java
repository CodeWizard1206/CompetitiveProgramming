// You are given a number. Find the largest 3 digit number contained within the gven range of
// all possible 3 digit number subsets in the given number.

// Sample Test Case

// Test Case 1:

// Input : 6478434
// Output: 843

// Explanation : In the given input number the possible subsets are 647,478,784,843,434 among
//     which the largest number is 843.

// Test Case 2:

// Input : 3001213
// Output: 300

// Explanation : In the given input number the possible subsets are 300,001,012,121,213 among
//     which the largest number is 300.

import java.util.*;

class ThreeDigitLargest {
    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);

        int num = S.nextInt();
        int larger = 0;

        do {
            int rem = num%1000;
            if (rem > larger) {
                larger = rem;
            }
            num = num/10;
        } while (num >= 1000);

        if (num > larger) {
            larger = num;
        }

        System.out.println(larger);
    }
}