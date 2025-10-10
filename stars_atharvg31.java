public class RemovingStarsFromString {
    public static String removeStars(String s) {
        StringBuilder sb = new StringBuilder();

        for (char ch : s.toCharArray()) {
            if (ch == '*') {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.append(ch);
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        String s = "erase*****";
        System.out.println(removeStars(s));  // Output: ""
    }
}
