// 搜索插入位置
// 暴力法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] >= target) {
                return i; 
            }
        }
        return n;
    }
};

// 二分法
class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        if(target > nums[j]) return n;
        while(i < j) {
            int mid = (i + j) >> 1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid;
            else i = mid + 1;
        }
        return i;
    }
};

// 二分法2
class Solution3 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i <= j) {
            int mid = (i + j) >> 1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return i;
    }
};

// 二分法3
class Solution4 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left == n) return n;
        if (right == -1) return 0;
        return left;
    }
};