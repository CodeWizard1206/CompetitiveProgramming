# The media company "GlobalAd" has received a batch of advertisement from different product brands.
# The batch of advertisements is a numeric value where each digit represents the number of advertisements
# the media company has received from different product brands. Since the company banners permit only even
# numbers of advertisements to be displayed, the media company needs to know the total number of advertisements
# it will be able to display from the given batch.

# Write an algo. to calculate the total number of advertisements that will be displayed from the batch.

# Input:
# The input consists of an integer batch, representing the batch of advertisements.

# Output:
# Print an integer representing the total number of advertisements that will be displayed by the media company.

# Constraints:
# 0 <= batch <= (10^9)

# Note:
# 0 is considered as even digit and 1 is considered as an odd digit.

# Example:
# Input:
# 258345

# Output:
# 14

# Explanation:
# The even number in the batch are 2, 8, 4,.
# Hence the output is 2+8+4 = 14.

batch = int(input())
ads = 0

while (batch != 0) :
    digit = batch%10
    if (digit%2 == 0) :
        ads = ads + digit
    batch = int(batch/10)

print(ads)