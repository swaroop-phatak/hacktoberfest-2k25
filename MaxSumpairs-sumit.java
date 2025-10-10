import java.util.*;

public class MaxKSumPairs {
    public static int maxOperations(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        int count = 0;

        for (int num : nums) {
            int complement = k-num;
            if (map.getOrDefault(complement, 0) > 0) {
                count++;
                map.put(complement, map.get(complement)-1);
            } else {
                map.put(num,map.getOrDefault(num, 0)+1);
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter array size: ");
        int n = sc.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        System.out.println("Enter value of k:");
        int k = sc.nextInt();

        int result = maxOperations(nums, k);
        System.out.println("Maximum number of K-sum pairs: " + result);
    }
}
