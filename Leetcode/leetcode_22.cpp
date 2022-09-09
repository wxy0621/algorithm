// 括号生成
#include <bits/stdc++.h>

using namespace std;

// DFS
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", 0, 0, n);
        return res;
    }

    void helper(vector<string>& res, string str, int l, int r, int n) {
        if(l > n || r > n || r > l)
            return;
        if(l == n && r == n) {
            res.emplace_back(str);
            return;
        }
        helper(res, str + '(', l+1, r, n);
        helper(res, str + ')', l, r+1, n);
        return;
    }
};

int main()
{
    return 0;
}