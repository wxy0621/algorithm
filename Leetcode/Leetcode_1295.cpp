// 统计位数为偶数的数字
// string
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto& num: nums) {
            string s = to_string(num);
            if(s.size() % 2 == 0) ++res;
        }
        return res;
    }
};

// log
class Solution2 {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto& num: nums) {
            if((int)(log10(num) + 1) % 2 == 0) ++res;
        }
        return res;
    }
};