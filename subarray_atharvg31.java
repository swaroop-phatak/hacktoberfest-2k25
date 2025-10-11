public class LongestSubarrayAfterDeletingOne {

    public static int longestSubarray(int[] nums) {
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.length; right++) {
            // Count zeros in current window
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If more than one zero, shrink window from left
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Window size minus one zero (since one element must be deleted)
            maxLen = Math.max(maxLen, right - left);
        }

        return maxLen;
    }

    // Example usage
    public static void main(String[] args) {
        int[] nums = {1, 1, 0, 1};
        System.out.println("Longest subarray of 1's after deleting one element: " + longestSubarray(nums));
    }
}
