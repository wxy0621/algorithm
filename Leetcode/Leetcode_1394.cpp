// 找出数组中的幸运数
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int count[501] = {0};
        int res = -1;
        for(auto& num: arr) ++count[num];
        for(int i = 1; i < 501; ++i) {
            if(i == count[i]) res = max(res, i);
        }
        return res;
    }
};