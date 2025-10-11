def kidsWithCandies(candies, extraCandies):
    # Find the maximum number of candies any kid currently has
    max_candies = max(candies)
    
    # Check for each kid if giving extraCandies makes them reach or exceed max_candies
    result = []
    for candy in candies:
        result.append(candy + extraCandies >= max_candies)
    
    return result

# Example usage:
candies = [2, 3, 5, 1, 3]
extraCandies = 3
print(kidsWithCandies(candies, extraCandies))
# Output: [True, True, True, False, True]
