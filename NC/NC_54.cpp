// 数组中相加和为0的三元组
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = num.size();
        if (n < 3) return {};
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        for (int i = 0 ; i < n - 2; ++i) {
            int first = num[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if ((num[left] + num[right] + first) == 0) {
                    res.emplace_back(vector<int>{first, num[left], num[right]});
                    while (left < right && num[left] == res.back()[1]) ++left;
                    while (left < right && num[right] == res.back()[2]) --right;
                }
                else if ((num[left] + num[right] + first) < 0) ++left;
                else --right;
            }
            while (i < (n - 1) && num[i] == num[i+1]) ++i;
        }
        return res;
    }
};