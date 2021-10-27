// Given a set of points in a plane, check whether the points lie on a Straight
// line or not, If they lie on a straight line return the equation else return 0.

// Input Format :
//     >First line contains number of points in the plane.
//     >Second line contains x,y coordinates of all the points which are divided
//     with spaces.

// Output Format : 
//     >Equation of the line(str) if the points lie on aa plane or 0(str).

// Sample Input :
// 3
// 1 1 2 2 3 3

// Output : 1x - 1y = 0

// Explanation:
//     The three points here are [1, 1], [2, 2], [3, 3]. These lie on a line so it
//     returned the equation.

import java.util.Scanner;

class StraightLine {
    static int xDiff = 1;
    static int yDiff = 1;

    static boolean checkLine(int[][] coord) {
        if (coord.length == 0)
            return false;

        double x1 = coord[0][0];
        double y1 = coord[0][1];
        Double slope = null;

        for (int i = 1; i < coord.length; ++i) {
            double x2 = coord[i][0];
            double y2 = coord[i][1];

            if ((x2 - coord[i-1][0]) > xDiff)
                xDiff = (int) x2 - coord[i-1][0];

            if ((y2 - coord[i-1][1]) > yDiff)
                yDiff = (int) y2 - coord[i-1][1];

            if ((x2 - x1) == 0)
                return false;
            
            if (slope == null) {
                slope = ((y2 - y1) / (x2 - x1));
                continue;
            }

            double slope2 = ((y2 - y1) / (x2 - x1));
            if (slope != slope2)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);
        int n = S.nextInt();
        int[][] coord = new int[n][2];

        for (int i = 0; i < n; ++i) {
            coord[i][0] = S.nextInt();
            coord[i][1] = S.nextInt();
        }

        S.close();
        if (checkLine(coord))
            System.out.println(xDiff + "x-" + yDiff + "y=0");
        else
            System.out.println("0");
    }
}