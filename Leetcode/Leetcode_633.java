// 平方数之和
class Solution {
    public boolean judgeSquareSum(int c) {
        int left = 0, right = (int)Math.sqrt(c);
        while (left <= right) {
            if (left * left + right * right == c) return true;
            else if (left * left + right * right < c) ++left;
            else --right;
        }
        return false;
    }
}