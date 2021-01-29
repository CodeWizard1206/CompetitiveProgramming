# 'TypeText' is a text editor. Its developers want to add a new feature that finds
# the count of unique words in a given text. The unique words are the words that only
# appear once in the tex.

# Write an algo. to help the developer add this new feature.

# Input: 

# The input consists of a string text representing the words of the text which are separated by
# whitespaces in the given text.

# Output:

# Print an integer representing the count of the unique words present in the text.

# Note:

# The input string text is case-sensitive i.e. 'AAA' and 'aaa' are considered as two unique
# words. The input string text consists of lower case and uppercase English alphabets.

# Example:

# Input:

# I love to swim and I like to travel abroad

# Output:
# 6

# Explanation:
# The unique words in the given text are : love, swim, and, like, travel, abroad.
# Hence, the output is 6.

dict = {}

def uniqueWords(word) :
    if word in dict :
        dict[word] += 1
    else :
        dict.update({word : 1})

if __name__ == '__main__' :
    stat = list(map(str, input().split()))

    for word in stat :
        uniqueWords(word)

    wordCount = 0

    for element in dict :
        if (dict[element] == 1) :
            wordCount += 1

    print(wordCount)