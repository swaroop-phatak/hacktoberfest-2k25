class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLen = 0;

        while (right < nums.length) {
            if (nums[right] == 0) zeroCount++;

            // If more than one zero, shrink window
            while (zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }

            // Calculate window size excluding one deletion
            maxLen = Math.max(maxLen, right - left);
            right++;
        }

        return maxLen;
    }
}
