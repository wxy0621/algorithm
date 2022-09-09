// 数组中重复的数据
// 原地修改
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(auto& num: nums) {
            if((nums[abs(num) - 1]) < 0)
                res.emplace_back(abs(num));
            nums[abs(num) - 1] *= -1;
        }
        return res;
    }
};