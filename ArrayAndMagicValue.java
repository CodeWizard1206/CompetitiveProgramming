// You are given an array 'a' comprising 'n' integers. You have to calculate
// the magic value of the array 'a'. Magic value of an array is equal to the
// difference between the sum of good integers in an array and the sum of the
// bad integers in an array.

// Good integers are theones whose indexes are not changed in an array when
// sorted, rest are bad.

// Input format:
// First line of the input contain a single integer n.
// Second line of input contains 'n' space separated integers elements of array 'a'.

// Ouput format:
// Output a single integer, magic value of array 'a'.

// Constraints:
// 1 <= n <= 10^6
// 0 <= a[i] <= 10^9

// Sample Input:
// 10
// 0 4 0 0 1 3 4 1 0 2

// Sample Output;
// -13

// Explanation:
// Element at 5th index is only element which is good element.

import java.util.Scanner;
import java.util.Arrays;

class ArrayAndMagicValue {

    public static int getMagicValue(int n, int a[]) {
        int t[] = new int[n];
        for (int i = 0; i < n; i++)
            t[i] = a[i];

        Arrays.sort(t);
        int goodNum = 0, badNum = 0;

        for (int i = 0; i < n; i++)
            if (a[i] == t[i])
                goodNum += a[i];
            else
                badNum += a[i];

        return goodNum-badNum;
    }
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = s.nextInt();

        s.close();
        int _out = getMagicValue(n, a);
        System.out.println(_out);
    }
}
