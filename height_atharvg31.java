public class HighestAltitude {

    public static int largestAltitude(int[] gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;

        for (int g : gain) {
            currentAltitude += g;         // update altitude
            maxAltitude = Math.max(maxAltitude, currentAltitude);  // track max
        }

        return maxAltitude;
    }

    // Example usage
    public static void main(String[] args) {
        int[] gain = {-5, 1, 5, 0, -7};
        System.out.println("Highest Altitude: " + largestAltitude(gain));
    }
}
