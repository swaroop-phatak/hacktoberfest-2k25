public class BinarySearch {
    public static int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid; 
            } else if (arr[mid] < target) {
                left = mid + 1; // search in the right half
            } else {
                right = mid - 1; // search in the left half
            }
        }

        return -1; 
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11};
        int target = 7;
        System.out.println("Index of " + target + ": " + binarySearch(arr, target));
    }
}
