// Amazon is building a way to help customer search review quicker by providiing real-time suggestions
// to search terms when the customer starts typing. when gievn a minimum of two characters into the search
// field the system will suggest at the most three keywords from the review word repository. As the customer
// continues to type in the reviews search bar the relevant keyword suggestions will update automatically.

// Write an algorithm that will output a maximum of three keywords suggestion after each character is typed
// by the customer into the search field.

// If there are more than three acceptable keywordds, return the keywords that are first in alphabetical order.
// Only return the keywords suggestions after the customer has entered two characters.
// Keyword suggestions must start with the characters already typed.
// Both the repository and the customerQuery should be compared in a case-insensitive way.

// Input
// The input to the method function consist of the arguments:
//     repository - a list of unique strings representing the various keywords from the Amazon review comment
//     section;

//     customerQuery - a string representing the full search query of the customer.

// Output
// Return a list of a list of strings in lower case, where each list represents the keyword suggestions made
// by the system as the customer types each character of the customerQuery. Assume the customer types
// character in order without deleting or removing any characters. I an output is not possible, return an
// empty array([]).

// Example
// Input :
// repository = ["mobile", "mouse", "moneypot", "monitor", "mousepad"]
// customerQuery = "mouse"

// Ouput:
// ["mobile", "moneypot", "monitor"]
// ["mouse", "mousepad"]
// ["mouse", "mousepad"]
// ["mouse", "mousepad"]

// Explanation:
// The chain of words that will generate in the search box will be : mo, mou, mous, mouse and each line
// from output shows the suggestion of "mo", "mou", "mous", "mouse", respectively in each line.
// For the keyword suggestions made by the system that are generated for "mo", the matches that will be generated
// are:["mobile". "mouse", "moneypot", "monitor", "mopusepad"]
// Alphabetically, they will be reordered to ["mobile", "moneypot", "monitor", "mouse", "mopusepad"]
// Thus the keyword suggestions made by the system are ["mobile", "moneypot", "monitor"].

import java.util.Scanner;
import java.util.List;
import java.util.LinkedList;
import java.util.Collections;
import java.util.stream.Collectors;

public class AmazonKeywordSearch {
    public static List<List<String>> solution(List<String> repository, String customerQuery) {
        List<List<String>> ret = new LinkedList<List<String>>();

        for (int i = 2; i <= customerQuery.length(); ++i) {
            String nStr = customerQuery.substring(0, i).toLowerCase();
            List<String> filteredList = repository.stream()
                    .filter(x -> x.toLowerCase().startsWith(nStr))
                    .map(String::toLowerCase)
                    .collect(Collectors.toList());
            
                    Collections.sort(filteredList);
                    if (filteredList.size() > 3)
                        filteredList = filteredList.subList(0, 3);
                    
                    ret.add(filteredList);
        }
        return ret;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        List<String> repository = new LinkedList<String>();

        int n = s.nextInt();
        s.nextLine();

        for (int i = 0; i < n; ++i)
            repository.add(s.nextLine());
        
        String customerQuery = s.nextLine();
        List<List<String>> result = solution(repository, customerQuery);
       
        result.stream()
            .map(
                x -> x.stream().collect(Collectors.joining(" "))
            ).map(x -> x + "\n")
            .collect(Collectors.toList())
            .forEach(
                e -> System.out.println(e)
            );
    }
}