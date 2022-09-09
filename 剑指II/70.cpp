// 排序数组中只出现一次的数字
// 暴力
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (auto& num: nums) res ^= num;
        return res;
    }
};

// 二分
class Solution2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0) right = mid - 2;
                else left = mid + 1;
            } else if (mid < n - 1 && nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0) left = mid + 2;
                else right = mid - 1;
            } else {
                return nums[mid];
            }
        }
        return nums[left];
    }
};