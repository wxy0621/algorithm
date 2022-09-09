// 删除字符串中的所有相邻重复项
class Solution {
public:
    string removeDuplicates(string S) {
        int n = S.size();
        int i = 0;
        while(i != n - 1) {
            if(S[i] == S[i + 1]) {
                S.erase(i, 2);
                i = 0;
                continue;
            }
            ++i;
        }
        return S;
    }
};

// 类似栈的方法
class Solution2 {
public:
    string removeDuplicates(string S) {
        string res = "";
        for(char& c: S) {
            if(!res.empty() && res.back() == c) res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};