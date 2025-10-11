public class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0; // pointer for s
        int j = 0; // pointer for t

        // Traverse both strings
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++; // move to next char in s if match found
            }
            j++; // always move in t
        }

        // if we reached the end of s, all chars matched
        return i == s.length();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.isSubsequence("abc", "ahbgdc")); // true
        System.out.println(sol.isSubsequence("axc", "ahbgdc")); // false
    }
}
