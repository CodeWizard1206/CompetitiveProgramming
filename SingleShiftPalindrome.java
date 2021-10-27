// Consider one string as input. You have to check whether the strings obtained from the input string
// with single backward and single forward shift are the same or not. If they are the same, then
// print 1; otherwise, print 0.

// Hint:

// Backward Shift : A single circular rotation of the string in which the first character becomes
// the last character and all the other characters are shifted one index to the left. For example,
// "abcde" becomes "bcdea" after one backward shift.

// Forward Shift: A single circular rotation of the string in which the last character becomes the
// first character and all the other characters are shifted to the right. For example, "abcde"
// becomes "eabcd" after one forward shift.

// Instructions:

// The system does not allow any kind of hard coded input value/values. 
// The written program code by the candidate will be verified against the inputs that are supplied
// from the system.
// For more clarification, please read the following points carefully till the end.



// Example 1:

// Input :
// sfdlmnop


// Output:
// 0



// Example 2:
// Input:
// mama


// Output:
// 1

// Explanation:


// In the first example, the string is “sfdlmnop".
// Forward Shift: fdlmnops 
// Backward Shift: psfdlmnop
// Both the strings above are not equal, so the output is 0.


// In the second example, the string is "mama"
// Forward Shift: amam
// Backward Shift: amam
// Both the strings above are equal, so the output is 1.

import java.util.Scanner;

class SingleShiftPalindrome {
    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);

        String str, bs, fs;

        str = S.nextLine();

        S.close();
        bs = str.substring(1, str.length()) + str.substring(0, 1);
        fs = str.substring((str.length() - 1), str.length()) + str.substring(0, (str.length() - 1));

        if(bs.equals(fs)) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
        
    }
}