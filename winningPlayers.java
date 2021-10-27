// In a gaming hub, N numbers of players were playing the same type of game. All players got stuck
// at the pillar level in the game, each with a different score. the owner of the gameing hub announced
// that players can pass the level if they can break two pillars. Both pillars have their own health
// points. The trick to break one pillar at a time is that if the players current score is multiplied
// up to a certain point then it should be equal to the pillars health. The same trick is used for the
// other pillar. If there is no number that can be multiplied with the players score to make the score equal
// to the players health, then that players loses. A player can only break one pillar at a time and if the
// player is not able to break both the pillars then they will not be able to clear the level.

// Write an algo. to find the total number of players who will clear that level of the game.

// Input:
// The first line of the input consists of an integer numPlayers representing the number of players(N).
// The second lines consists of N space separated integers score1, score2,....., score(N-1), representing
// the score of each player.
// The last line of the input conists of two integers health1, health2 representing the health of both the
// pillars respectiviily.

// Output:
// Print the count of the players who will clear that level of the game.

// Constraints:
// 0 <= numPlayers <= (10^9)
// 0 <= score[i] <= (10^3)
// score[i] health1, health2 <= (10^5)
// 0 <= i <= numPlayers

// Example:
// Input:
// 5
// 15 5 3 7 9
// 135 90

// Output:
// 4

// Explanation:
// Scores 15, 5, 3, 9 can be multiplied by another number to equal 135 and 90 which will break the pillar.
// So, the output is 4.

import java.util.Scanner;

class winningPlayers {
    public static void main(String args[]) {
        Scanner S = new Scanner(System.in);
        int N;
        N = S.nextInt();
        long[] scores = new long[N];

        for (int i = 0; i < N; ++i) {
            scores[i] = S.nextLong();
        }

        long health1, health2;
        health1 = S.nextLong();
        health2 = S.nextLong();

        S.close();
        long winners = 0;
        for (int i = 0; i < N; ++i) {
            boolean pillarOne = (health1%scores[i] == 0);
            boolean pillarTwo = (health2%scores[i] == 0);

            if (pillarOne && pillarTwo) {
                winners += 1;
            }
        }

        System.out.println(winners);
    }
}