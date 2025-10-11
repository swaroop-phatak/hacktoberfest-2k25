public class MoveZeroes {
    public static void moveZeroes(int[] nums) {
        int lastNonZero = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                int tmp = nums[lastNonZero];
                nums[lastNonZero] = nums[i];
                nums[i] = tmp;
                lastNonZero++;
            }
        }
    }

    public static void main(String[] args) {
        int[] nums = {0, 1, 0, 3, 12};
        moveZeroes(nums);
        for (int n : nums) {
            System.out.print(n + " ");
        }
    }
}
