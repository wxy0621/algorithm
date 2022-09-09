// 移动零
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> res;
        int zeros_number = 0;
        for(int num: nums) {
            if(num == 0) ++zeros_number;
            if(num != 0) res.push_back(num);
        }
        while(zeros_number--) {
            res.push_back(0);
        }
        for(int i = 0; i < nums.size(); ++i) {
            nums[i] = res[i];
        }
    }
};