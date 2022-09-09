// 矩阵中战斗力最弱的 K 行
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        if (m == 0) return {};
        int n = mat[0].size();
        if (n == 0) return {};
        priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int>>> pq;
        vector<int> res;
        vector< pair<int, int> > p;
        for (int i = 0; i < m; ++i) {
            int left = 0, right = n - 1;
            int pos = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (mat[i][mid] == 1) {
                    left = mid + 1;
                    pos = mid;
                } else {
                    right = mid - 1;
                }
            }
            pq.push(pair<int, int>(pos+1, i));
        }
        for (int i = 0; i < k; ++i) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};