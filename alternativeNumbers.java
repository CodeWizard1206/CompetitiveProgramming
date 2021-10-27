// Consider a set of random positive integers. There are multiple ways in which these numbers can be arranged,
// based on some rules. In one such arrangement, the rules used are as follows:
//     1. The first number in the new arrangement is the  largest number in the given set.
//     2. The second number in the new arrangement is the smallest number in the given set.
//     3. The third number in the new arrangement is the second largest number in the given set.
//     4. The fourth number in the new arrangement is the second smallest number in the given set.

//     ...and so on until the numbers are arranged.

// Given the set of numebrs, the program should:
//     1. Reaarange the set using the above rules, and print the new arrangement in a single line. Each number
//     should be separated by a single space.
//     2. Print Invalid input if any of the constraints mentioned below are violated.

// Example 1:
// Consider the following list of numbers:
// 4
// 5
// 3
// 6
// 1
// 2
// 9
// 8
// 7

// Here, the largest number is 9, second largest is 8, then 7, and so on.
// Similarly the smallest number is 1, second smallest is 2, then 3, and so on.

// Reaaranging as per the rules, we get the following output:
// 9 1 8 2 7 3 6 4 5

// Example 1:
// Consider the following list of numbers:
// 4
// 5
// 3
// 6
// 1
// 2
// 9
// 9
// 7

// Here the largest number 9 is repeated teice. This violates s given constraint in the constraints section
// below.
// Hence the output is:
// Invalid Input 

// Constraints:

//     1. The given set of integers should have no repeating numbers
//     2. All given numbers in the list should be positive integers.


import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class alternativeNumbers {

    public static void solution(List<Integer> arr) {
        Set<Integer> set = new HashSet<Integer>();

        for (Integer i : arr) {
            if (set.contains(i) || i < 0) {
                System.out.println("Invalid Input");
                return;
            } else {
                set.add(i);
            }
        }
        
        Collections.sort(arr);
        int l = 0;
        int h = arr.size() - 1;
        int i = 0;

        while (l <= h) {
            if (i%2 == 0) {
                System.out.print(arr.get(h) + " ");
                h--;
            } else {
                System.out.print(arr.get(l) + " ");
                l++;
            }
            i++;
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = 9;
        List<Integer> list = new ArrayList<Integer>();

        for (int i = 0; i < n; ++i) {
            list.add(s.nextInt());
        }

        solution(list);
        s.close();
    }
}