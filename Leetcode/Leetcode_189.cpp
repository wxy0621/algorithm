// 旋转数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        mySwap(nums, 0, n - 1);
        mySwap(nums, 0, k % n - 1);
        mySwap(nums, k % n, n - 1);
    }
    void mySwap(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};