// Write a program to find the number of ways in which we can transform a wrong word to a correct word by
// removing zero or more characters from the wrong word. Given: strings, i.e. S1 (for wrong word) and
// S2 (for correct word).


// Example 1:
// Input :
// Indiiian - String S1, i.e. wrong word 
// Indian - String S2, i.e. correct word


// Output:
// 3 


// Explanation: The three ways will be "ind..ian", "indi.an" and "ind.i.an" is where a character is removed.


// Example 2:
// Input :
// ggoog - String S1, i.e. wrong word 
// go - String S2, i.e. correct word

// Output:
// 4

// Explanation: 
// The four ways will be "g.o..", "g..o.",
// ".go.." and ".g.o.," "." is where characters are removed.

import java.util.Scanner;

class eliminateCharacters {
    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);

        String s1 = S.nextLine();
        String s2 = S.nextLine();

        S.close();
        int output = eliminateChar(s1, s2);
        System.out.println(output);
    }

    static int eliminateChar(String s1, String s2) {
        
        int row = s2.length();
        int col = s1.length();

        int[][] compareMatrix = new int[row+1][col+1];

        for (int i = 0; i < col+1; ++i) {
            compareMatrix[0][i] = 1;
        }
        
        for (int i = 1; i < row+1; ++i) {
            compareMatrix[i][0] = 0;
        }

        for (int i = 1; i < row+1; ++i) {
            for (int j = 1; j < col+1; ++j) {
                if (s2.charAt(i-1) == s1.charAt(j-1)) {
                    compareMatrix[i][j] = compareMatrix[i][j-1] + compareMatrix[i-1][j-1];
                } else {
                    compareMatrix[i][j] = compareMatrix[i][j-1];
                }
            }
        }

        return compareMatrix[row][col];
    }
}