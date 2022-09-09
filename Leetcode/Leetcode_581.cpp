// 最短无序连续子数组
// 排序
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> numsSort(nums);
        sort(numsSort.begin(), numsSort.end());
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right && numsSort[left] == nums[left]) ++left;
        while (left <= right && numsSort[right] == nums[right]) --right;
        return right - left + 1;
    }
};

// 一次遍历
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        int minn = INT_MAX, maxn = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (minn >= nums[n-1-i]) {
                minn = nums[n-1-i];
            } else {
                left = n - 1 - i;
            }
            if (maxn <= nums[i]) {
                maxn = nums[i];
            } else {
                right = i;
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};