// 跳水板，弱智题
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0)
            return {};
        vector<int> res;
        if(shorter == longer) {
            res.emplace_back(k * shorter);
            return res;
        }

        int temp_length = shorter * k;
        res.emplace_back(temp_length);
        int dif = longer - shorter;
        for(int i = 0; i < k; ++i) {
            temp_length += dif;
            res.emplace_back(temp_length);
        }
        return res;
    }
};