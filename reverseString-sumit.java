public class ReverseWordsInString {

    public static String reverseWords(String s) {
        s = s.trim();
        String[] a = s.split("\\s+");
        StringBuilder sb = new StringBuilder();

        for (int i=a.length-1;i>=0;i--) {
            sb.append(a[i]);
            if (i!= 0){
              sb.append(" ");
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        String s = " the sky is blue ";
        System.out.println(reverseWords(s));
    }
}
