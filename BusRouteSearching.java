/* Bucket is planning to make a very long journey across the countryside by bus.
Her journey consists of N bus routes, numbered from 1 to N in the order she must take them.
The buses themselves are very fast, but do not run often. The i-th bus route only runs every Xi days.

More specifically, she can only take the i-th bus on day Xi, 2Xi, 3Xi and so on.
Since the buses are very fast, she can take multiple buses on the same day.

Bucket must finish her journey by day D, but she would like to start the journey as late as possible.
What is the latest day she could take the first bus, and still finish her journey by day D?

It is guaranteed that it is possible for Bucket to finish her journey by day D.

Input
The first line of the input gives the number of test cases, T. T test cases follow.
Each test case begins with a line containing the two integers N and D.
Then, another line follows containing N integers, the i-th one is Xi.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1)
and y is the latest day she could take the first bus, and still finish her journey by day D.

Limits
Time limit: 10 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Xi ≤ D.
1 ≤ N ≤ 1000.
It is guaranteed that it is possible for Bucket to finish her journey by day D.

Test set 1
1 ≤ D ≤ 100.

Test set 2
1 ≤ D ≤ 1012.

Sample

Input                   Output

3
3 10
3 7 2                 Case #1: 6
4 100
11 10 5 50            Case #2: 99
1 1
1                     Case #3: 1
*/


import java.util.*;

class BusRouteSearching {
  public static void main(String args[]) {
    Scanner S= new Scanner(System.in);
    int noOfTestCases = S.nextInt();
    Long[] testCasesResult = new Long[noOfTestCases];
    for (int i = 0; i<noOfTestCases; i++) {
      int noOfRoutes = S.nextInt();
      long noOfDays = S.nextLong();
      Integer[] Bus = new Integer[noOfRoutes];
      long low = 0, high = noOfDays;
      for (int j = 0; j<noOfRoutes; j++) {
        Bus[j] = S.nextInt();
      }

      while (low < high) {
        long mid =  (((low + high) + 1)/2);
        if (findDay(mid,noOfDays,noOfRoutes, Bus)) {
          low = mid;
        } else {
          high = mid - 1;
        }
      }
      testCasesResult[i] = low;
    }
    S.close();
    for (int i = 1; i<=noOfTestCases; i++) {
      System.out.println("Case #"+i+": "+testCasesResult[i-1]);
    }
  }

  private static boolean findDay (long mid, long noOfDays, int noOfRoutes, Integer[] Bus) {
    for (int j =0; j<noOfRoutes; j++) {
      if (mid % Bus[j] != 0) {
        mid += (Bus[j] - mid % Bus[j]);
      }
    }
    return mid <= noOfDays;
  }
}
