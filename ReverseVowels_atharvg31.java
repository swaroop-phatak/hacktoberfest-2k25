public class ReverseVowels {

    public static String reverseVowels(String s) {
        if (s == null || s.length() == 0) return s;

        char[] chars = s.toCharArray();
        int left = 0, right = chars.length - 1;

        while (left < right) {
            // Move left pointer until a vowel is found
            while (left < right && !isVowel(chars[left])) {
                left++;
            }

            // Move right pointer until a vowel is found
            while (left < right && !isVowel(chars[right])) {
                right--;
            }

            // Swap vowels
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;

            left++;
            right--;
        }

        return new String(chars);
    }

    // Helper method to check if a character is a vowel
    private static boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) != -1;
    }

    // Example usage
    public static void main(String[] args) {
        String input = "hello";
        String output = reverseVowels(input);
        System.out.println("Input: " + input);
        System.out.println("Output: " + output);
    }
}
