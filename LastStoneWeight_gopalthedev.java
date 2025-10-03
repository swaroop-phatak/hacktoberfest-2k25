import java.util.*;

public class LastStoneWeight {
    public static int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int stone : stones) maxHeap.offer(stone);
        
        while (maxHeap.size() > 1) {
            int y = maxHeap.poll();
            int x = maxHeap.poll();
            if (x != y) maxHeap.offer(y - x);
        }
        
        return maxHeap.isEmpty() ? 0 : maxHeap.poll();
    }

    public static void main(String[] args) {
        // Test cases
        System.out.println(lastStoneWeight(new int[]{2,7,4,1,8,1})); // 1
        System.out.println(lastStoneWeight(new int[]{1}));             // 1
        System.out.println(lastStoneWeight(new int[]{1,1}));           // 0
        System.out.println(lastStoneWeight(new int[]{10,10,10,10}));   // 0
        System.out.println(lastStoneWeight(new int[]{3,7,2}));         // 2
    }
}
