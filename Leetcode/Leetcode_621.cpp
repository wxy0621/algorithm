// 任务调度器
// 公式推导，返回语句精髓
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        int res;
        int len = tasks.size();
        for (auto& c: tasks) ++v[c-'A'];
        sort(v.rbegin(), v.rend());
        int count = 1;
        while (count < 26 && v[count] == v[0]) ++count;
        return len > (v[0] - 1) * (n + 1) + count ? len : (v[0] - 1) * (n + 1) + count;
    }
};