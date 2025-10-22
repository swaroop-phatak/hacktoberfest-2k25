import bisect
from typing import List

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        # 1. Combine and sort jobs by end time
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        
        n = len(jobs)
        # dp[i] is the max profit considering jobs[0...i]
        # In this space-optimized approach, dp[i] stores the max profit ending at end time i
        # A simpler DP approach uses a dictionary or a list indexed by job index.
        
        # dp[i] = max profit considering the first i jobs
        dp = [0] * (n + 1)
        
        # Extract the sorted end times for binary search
        sorted_end_times = [job[1] for job in jobs]

        for i in range(n):
            start, end, p = jobs[i]
            
            # Option 1: Don't include the current job i
            # Profit is the same as the max profit considering jobs[0...i-1]
            profit_not_take = dp[i]

            # Option 2: Include the current job i
            # Find the largest index j such that job j's end time is <= current job's start time
            # We search in the *previous* job end times (up to job i-1)
            
            # We use bisect_right on the end times to find the insertion point, which corresponds
            # to the first end time > start time. The index just before that is the job we want.
            
            # Find index 'j' of the last non-overlapping job (end_time <= start)
            # bisect.bisect_right(a, x) returns an insertion point.
            # We search for 'start' in the array of end times up to index i-1.
            # The indices for dp are 1-based, so we adjust.
            
            # Find the index in the sorted_end_times[:i]
            j = bisect.bisect_right(sorted_end_times, start, hi=i)
            # j is the index in the 0-based array. The DP index is j-th job (1-based index)
            
            prev_max_profit = dp[j]
            profit_take = p + prev_max_profit
            
            # Update dp[i+1] (for the current job)
            dp[i+1] = max(profit_take, profit_not_take)
            
        return dp[n]
