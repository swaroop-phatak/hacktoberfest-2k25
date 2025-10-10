from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if not piles:
            return 0

        # Helper: does speed k allow finishing within h hours?
        def can_finish(k: int) -> bool:
            hours = 0
            for p in piles:
                # ceiling division: hours needed for this pile at speed k
                hours += (p + k - 1) // k
                # tiny optimization: stop early if hours already > h
                if hours > h:
                    return False
            return hours <= h

        left, right = 1, max(piles)
        answer = right

        while left <= right:
            mid = (left + right) // 2
            if can_finish(mid):
                answer = mid          # mid works, try smaller
                right = mid - 1
            else:
                left = mid + 1        # mid too slow, try larger

        return answer
