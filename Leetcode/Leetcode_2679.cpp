// 矩阵中的和
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        int m = nums.size();
        if (m == 0) return 0;
        int n = nums[0].size();
        if (n == 0) return 0;
        for (int i = 0; i < m; ++i) {
            sort(nums[i].begin(), nums[i].end());
        }
        for (int j = 0; j < n; ++j) {
            int maxNum = nums[0][j];
            for (int i = 1; i < m; ++i) {
                maxNum = max(maxNum, nums[i][j]);
            }
            res += maxNum;
        }
        return res;
    }
};