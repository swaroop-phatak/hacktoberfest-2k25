public class Solution {
    public int pivotIndex(int[] nums) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        int leftSum = 0;
        for (int i = 0; i < nums.length; i++) {
            if (leftSum == totalSum - leftSum - nums[i])
                return i;
            leftSum += nums[i];
        }

        return -1;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = {1, 7, 3, 6, 5, 6};
        int[] nums2 = {1, 2, 3};

        System.out.println(sol.pivotIndex(nums1)); // Output: 3
        System.out.println(sol.pivotIndex(nums2)); // Output: -1
    }
}
