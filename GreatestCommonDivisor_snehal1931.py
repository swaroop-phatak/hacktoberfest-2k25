import math

def gcdOfStrings(str1, str2):
    # Check if concatenation in both orders is same
    if str1 + str2 != str2 + str1:
        return ""
    
    # Find gcd of lengths
    gcd_length = math.gcd(len(str1), len(str2))
    
    # The GCD string will be prefix of that length
    return str1[:gcd_length]

# Example usage:
str1 = "ABCABC"
str2 = "ABC"
print(gcdOfStrings(str1, str2))  # Output: "ABC"
