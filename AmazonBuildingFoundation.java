// You are in charge of preparing a recently purchased lot for one of Amazon's new
// building. The lot is covered with trenches and has a single obstacle that needs
// to be taken down before the foundation can be prepared for the building. The
// demolition robot must remove the obstacle before progress can be made on the
// building.

// Write an algorithm to determine the minimum distance required for the demolition
// robot to remove the obstacle.

// Assumptions:

// The Lot is flat except for trenches, and can be represented as a 2-dimensional grid.
// The demolition robot must start from the top-left corner off the lot, which is always
// flat, and can move one block up down, left or right at a time.
// The demolition robot cannot enter trences and cannot leave the lot.
// The flat areas are represented as 1, areas with trenches are represented by 0 and the
// obstacle is represented by 9.

// Input:
// The input to the function/method consist of one argument;
// lot, representing the 2-dimensional grid of longegers.

// Output:
// Return an longeger representing the minimum distance traversed to remove the obstacle
// else return -1.

// Constralongs
// 1 <= rows, columns <= 10^3

// Example:
// lot=
// [[1,0,0],
// [1,0,0],
// [1,9,1]]

// Output:
// 3

// Explanation:

// Starting from the left corner, the demolition robot traversed the cells(0,0)
// -> (1.0) -> (2.0) -> (2,1). The robot traversed the total distance 3 to remove
// the obstacle.

// So, the output is 3

import java.util.List;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

class Point {
    private long x;
    private long y;

    public Point(long x, long y) {
        this.x = x;
        this.y = y;
    }

    public void setX(long x) { this.x = x; }
    public void setY(long y) { this.y = y; }

    public long getX() { return this.x; }
    public long getY() { return this.y; }
}

class Coord {
    private Point pt;
    private long minDistance;

    public Coord(Point pt, long minDistance) {
        this.pt = pt;
        this.minDistance = minDistance;
    }

    public void setPt(Point pt) { this.pt = pt; }
    public void setMinDistance(long minDistance) { this.minDistance = minDistance; }

    public Point getPt() { return this.pt; }
    public long getMinDistance() { return this.minDistance; }
}

public class AmazonBuildingFoundation {
    private static long rows;
    private static long cols;
    private static List<Point> directions;

    static {
        rows = 0;
        cols = 0;
        directions = new LinkedList<Point>();
        directions.add(new Point(-1, 0));
        directions.add(new Point(0, 1));
        directions.add(new Point(1, 0));
        directions.add(new Point(0, -1));
    }

    public static boolean isValid(long x, long y) {
        return (x >= 0 && y >= 0 && x < rows && y < cols);
    }

    public static int solution(List<List<Integer>> lot) {
        List<List<Boolean>> visited = new LinkedList<List<Boolean>>();
        Queue<Coord> queue = new LinkedList<Coord>();
        for (long i = 0; i < rows; i++) {
            List<Boolean> t = new LinkedList<Boolean>();
            for (long j = 0; j < cols; ++j) {
                t.add(false);
            }
            visited.add(t);
        }

        queue.add(new Coord(new Point(0, 0), 0));

        while (!queue.isEmpty()) {
            Coord curr = queue.remove();
            if (lot.get((int) curr.getPt().getX()).get((int)curr.getPt().getY()) == 9)
                return (int) (curr.getMinDistance()%(Math.pow(10, 9) + 7));
            
            for (Point p : directions) {
                long nx = curr.getPt().getX() + p.getX();
                long ny = curr.getPt().getY() + p.getY();

                if (isValid(nx, ny) && lot.get((int)nx).get((int)ny) != 0 && !(visited.get((int)nx).get((int)ny))) {
                    List<Boolean> t = visited.get((int)nx);
                    t.set((int)ny, true);
                    visited.set((int)nx, t);
                    queue.add(new Coord(new Point(nx, ny), curr.getMinDistance()+1));
                }
            }
        }

        return -1;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        List<List<Integer>> lat = new LinkedList<List<Integer>>();
        rows = s.nextLong();
        cols = s.nextLong();


        for (long i = 0; i < rows; ++i) {
            List<Integer> temp = new LinkedList<Integer>();
            for (int j = 0; j < cols; ++j) {
                temp.add(s.nextInt());
            }
            lat.add(temp);
        }

        System.out.println(solution(lat));
        s.close();
    }
}