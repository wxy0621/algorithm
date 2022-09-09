// 最大数
class Solution {
public:
    static bool cmp(const int& v1, const int& v2) {
        long l1 = 10, l2 = 10;
        while (l1 <= v1) l1 *= 10;
        while (l2 <= v2) l2 *= 10;
        return l2 * v1 + v2 > l1 * v2 + v1;
    }
    string largestNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) return "0";
        for (int& num: nums) {
            res += to_string(num);
        }
        return res;
    }
};