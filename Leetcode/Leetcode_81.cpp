// 搜索旋转排序数组 II
// 二分法
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return false;
        if(n == 1) return nums[0] == target;
        int i = 0, j = n - 1;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(nums[mid] == target) return true;
            // 会出现重复数字，所以多了一个判断条件
            if(nums[i] == nums[mid]) {
                ++i;
                continue;
            }
            if(nums[i] < nums[mid]) {
                if(nums[i] <= target && target < nums[mid]) j = mid - 1;
                else i = mid + 1;
            } else {
                if(nums[mid] < target && target <= nums[j]) i = mid + 1;
                else j = mid - 1;
            }
        }
        return false;
    }
};