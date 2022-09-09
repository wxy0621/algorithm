// 检查是否区域内所有整数都被覆盖
class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] < v2[0];
    }
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), cmp);
        for (int i = left; i <= right; ++i) {
            bool isFind = false;
            for (auto& range: ranges) {
                if (range[0] <= i && i <= range[1]) {
                    isFind = true;
                    break;
                }
            }
            if (!isFind) return false;
        }
        return true;
    }
};