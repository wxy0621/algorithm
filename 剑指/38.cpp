// 字符串的排列
// 剪枝
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        int n = s.size();
        backTracking(s, res, 0, n);
        return res;
    }
    void backTracking(string& s, vector<string>& res, int start, int& n) {
        if (start == n - 1) {
            res.emplace_back(s);
            return;
        }
        unordered_set<int> appeared;
        for (int i = start; i < n; ++i) {
            if (appeared.count(s[i])) continue;
            appeared.insert(s[i]);
            swap(s[start], s[i]);
            backTracking(s, res, start + 1, n);
            swap(s[start], s[i]);
        }
    }
};

class Solution2 {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        vector<char> temp;
        for(int i = 0; i < s.size(); ++i) {
            temp.emplace_back(s[i]);
        }
        sort(temp.begin(), temp.end(), compare);
        dfs(temp, 0);
        return res;
    }
    void dfs(vector<char> temp, int left) {
        if(left == temp.size() - 1) {
            string s;
            for(int i = 0; i < temp.size(); ++i) {
                s += temp[i];
            }
            res.emplace_back(s);
            return;
        }
        for(int i = left; i < temp.size(); ++i) {
            if(i != left && temp[left] == temp[i]) {
                continue;
            }
            swap(temp[i], temp[left]);
            dfs(temp, left+1);
        }
    }
    static bool compare(const char& a, const char& b) {
        return a <= b;
    }
};