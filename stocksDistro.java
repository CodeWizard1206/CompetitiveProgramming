// The warehouse of an e-commerce company has limited stock available for each item due to
// a promotional sale. The company needs to distrtibute this stick to its distribution center
// in a particular manner. If the value of the available stock for a item is an even number,
// then the total stock is divided by 2. If it is an odd number, 1 is subtracted from it. The
// company wishes to know how many distributions can take place before the stock reaches 0.

// Write an algo. to calculate the no. of distributions that can take place before the stock
// reaches 0.

// Input:
// The input consists of an integer numStocks representing the stock available for the item (N).

// Output:
// Print an integer value representing the number of distributions that can take place before the
// stock reaches 0.

// Constraints:
// 0 <= numStock <= (10^9)

// Example:

// Input:
// 12

// Output:
// 5

// Explanation:
// 12 is even, 12/2 is 6. (1)
// 6 is even, 6/2 is 3. (2)
// 3 is odd, 3 - 1 is 2. (3)
// 2 is even, 2/2 is 1. (4)
// 1 is odd, 1 - 1 is 0. (5)
// The total number of distributions is 5.

import java.util.*;

class stockDistro {
    public static void main(String args[]) {
        Scanner S=new Scanner(System.in);
        int numStock, dist = 0;
        numStock = S.nextInt();
        S.close();
        while (numStock != 0) {
        	if ((numStock % 2) == 0) {
        		numStock = numStock / 2;
        		dist++;
        	} else {
        		numStock = numStock - 1;
        		dist++;
        	}
        }
        System.out.println(dist);
    }
}
