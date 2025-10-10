public class MergeStrings {
    public static String mergeAlternately(String word1, String word2) {
        StringBuilder result = new StringBuilder();
        int i = 0, j = 0;

        // Add characters alternately
        while (i < word1.length() && j < word2.length()) {
            result.append(word1.charAt(i++));
            result.append(word2.charAt(j++));
        }

        // Add remaining characters (if any)
        if (i < word1.length()) result.append(word1.substring(i));
        if (j < word2.length()) result.append(word2.substring(j));

        return result.toString();
    }

    public static void main(String[] args) {
        String word1 = "abc";
        String word2 = "pqr";
        System.out.println("Merged String: " + mergeAlternately(word1, word2));
    }
}
