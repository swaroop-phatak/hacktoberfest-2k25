public class MaxConsecutiveOnesIII {

    public static int longestOnes(int[] nums, int k) {
        int left = 0;
        int maxLength = 0;
        int zeroCount = 0;

        for (int right = 0; right < nums.length; right++) {
            // If current element is 0, increase zero count
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If zeros exceed k, shrink window from left
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Update max window length
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }

    // Example usage
    public static void main(String[] args) {
        int[] nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
        int k = 2;
        System.out.println("Max consecutive ones after flipping at most " + k + " zeros: " + longestOnes(nums, k));
    }
}
