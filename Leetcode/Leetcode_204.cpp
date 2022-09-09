// 计数质数
class Solution {
public:
    int countPrimes(int n) {
        vector<int> nums(n, 1);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (nums[i] == 1) {
                ++res;
                int j = i;
                while ((long)i * j < n) {
                    nums[i * j] = 0;
                    ++j;
                }
            }
        }
        return res;
    }
};