from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums: return 0
        if len(nums) == 1: return nums[0]
        
        # Helper function for the basic House Robber (non-circular)
        def simple_rob(arr):
            # Same logic as House Robber I
            if not arr: return 0
            if len(arr) == 1: return arr[0]

            dp_i_minus_2 = arr[0]
            dp_i_minus_1 = max(arr[0], arr[1])

            for i in range(2, len(arr)):
                dp_i = max(arr[i] + dp_i_minus_2, dp_i_minus_1)
                dp_i_minus_2 = dp_i_minus_1
                dp_i_minus_1 = dp_i
            return dp_i_minus_1

        # The max profit from a circular arrangement is the maximum of:
        # 1. Robbing from house 0 up to house n-2 (skipping the last house)
        # 2. Robbing from house 1 up to house n-1 (skipping the first house)
        
        # Case 1: Excluding the last house (nums[:-1])
        profit_excl_last = simple_rob(nums[:-1])
        
        # Case 2: Excluding the first house (nums[1:])
        profit_excl_first = simple_rob(nums[1:])
        
        return max(profit_excl_last, profit_excl_first)
