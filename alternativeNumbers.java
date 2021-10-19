import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class alternativeNumbers {

    public static void solution(List<Integer> arr) {
        Set<Integer> set = new HashSet<Integer>();

        for (Integer i : arr) {
            if (set.contains(i) || i < 0) {
                System.out.println("Invalid Input");
                return;
            } else {
                set.add(i);
            }
        }
        
        Collections.sort(arr);
        int l = 0;
        int h = arr.size() - 1;
        int i = 0;

        while (l <= h) {
            if (i%2 == 0) {
                System.out.print(arr.get(h) + " ");
                h--;
            } else {
                System.out.print(arr.get(l) + " ");
                l++;
            }
            i++;
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        List<Integer> list = new ArrayList<Integer>();

        for (int i = 0; i < n; ++i) {
            list.add(s.nextInt());
        }

        solution(list);
    }
}