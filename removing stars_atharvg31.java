import java.util.Stack;

public class RemovingStarsFromString {
    public static String removeStars(String s) {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch == '*') {
                // Remove the most recent character
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                // Add normal character
                stack.push(ch);
            }
        }

        // Build the resulting string
        StringBuilder result = new StringBuilder();
        for (char ch : stack) {
            result.append(ch);
        }

        return result.toString();
    }

    public static void main(String[] args) {
        String s = "leet**cod*e";
        System.out.println(removeStars(s));  // Output: "lecoe"
    }
}
