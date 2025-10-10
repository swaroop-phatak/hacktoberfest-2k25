class MoveZeroes {
    public void moveZeroes(int[] nums) {
        int nonZeroPtr = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (i != nonZeroPtr) {
                    int temp = nums[nonZeroPtr];
                    nums[nonZeroPtr] = nums[i];
                    nums[i] = temp;
                }
                nonZeroPtr++;
            }
        }
    }
}
