import java.util.*;

public class Dota2Senate {
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        Queue<Integer> radiant = new ArrayDeque<>();
        Queue<Integer> dire = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            if (senate.charAt(i) == 'R') radiant.add(i);
            else dire.add(i);
        }

        while (!radiant.isEmpty() && !dire.isEmpty()) {
            int r = radiant.poll();
            int d = dire.poll();
            if (r < d) radiant.add(r + n);
            else dire.add(d + n);
        }

        return radiant.isEmpty() ? "Dire" : "Radiant";
    }

    public static void main(String[] args) {
        Dota2Senate solver = new Dota2Senate();
        System.out.println(solver.predictPartyVictory("RD"));    
        System.out.println(solver.predictPartyVictory("RDD"));   
        System.out.println(solver.predictPartyVictory("RDRDR"));  
    }
}
