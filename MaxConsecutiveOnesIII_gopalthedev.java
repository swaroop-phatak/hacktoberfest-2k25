public class MaxConsecutiveOnesIII {
    public static int longestOnes(int[] nums, int k) {
        int left = 0, right = 0, zeros = 0, maxLen = 0;
        
        while (right < nums.length) {
            if (nums[right] == 0) zeros++;
            
            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            
            maxLen = Math.max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }

    public static void main(String[] args) {
        // Test cases
        System.out.println(longestOnes(new int[]{1,1,1,0,0,0,1,1,1,1,0}, 2)); // 6
        System.out.println(longestOnes(new int[]{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3)); // 10
        System.out.println(longestOnes(new int[]{1,1,1,0,0,0,1,1,1,1}, 0)); // 4
        System.out.println(longestOnes(new int[]{0,0,0,0}, 2)); // 2
        System.out.println(longestOnes(new int[]{1,1,1,1}, 2)); // 4
    }
}
