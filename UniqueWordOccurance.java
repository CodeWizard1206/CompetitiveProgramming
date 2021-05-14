import java.util.*;
import java.io.*;

class UniqueWordOccurance {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        String string;
        try {
            File file = new File("abc.txt");
            BufferedReader buffer = new BufferedReader(new FileReader(file));
            while((string = buffer.readLine()) != null) {
                String[] strArray = string.split("\\s");

                for (String str : strArray) {
                    if (map.containsKey(str)) {
                        map.replace(str, map.get(str) + 1);
                    } else {
                        map.put(str, 1);
                    }
                }
            }

            List<Map.Entry<String, Integer>> list = new ArrayList<>(map.entrySet());

            Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
                public int compare(Map.Entry<String, Integer> a, Map.Entry<String, Integer> b) {
                    Integer x = a.getValue();
                    Integer y = b.getValue();

                    return y.compareTo(x);
                }
            });
            for (int i = 0; i < 10; ++i) {
                Map.Entry e = list.get(i);
                System.out.println(e.getKey() + " : " + e.getValue());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}