// 机器人的运动范围
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector< vector<bool> > visited(m, vector<bool>(n, false));
        int res = 0;
        dfs(visited, res, 0, 0, m, n, k);
        return res;
    }
    void dfs(vector< vector<bool> >& visited, int& res, int i, int j, int& m, int& n, int& k) {
        int temp = countNum(i) + countNum(j);
        if (temp <= k && !visited[i][j]) {  // 减枝
            ++res;
            visited[i][j] = true;
        } else return;
        if (i + 1 < m) dfs(visited, res, i + 1, j, m, n, k);
        if (j + 1 < n) dfs(visited, res, i, j + 1, m, n, k);
    }
    int countNum(int num) {
        int temp = 0;
        while (num) {
            temp += num % 10;
            num /= 10;
        }
        return temp;
    }
};