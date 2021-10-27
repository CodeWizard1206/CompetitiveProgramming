import java.util.*;

class minimumStock {
    public static void main(String args[]) {
        Scanner S = new Scanner(System.in);

        int count = S.nextInt();
        Map<Integer, Integer> stock = new HashMap<Integer, Integer>();

        for (int i = 0; i < count; ++i) {
            int num = S.nextInt();

            if (stock.containsKey(num)) {
                int nNum = stock.get(num) + 1;

                stock.replace(num, nNum);
            } else {
                stock.put(num, 1);
            }
        }

        S.close();
        int val = 0;

        for (Map.Entry<Integer, Integer> e : stock.entrySet()) {
            if (e.getValue() == 1) {
                val = 1;
                System.out.println(e.getKey());
                break;
            }
        }

        if (val == 0) {
            System.out.println("-1");
        }
    }
}