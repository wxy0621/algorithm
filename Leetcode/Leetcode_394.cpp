// 字符串解码
// 丑陋的代码
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int frequent = 0;
        stack< pair<string, int> > stk;
        for (auto& c: s) {
            if ('0' <= c && c <= '9') {
                frequent = frequent * 10 + c - '0';
            } else if (c == '[') {
                pair<string, int> temp(res, frequent);
                stk.push(temp);
                res = "";
                frequent = 0;
            } else if (c == ']') {
                pair<string, int> temp = stk.top();
                stk.pop();
                string lastRes = temp.first;
                int tempFreq = temp.second;
                string tempStr = res;
                res = lastRes;
                for (int i = 0; i < tempFreq; ++i) res += tempStr;
            } else {
                res += c;
            }
        }
        return res;
    }
};