public class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0;       // left pointer
        int zeroCount = 0;  // number of zeros in the current window
        int maxLen = 0;

        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0)
                zeroCount++;

            // if more than one zero, shrink the window
            while (zeroCount > 1) {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }

            // window length minus one (because we must delete one element)
            maxLen = Math.max(maxLen, right - left);
        }

        return maxLen;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 1, 0, 1};
        System.out.println(sol.longestSubarray(nums)); // Output: 3
    }
}
