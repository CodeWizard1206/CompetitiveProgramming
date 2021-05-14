import java.util.*;
import java.math.BigDecimal;

class BigDecimalArray {
    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);
        int N = S.nextInt();
        String[] numArray = new String[N];

        for (int i = 0; i < N; ++i) {
            numArray[i] = S.next();
        }

        Arrays.sort(numArray, 0, N, new Comparator<Object>() {
            public int compare(Object numOne, Object numTwo) {
                BigDecimal bigOne = new BigDecimal((String) numOne);
                BigDecimal bigTwo = new BigDecimal((String) numTwo);
                return bigTwo.compareTo(bigOne);
            }
        });

        for (int i = 0; i < N; ++i) {
            System.out.println(numArray[i]);
        }
    }
}