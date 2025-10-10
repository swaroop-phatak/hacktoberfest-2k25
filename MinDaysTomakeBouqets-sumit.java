import java.util.*;

public class MinDaysToMakeBouquets {
    public int minDays(int[] bloomDay, int m, int k) {
        if ((long) m * k > bloomDay.length) return -1;

        int left = 1, right = Arrays.stream(bloomDay).max().getAsInt(), ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return ans;
    }

    private boolean canMake(int[] bloomDay, int m, int k, int day) {
        int flowers = 0, bouquets = 0;
        for (int d : bloomDay) {
            if (d <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else flowers = 0;
        }
        return bouquets >= m;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of flowers:");
        int n = sc.nextInt();
        int[] bloomDay = new int[n];
        System.out.println("Enter bloom days:");
        for (int i = 0; i < n; i++) bloomDay[i] = sc.nextInt();
        System.out.println("Enter m and k:");
        int m = sc.nextInt(), k = sc.nextInt();
        MinDaysToMakeBouquets obj = new MinDaysToMakeBouquets();
        System.out.println("Minimum days to make bouquets: " + obj.minDays(bloomDay, m, k));
    }
}
