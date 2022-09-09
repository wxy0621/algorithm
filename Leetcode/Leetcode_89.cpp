// 格雷编码
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.emplace_back(0);
        for(int i = 0; i < n; ++i) {
            vector<int> temp = res;
            reverse(temp.begin(), temp.end());
            for(auto& t: temp) {
                t += (1 << i);
                res.emplace_back(t);
            }
        }
        return res;
    }
};