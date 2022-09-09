// 总持续时间可被 60 整除的歌曲
// 数学
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        unordered_map<int, int> m;
        for(auto& t: time) ++m[t % 60];
        count += (m[0] * (m[0] - 1)) / 2;
        count += (m[30] * (m[30] - 1)) / 2;
        int i = 1, j = 59;
        while(i < j) {
            count += m[i++] * m[j--];
        }
        return count;
    }
};