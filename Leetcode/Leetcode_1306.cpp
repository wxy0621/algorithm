// 跳跃游戏 III
// dfs
class Solution {
public:
    bool dfs(vector<int>& arr, int cur) {
        if (cur > arr.size() - 1 || cur < 0 || arr[cur] == -1) {
            return false;
        }
        int step = arr[cur];
        if (step == 0) return true;
        arr[cur] = -1;
        return dfs(arr, cur + step) || dfs(arr, cur - step);
    }
    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);
    }
};