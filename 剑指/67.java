// 把字符串转换成整数
// 细节太多
class Solution {
    public int strToInt(String str) {
        long res = 0;
        int n = str.length();
        if (n == 0) return 0;
        int i = 0;
        boolean isPositive = true;
        while (i < n && str.charAt(i) == ' ') ++i;
        if (i == n) return 0;
        if (str.charAt(i) == '-') {
            isPositive = false;
            ++i;
        } else if (str.charAt(i) == '+') {
            ++i;
        } else if ('0' > str.charAt(i) || str.charAt(i) > '9') {
            return 0;
        }
        while (i < n && '0' <= str.charAt(i) && str.charAt(i) <= '9') {
            if (res > Integer.MAX_VALUE) break;
            res = res * 10 + str.charAt(i) - '0';
            ++i;
        }
        if (isPositive) {
            if (res > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            } else return (int)res;
        } else {
            if (-1 * res < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            } else return -1 * (int)res;
        }
    }
}