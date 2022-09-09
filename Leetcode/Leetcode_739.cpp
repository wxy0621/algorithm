// 每日温度
// 辅助栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = 0; i < n; ++i) {
            while(!s.empty() && T[i] > T[s.top()]) {
                int temp = s.top();
                res[temp] = i - temp;
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};