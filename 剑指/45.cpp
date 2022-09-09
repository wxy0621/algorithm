// 把数组排成最小的数
// 排序规则：若 x + y > y + x, 则 x 大于 y
class Solution {
public:
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        string res;
        vector<string> s(n);
        for(int i = 0; i < n; ++i) s[i] = to_string(nums[i]);
        fastsort(s, 0, n - 1);
        for(int i = 0; i < n; ++i) res += s[i];
        return res;
    }

    void fastsort(vector<string>& s, int left, int right) {
        if(left >= right) return;
        int i = left, j = right, l = left;
        while(i < j) {
            while(i < j && s[l] + s[j] <= s[j] + s[l]) --j;
            while(i < j && s[l] + s[i] >= s[i] + s[l]) ++i;
            swap(s[i], s[j]);
        }
        swap(s[i], s[l]);
        fastsort(s, left, i - 1);
        fastsort(s, i + 1, right);
    }
};