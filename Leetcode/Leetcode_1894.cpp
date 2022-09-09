// 找到需要补充粉笔的学生编号
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        if (n == 0) return -1;
        long long sum = 0;
        for (int i = 0; i < n; ++i) sum += chalk[i];
        k %= sum;
        for (int i = 0; i < n; ++i) {
            k -= chalk[i];
            if (k < 0) return i;
        }
        return -1;
    }
};