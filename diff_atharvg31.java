import java.util.*;

public class DifferenceOfTwoArrays {
    public static List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        // Convert both arrays to sets to remove duplicates
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        
        for (int num : nums1) set1.add(num);
        for (int num : nums2) set2.add(num);
        
        // Create copies to find differences
        Set<Integer> onlyInNums1 = new HashSet<>(set1);
        Set<Integer> onlyInNums2 = new HashSet<>(set2);
        
        // Remove common elements
        onlyInNums1.removeAll(set2);
        onlyInNums2.removeAll(set1);
        
        // Prepare the result as list of lists
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<>(onlyInNums1));
        result.add(new ArrayList<>(onlyInNums2));
        
        return result;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3};
        int[] nums2 = {2, 4, 6};
        
        List<List<Integer>> ans = findDifference(nums1, nums2);
        System.out.println(ans);
        // Output: [[1, 3], [4, 6]]
    }
}
