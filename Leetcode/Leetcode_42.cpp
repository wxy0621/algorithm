// 接雨水
// dp, left[i], right[i]: 表示 i 处的最大左右边界，这个量可以通过 dp 求解
// 最终遍历两遍数组，得到结果，复杂度从 O(n^2) 降到 O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        for(int i = 1; i < n; ++i) {
            left[i] = max(left[i-1], height[i-1]);
        }
        for(int i = n - 2; i >= 0; --i) {
            right[i] = max(right[i+1], height[i+1]);
        }

        for(int i = 1; i < n - 1; ++i) {
            int temp = min(left[i], right[i]);
            res += max(0, temp - height[i]);
        }
        return res;
    }
};