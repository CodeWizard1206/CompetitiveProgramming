/*

Given a non integer num, return the number of steps
to reduce it to zero. If the current number is even,
you have to divide it by 2, otherwise, you have to subtract
1 from it.

input: num = 14
output: 6

OR

This is a game where there are steps numbered from 0 to the n
steps. You will be on the nth step on the start of the game. Your
goal to reach the 0th step at the end of the game with minimum no.
of jumps. If the given step's number is even you are allowed to
jump n/2 steps no. is odd you are allowed to jump 1 step below.
Now find the minimum number of the steps required to win this game
from the given input.

Sample Input:
10

Output:
5

Explanation:
10->5 jump = 1
5->4 jump = 2
4->2 jump = 3
2->1 jump = 4
1->0 jump = 5

*/

import java.lang.*;
import java.util.*;

class ReductionStepCount {
    public static void main(String args[]) {
        Scanner s=new Scanner(System.in);
        int num,opCount = 0;
        num = s.nextInt();
        while (num != 0) {
        	if ((num % 2) == 0) {
        		num = num / 2;
        	} else {
        		num = num - 1;
        	}
            opCount++;
        }
        System.out.println(opCount);
    }
}
