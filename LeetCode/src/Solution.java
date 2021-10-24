import java.util.HashMap;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        boolean[] keyMap = new boolean[128];
        for (int i = 0; i < 128; i++) {
            keyMap[i] = false;
        }
        int length = 0;
        int maxLength = 0;
        int end = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            keyMap[(int)s.charAt(i)] = true;
            length = 1;
            for (; end < s.length(); end++) {
                end = Math.max(i + 1, end);
                if (keyMap[(int) s.charAt(end)]) {
                    maxLength = Math.max(length, maxLength);
                    break;
                } else {
                    length++;
                    keyMap[(int)s.charAt(end)] = true;
                }
            }
            keyMap[(int)s.charAt(i)] = false;
            length--;
        }
        maxLength = Math.max(length, maxLength);
        return maxLength;
    }
}