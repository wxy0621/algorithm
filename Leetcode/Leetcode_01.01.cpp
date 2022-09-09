// 判定字符是否唯一
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i <= nums.size(); ++i) {
            res += (i - nums[i - 1]);
        }
        return res;
    }
};

// 位运算
class Solution2 {
public:
    bool isUnique(string astr) {
        int x = 0;
        for(char& c: astr) {
            if(x & (1 << (c - 'a'))) return false;
            else x |= (1 << (c - 'a'));
        }
        return true;
    }
};