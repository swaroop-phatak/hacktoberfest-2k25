public class CountingBits {

    public static int[] countBits(int n) {
        int[] ans = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            // The number of 1s in i is the number of 1s in i/2 + (i % 2)
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }

    public static void main(String[] args) {
        int n = 5;
        int[] result = countBits(n);

        System.out.print("[ ");
        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println("]");
        // Output: [ 0 1 1 2 1 2 ]
    }
}
