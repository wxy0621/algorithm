// 删除某些元素后的数组均值
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int total = accumulate(arr.begin() + n / 20, arr.begin() + (19 * n / 20), 0);
        return total / (n * 0.9);
    }
};