// 数组中的第 K 个最大元素
// 快排
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int res = quickSort(nums, 0, n - 1);
        int left = 0, right = n - 1;
        while (res != k - 1) {
            if (res > k - 1) right = res - 1;
            else left = res + 1;
            res = quickSort(nums, left, right);
        }
        return nums[res];
    }
    int quickSort(vector<int>& nums, int left, int right) {
        int sentinel = left;
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] <= nums[sentinel]) --j;
            while (i < j && nums[i] >= nums[sentinel]) ++i;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[sentinel]);
        return i;
    }
};

// 堆
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > p;
        for(auto n: nums) {
            if(p.size() == k && p.top() >= n) continue;
            if(p.size() == k) p.pop();
            p.push(n);
        }
        return p.top();
    }
};