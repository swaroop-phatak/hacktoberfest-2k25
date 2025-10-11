class Solution {
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public int maxVowels(String s, int k) {
        int currentCount = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s.charAt(i))) {
                currentCount++;
            }
        }

        int maxCount = currentCount;

        for (int i = k; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                currentCount++;
            }

            if (isVowel(s.charAt(i - k))) {
                currentCount--;
            }

            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        }

        return maxCount;
    }
}
