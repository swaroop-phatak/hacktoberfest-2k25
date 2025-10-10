class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0;
        int maxWindowSize = 0;
        int zeroCount = 0;

        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxWindowSize = Math.max(maxWindowSize, right - left + 1);
        }

        return maxWindowSize - 1;
    }
}
