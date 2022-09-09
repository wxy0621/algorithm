// 反转字符串中的单词 III
class Solution {
    public String reverseWords(String s) {
        StringBuffer res = new StringBuffer();;
        int i = 0;
        int n = s.length();
        while (i < n) {
            int start = i;
            while (i < n && s.charAt(i) != ' ') {
                ++i;
            }
            for (int j = i - 1; j >= start; --j) {
                res.append(s.charAt(j));
            }
            while (i < n && s.charAt(i) == ' ') {
                res.append(' ');
                ++i;
            }
        }
        return res.toString();
    }
}