// 电话号码的字母组合
// 回溯法
class Solution {
public:
    vector<string> res;
    string cur;
    map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        dfs(0, digits);
        return res;
    }
    
    void dfs(int index, string digits) {
        if(digits.size() == index) {
            res.emplace_back(cur);
            return;
        }

        for(int i = 0; i < m[digits[index]].size(); ++i) {
            cur.push_back(m[digits[index]][i]);
            dfs(index + 1, digits);
            cur.pop_back();
        }
    }
};