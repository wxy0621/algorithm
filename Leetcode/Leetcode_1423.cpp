// 可获得的最大点数
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if (n < k) return -1;
        int res = 0;
        for (int i = 0; i < k; ++i) res += cardPoints[i];
        int temp = res;
        for (int i = 0; i < k; ++i) {
            temp = temp - cardPoints[k-1-i] + cardPoints[n-1-i];
            res = max(res, temp);
        }
        return res;
    }
};