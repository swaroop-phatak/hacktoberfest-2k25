class Solution {
    public String removeStars(String s) {
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (c == '*') {
                // Remove the last character when a '*' is found
                sb.deleteCharAt(sb.length() - 1);
            } else {
                // Append normal characters
                sb.append(c);
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String input = "leet**cod*e";
        System.out.println(sol.removeStars(input));  // Output: "lecoe"
    }
}
