// 等差数列划分
// o(n)，差分
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        int difNum = nums[1] - nums[0];
        int temp = 0;
        for (int i = 2; i < n; ++i) {
            if (difNum == nums[i] - nums[i-1]) {
                ++temp;
            } else {
                difNum = nums[i] - nums[i-1];
                temp = 0;
            }
            res += temp;
        }
        return res;
    }
};
// o(n^2)，暴力
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        int difNum;
        for (int i = 1; i < n - 1; ++i) {
            difNum = nums[i] - nums[i-1];
            for (int j = i + 1; j < n; ++j) {
                int temp = nums[j] - nums[j-1];
                if (difNum == temp) {
                    ++res;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
