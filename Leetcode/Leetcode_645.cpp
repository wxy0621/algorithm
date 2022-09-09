// 错误的集合
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 1);
        vector<int> res(2);
        for (auto& num: nums) --temp[num-1];
        for (int i = 0; i < n; ++i) {
            if (temp[i] == -1) res[0] = i + 1;
            if (temp[i] == 1) res[1] = i + 1;
        }
        return res;
    }
};