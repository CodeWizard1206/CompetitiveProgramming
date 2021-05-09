# In certain decryption algorithms, it is beneficial to calculate the number of times a specific
# character occurs in a piece of text. The number of times a character occurs is reffered to as
# the frequency of occurance of the character. Given a piece of text as the input, the program
# should find the most frequent charcter in it.

# That is :
#     > The program should print the character or characters that occurs the most  number of times in the given text.
#     > If there are are multiple charaters with the same maximum frequency, the program should print all those, separated
#     by a single comma, in the given order in which they first appear in the input string.
#     > If the inpu ttext is less than 2 characters long, print invlaid input.

# Constraints :
#     > The program should talk in to consideration only English alphabets, and digits.
#     > Uppercase and lowercase letters are considered different.
#     > The input text should be at least 2 character long.

# Input Format :
#     The first line contains a string, denoting the input text.

# Sample Case 0 :
#     >Input :
#         Web application
#     >Output :
#         a,p,i

#     >Explanation : 
#         The character that occur the most number of times are 'a', 'p', 'i'. They should be printed in the order in which
#         they first appear in the input and separated by commas.

# Sample Case 1 :
#     >Input :
#         On a scale of 1 to 11
#     >Output : 
#         1

#     >Explanation :
#         White spaces is ignored, and the characters 'O' and 'o' are counted separately, hence '1' is the character occurs
#         the most number of times.

def findMostFrequentCharacters(text) :
    dict = {}
    greater = 1

    wordList = text.split(" ")
    for word in wordList :
        for char in word :
            if char in dict :
                dict[char] += 1
                if (dict[char] > greater) :
                    greater = dict[char]
            else :
                dict.update({char : 1})

    out = list()
    for char in dict :
        if (dict[char] == greater) :
            out.append(char)

    return (",".join(out))

def main() :
    text = str(input())
    print(findMostFrequentCharacters(text))

if __name__ == '__main__' :
    main()
