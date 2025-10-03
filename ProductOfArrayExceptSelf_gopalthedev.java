public class ProductOfArrayExceptSelf {
    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        
        // Calculate left products
        result[0] = 1;
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        // Calculate right products and multiply with left products
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= right;
            right *= nums[i];
        }
        
        return result;
    }

    public static void main(String[] args) {
        // Test cases
        printArray(productExceptSelf(new int[]{1,2,3,4}));  // [24,12,8,6]
        printArray(productExceptSelf(new int[]{-1,1,0,-3,3})); // [0,0,9,0,0]
        printArray(productExceptSelf(new int[]{2,3,5,7}));  // [105,70,42,30]
        printArray(productExceptSelf(new int[]{1,1,1,1}));  // [1,1,1,1]
    }
    
    private static void printArray(int[] arr) {
        for (int num : arr) System.out.print(num + " ");
        System.out.println();
    }
}
