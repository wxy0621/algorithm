// 摆动排序 II
// 排序 + 重新插入，但不是最优解
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        bool isOdd = (n % 2 == 1);
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < n / 2; ++i) {
            if (isOdd) nums[i * 2] = nums2[n / 2 - i];
            else nums[i * 2] = nums2[n / 2 - 1 - i];
            nums[i * 2 + 1] = nums2[n - 1 - i];
        }
        if (isOdd) nums[n - 1] = nums2[0];
    }
};