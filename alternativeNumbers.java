import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class alternativeNumbers {

    public static void solution(int[] arr) {
        Set<Integer> set = new HashSet<Integer>();

        for (int i : arr) {
            if (set.contains(new Integer(i)) or i < 0) {
                System.out.println("Invalid Input");
                return;
            } else {
                set.add(new Integer(i));
            }
        }
        
        int l = 0;
        int h = arr.length - 1;
        int i = 0;

        while (l < h) {
            if (i%2 == 0) {
                System.out.print(arr[h] + " ");
                h--;
            } else {
                System.out.print(arr[l] + " ");
                l++;
            }
            i++;
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; ++i) {
            arr[i] = s.nextInt();
        }

        solution(arr);
    }
}