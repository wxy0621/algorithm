// 回旋镖的数量
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (auto& p: points) {
            unordered_map<int, int> count;
            for (auto& q: points) {
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                ++count[dis];
            }
            for (auto& t: count) {
                res += (t.second - 1) * t.second;
            }
        }
        return res;
    }
};