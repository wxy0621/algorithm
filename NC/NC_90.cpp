// 设计 getMin 功能的栈
class Solution {
public:
    /**
     * return a array which include all ans for op3
     * @param op int整型vector<vector<>> operator
     * @return int整型vector
     */
    vector<int> getMinStack(vector<vector<int> >& op) {
        // write code here
        vector<int> res;
        int n = op.size();
        for (int i = 0; i < n; ++i) {
            if (op[i][0] == 1) {
                if (s.empty()) min_s.push(op[i][1]);
                else min_s.push(min(min_s.top(), op[i][1]));
                s.push(op[i][1]);
            } else if (op[i][0] == 2) {
                s.pop();
                min_s.pop();
            } else {
                res.emplace_back(min_s.top());
            }
        }
        return res;
    }
private:
    stack<int> s;
    stack<int> min_s;
};