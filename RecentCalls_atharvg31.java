RecentCounter()```  
Initializes the counter with zero recent requests.

```java
int ping(int t)```  
Adds a new request at time `t` (in milliseconds), and returns the number of requests that have happened in the past 3000 milliseconds (including the current request).  

Specifically, return the count of calls that have happened in the inclusive range `[t - 3000, t]`.

---

### ✅ **Java Implementation**
```java
import java.util.*;

class RecentCounter {
    private Queue<Integer> queue;

    public RecentCounter() {
        queue = new LinkedList<>();
    }

    public int ping(int t) {
        // Add current request time
        queue.add(t);

        // Remove all requests older than (t - 3000)
        while (!queue.isEmpty() && queue.peek() < t - 3000) {
            queue.poll();
        }

        // The remaining requests are within the 3000ms window
        return queue.size();
    }

    public static void main(String[] args) {
        RecentCounter counter = new RecentCounter();

        System.out.println(counter.ping(1));     // Output: 1
        System.out.println(counter.ping(100));   // Output: 2
        System.out.println(counter.ping(3001));  // Output: 3
        System.out.println(counter.ping(3002));  // Output: 3
    }
}
