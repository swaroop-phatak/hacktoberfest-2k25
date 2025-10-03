import java.util.*;

public class FindDifferenceTwoArrays_Concise {
    
    public static List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        
        for (int num : nums1) set1.add(num);
        for (int num : nums2) set2.add(num);
        
        List<Integer> diff1 = new ArrayList<>();
        List<Integer> diff2 = new ArrayList<>();
        
        for (int num : set1) if (!set2.contains(num)) diff1.add(num);
        for (int num : set2) if (!set1.contains(num)) diff2.add(num);
        
        return Arrays.asList(diff1, diff2);
    }
    
    public static void main(String[] args) {
        // Quick test
        System.out.println(findDifference(new int[]{1,2,3}, new int[]{2,4,6}));
        // Output: [[1, 3], [4, 6]]
        
        System.out.println(findDifference(new int[]{1,2,3,3}, new int[]{1,1,2,2}));
        // Output: [[3], []]
    }
}
