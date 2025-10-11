public class Move_Zeroes_Shruti03-patil {
    
    public void Move_Zeroes_Shruti03-patil(int[] nums) {
        int lastNonZeroIndex = 0;

        // First pass: move non-zero elements forward
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroIndex] = nums[i];
                lastNonZeroIndex++;
            }
        }

        // Second pass: fill the remaining elements with zero
        for (int i = lastNonZeroIndex; i < nums.length; i++) {
            nums[i] = 0;
        }
    }

    // Example usage
    public static void main(String[] args) {
        Move_Zeroes_Shruti03-patil solution = new Move_Zeroes_Shruti03-patil();

        int[] nums = {0, 1, 0, 3, 12};
        solution.Move_Zeroes_Shruti03-patil(nums);

        // Output the result
        for (int num : nums) {
            System.out.print(num + " ");
        }
        // Output: 1 3 12 0 0
    }
}