// 翻转字符串里的单词
class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> stack;
        string res;
        int n = s.size();
        int i = 0;
        // 下面两行的目的是为了排除字符串全空格的情况
        while(s[i] == ' ' && i < n) ++i;
        if(i == n) return "";
        // 主要步骤
        while(i < n) {
            while(s[i] == ' ' && i < n) ++i;
            if(i == n) break;
            int j = i;
            while(s[i] != ' ' && i < n) ++i;
            string temp = s.substr(j, i - j);
            stack.push(temp);
        }
        // 这样会多一个' '，最后需要排除
        while(!stack.empty()) {
            res += stack.top();
            res += ' ';
            stack.pop();
        }
        res.pop_back();
        return res;
    }
};