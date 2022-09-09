// 有效三角形的个数
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i <= n - 3; ++i) {
            for (int j = i + 1; j <= n - 2; ++j) {
                int k = j;
                int left = j + 1, right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] >= nums[i] + nums[j]) {
                        right = mid - 1;
                    } else {
                        k = mid;
                        left = mid + 1;
                    }
                }
                res += (k - j);
            }
        }
        return res;
    }
};