// 解码异或后的数组
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> res(n + 1);
        res[0] = first;
        for (int i = 1; i <= n; ++i) {
            res[i] = encoded[i-1] ^ res[i-1];
        }
        return res;
    }
};