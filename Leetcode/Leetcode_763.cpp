// 划分字母区间
// 贪心法
// 1. 首先用一个数组保存每个字母的最后出现位置
// 2. 然后不断地求每次出现的最短的片段
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26] = {0};
        vector<int> res;
        int start = 0, end = 0;
        for(int i = 0; i < S.size(); ++i) {
            last[S[i] - 97] = i;
        }
        for(int i = 0; i < S.size(); ++i) {
            end = max(end, last[S[i] - 97]);
            if(end == i) {
                res.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};