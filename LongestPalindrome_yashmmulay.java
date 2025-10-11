public class LongestPalindromicSubstring {

    public static String longestPalindrome(String s) {
        if (s == null || s.length() < 2) return s;

        int start = 0, end = 0;

        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindrome (center at i)
            int len1 = expandFromCenter(s, i, i);
            // Even-length palindrome (center between i and i+1)
            int len2 = expandFromCenter(s, i, i + 1);
            int len = Math.max(len1, len2);

            // Update start and end if a longer palindrome is found
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substring(start, end + 1);
    }

    // Helper function to expand around the center
    private static int expandFromCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1; // Length of the palindrome
    }

    // Example usage
    public static void main(String[] args) {
        String s1 = "babad";
        String s2 = "cbbd";
        System.out.println(longestPalindrome(s1)); // Output: "bab" or "aba"
        System.out.println(longestPalindrome(s2)); // Output: "bb"
    }
}
