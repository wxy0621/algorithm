// 生存人数
// 差分
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> change(102, 0);
        int n = birth.size();
        if (n == 0) return 0;
        for (int i = 0; i < n; ++i) {
            ++change[birth[i] - 1900];
            --change[death[i] - 1899];
        }
        int res = 1900;
        int curAlive = change[0];
        int maxAlive = change[0];
        for (int i = 1901; i <= 2000; ++i) {
            curAlive += change[i - 1900];
            if (curAlive > maxAlive) {
                res = i;
                maxAlive = curAlive;
            }
        }
        return res;
    }
};