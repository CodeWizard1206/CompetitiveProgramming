/*

Given a non integer num, return the number of steps
to reduce it to zero. If the current number is even,
you have to divide it by 2, otherwise, you have to subtract
1 from it.

input: num = 14
output: 6

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
        		opCount++;
        	} else {
        		num = num - 1;
        		opCount++;
        	}
        }
        System.out.println(opCount);
    }
}
