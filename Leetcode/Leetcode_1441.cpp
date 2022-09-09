// 用栈操作构建数组
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int i = 0, count = 1;
        while(i < target.size()) {
            if(target[i] != count) {
                res.emplace_back("Push");
                res.emplace_back("Pop");
                --i;
            } else {
                res.emplace_back("Push");
            }
            ++count;
            ++i;
        }
        return res;
    }
};