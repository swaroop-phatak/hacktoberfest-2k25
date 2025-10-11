public class Solution {
    public int compress(char[] chars) {
        int index = 0; // position to write in chars[]
        int i = 0;     // read pointer

        while (i < chars.length) {
            char currentChar = chars[i];
            int count = 0;

            // Count how many times the current character repeats
            while (i < chars.length && chars[i] == currentChar) {
                i++;
                count++;
            }

            // Write the character
            chars[index++] = currentChar;

            // Write the count (if > 1)
            if (count > 1) {
                for (char c : String.valueOf(count).toCharArray()) {
                    chars[index++] = c;
                }
            }
        }
        return index; // New compressed length
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        char[] chars = {'a','a','b','b','c','c','c'};
        int len = sol.compress(chars);

        System.out.print("Compressed: ");
        for (int i = 0; i < len; i++) System.out.print(chars[i]);
        System.out.println("\nLength: " + len);
    }
}
