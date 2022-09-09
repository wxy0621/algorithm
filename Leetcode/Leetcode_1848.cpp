// 到目标元素的最小距离
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left = start, right = start;
        int n = nums.size();
        while (left >= 0 && nums[left] != target) --left;
        while (right < n && nums[right] != target) ++right;
        if (right == n) return start - left;
	    else if (left == -1) return right - start;
	    else return min(right - start, start - left);
    }
};