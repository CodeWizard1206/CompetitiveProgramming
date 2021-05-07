// Consider a game of N x N tic-tac-toe between two players. The game play is
// represented as an array P[N][N]. Each element of the array will have either ‘X’ or ‘O’.
// Write a function that takes the array P and integer N as input, and prints one of the
// following results based on whoever has won –
// • X wins the game
// • O wins the game
// • Game is drawn
// Program for accuracy and efficiency (no more checks than absolutely required)

import java.util.Scanner;

class Question_1 {
    static char startChar;
    //Row Winning Pattern Search
    static boolean checkRow(char[][] P, int N) {
        for (int i = 0; i <N; i++) {
            startChar = P[i][0];
            for (int j = 1; j < N; ++j) 
                if (P[i][j-1] != P[i][j]) break;
                else if (j == N-1) return true;
        }
        return false;
    }
    //Column Winning Pattern Search
    static boolean checkColumn(char[][] P, int N) {
        for (int i = 0; i <N; i++) {
            startChar = P[0][i];
            for (int j = 1; j < N; ++j)
                if (P[j-1][i] != P[j][i]) break;
                else if (j == N-1) return true;
        }
        return false;
    }
    //Diagonal Pattern Search
    static boolean checkDiagonal(char[][] P, int N) {
        startChar = P[0][0];
        for (int i = 1; i < N; ++i)
            if (P[i-1][i-1] != P[i][i]) break;
            else if (i == N-1) return true;

        startChar = P[0][N-1];
        for (int i = 1; i < N; ++i) 
            if (P[i-1][N-1-(i-1)] != P[i][N-1-i]) break;
            else if (i == N-1) return true;
        
        return false;
    }

    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);

        int N = S.nextInt();
        S.nextLine();
        String[] pattern = S.nextLine().split(" ");
        char[][] P = new char[N][N];
        int z = 0;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                P[i][j] = pattern[z].charAt(0);
                ++z;
            }

        boolean won = checkRow(P, N);
        if (!won) won = checkColumn(P, N);
        if (!won) won = checkDiagonal(P, N);

        if (won) System.out.println(startChar + " wins the game");
        else System.out.println("Game is drawn");
    }
}

/*
TestCase #1 :
3
X O X X X O O O X

Output : X wins the game

TestCase #2 :
4
X O X X O X X O O O X O X O X O

Output : X wins the game

TestCase #3 : 
4
X X O X O O O O X X O O O X X X

Output : o wins the game

TestCase #4 :
3
X O X O X O O X O

Output :
Game is drawn
*/