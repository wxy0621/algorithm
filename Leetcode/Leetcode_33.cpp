// 搜索旋转排序数组
// 二分法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return nums[0] == target ? 0 : -1;
        int i = 0, j = n - 1;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            // 找到某一半递增的部分
            if(nums[i] <= nums[mid]) {
                if(nums[i] <= target && target <= nums[mid]) j = mid - 1;
                else i = mid + 1;
            } else {
                if(nums[mid] <= target && target <= nums[j]) i = mid + 1;
                else j = mid - 1;
            }
        }
        return -1;
    }
};