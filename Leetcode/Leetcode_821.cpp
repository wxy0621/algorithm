// 字符的最短距离
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n, 0);
        int pre = INT_MIN / 2;
        for(int i = 0; i < n; ++i) {
            if(S[i] == C) pre = i;
            res[i] = i - pre;
        }
        pre = INT_MAX / 2;
        for(int i = n - 1; i >= 0; --i) {
            if(S[i] == C) pre = i;
            res[i] = min(pre - i, res[i]);
        }
        return res;
    }
};