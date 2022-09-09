// 计数质数
class Solution {
    public int countPrimes(int n) {
        int[] nums = new int[n];
        Arrays.fill(nums, 1);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (nums[i] == 1) {
                ++res;
                int j = i;
                while ((long)j * i < n) {
                    nums[j * i] = 0;
                    ++j;
                }
            }
        }
        return res;
    }
}