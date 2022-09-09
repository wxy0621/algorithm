// 括号的最大嵌套深度
class Solution {
public:
    int maxDepth(string s) {
        int res = 0, temp_max = 0;
        for(auto& c: s) {
            if(c == '(') {
                ++temp_max;
                res = max(temp_max, res);
            }
            else if(c == ')') --temp_max;
        }
        return res;
    }
};