import java.util.*;

public class Unique_Number_of_Occurrences_Shruti03-patil {
    
    public boolean Unique_Number_of_Occurrences_Shruti03-patil(int[] arr) {
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        
       
        for (int num : arr) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        Set<Integer> seenFrequencies = new HashSet<>();

        
        for (int freq : frequencyMap.values()) {
            if (!seenFrequencies.add(freq)) {
                return false; 
            }
        }

        return true;
    }

    
    public static void main(String[] args) {
        Unique_Number_of_Occurrences_Shruti03-patil solution = new Unique_Number_of_Occurrences_Shruti03-patil();
        
        int[] arr1 = {1, 2, 2, 1, 1, 3};
        int[] arr2 = {1, 2}; 

        System.out.println(solution.Unique_Number_of_Occurrences_Shruti03-patil(arr1)); 
        System.out.println(solution.Unique_Number_of_Occurrences_Shruti03-patil(arr2)); 
    }
}
