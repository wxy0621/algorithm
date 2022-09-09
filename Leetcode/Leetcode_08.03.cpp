// 魔术索引
// 弱智题
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] == i) return i;
        return -1;
    }
};