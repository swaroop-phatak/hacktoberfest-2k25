import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeMap;

class MaxProfitJobScheduling {

    class Job {
        int start, end, profit;
        Job(int start, int end, int profit) {
            this.start = start;
            this.end = end;
            this.profit = profit;
        }
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }

        Arrays.sort(jobs, Comparator.comparingInt(j -> j.end));

        TreeMap<Integer, Integer> dp = new TreeMap<>();
        dp.put(0, 0); 
        int maxProfit = 0;

        for (Job job : jobs) {
            
            Integer latestEndTimeBeforeStart = dp.floorKey(job.start);
            int profitUpToNonConflicting = dp.get(latestEndTimeBeforeStart);
            
            int currentProfit = job.profit + profitUpToNonConflicting;
            
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
            
            dp.put(job.end, maxProfit);
        }

        return maxProfit;
    }
}
