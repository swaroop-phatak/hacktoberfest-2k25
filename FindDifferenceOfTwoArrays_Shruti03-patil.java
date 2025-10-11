import java.util.*;

public class ArrayDifference {
    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4, 5};
        int[] arr2 = {3, 4, 6};

        Set<Integer> set2 = new HashSet<>();
        for (int num : arr2) {
            set2.add(num);
        }
        List<Integer> difference = new ArrayList<>();
        for (int num : arr1) {
            if (!set2.contains(num)) {
                difference.add(num);
            }
        }
        System.out.println("Difference (arr1-arr2): " + difference);
    }
}
