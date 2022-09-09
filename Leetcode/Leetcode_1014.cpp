// 最佳观光组合
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0;
        int n = A.size();
        int mx = A[0] + 0;
        for(int i = 1; i < n; ++i) {
            res = max(res, mx + A[i] - i);
            mx = max(mx, A[i] + i);
        }
        return res;
    }
};