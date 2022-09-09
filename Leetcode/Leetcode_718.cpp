// 最长重复子数组
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector< vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for(int i = m - 1; i >= 0 ; --i) {
            for(int j = n - 1; j >= 0; --j) {
                dp[i][j] = A[i] == B[j] ? (dp[i+1][j+1]+1) : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};