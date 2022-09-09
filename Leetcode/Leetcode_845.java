// 数组中的最长山脉
class Solution {
    public int longestMountain(int[] arr) {
        int n = arr.length;
        int res = 0;
        int i = 0;
        while (i < n - 1) {
            int inc = 0, dec = 0;
            while (i < n - 1 && arr[i] < arr[i+1]) {
                ++inc;
                ++i;
            }
            while (i < n - 1 && arr[i] > arr[i+1]) {
                ++dec;
                ++i;
            }
            if (inc > 0 && dec > 0) {
                res = Math.max(res, inc + dec + 1);
            }
            while (i < n - 1 && arr[i] == arr[i+1]) {
                ++i;
            }
        }
        return res;
    }
}