public class MaxVowelsInSubstring {

    public static int maxVowels(String s, int k) {
        int maxCount = 0;
        int currentCount = 0;

        // Helper method can check vowel directly
        for (int i = 0; i < s.length(); i++) {
            // Add rightmost character
            if (isVowel(s.charAt(i))) {
                currentCount++;
            }

            // If window exceeds size k, remove leftmost character
            if (i >= k && isVowel(s.charAt(i - k))) {
                currentCount--;
            }

            // Update maximum
            maxCount = Math.max(maxCount, currentCount);

            // Early stop: can't get better than k
            if (maxCount == k) return k;
        }

        return maxCount;
    }

    // Helper function to check vowels
    private static boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) != -1;
    }

    // Example usage
    public static void main(String[] args) {
        String s = "abciiidef";
        int k = 3;
        System.out.println("Maximum number of vowels in a substring of length " + k + " is: " + maxVowels(s, k));
    }
}
