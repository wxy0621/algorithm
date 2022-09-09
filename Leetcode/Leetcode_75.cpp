// 颜色分类
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int b = nums.size() - 1;
        int r = 0, w = 0;
        while(w <= b) {
            if(nums[w] == 0) swap(nums[r++], nums[w++]);
            else if(nums[w] == 1) ++w;
            else swap(nums[w], nums[b--]);
        }
    }
};