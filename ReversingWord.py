# Write a program to reverse each word in a string without changing
# the order of the word.

# Input Format :
# First Line : The input string

# Output Format :
# First Line : The reversed string

# Example :

# Input :
# Reverse each word in string

# Output:
# esreveR hcae drow ni gnirts

def main() :
    string = input()
    reverseString = list()
    for word in string.split(" ") :
        reverseString.append(word[::-1])
    print(" ".join(reverseString))

if __name == "__main__" :
    main()