// 分割回文串
class Solution {
public:
    bool isPalindrome(string str) {
        int n = str.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    void backTracking(string& str, int start, int end) {
        if (start > end) {
            res.emplace_back(temp);
            return;
        }
        for (int i = 1; i <= end - start + 1; ++i) {
            if (isPalindrome(str.substr(start, i))) {
                temp.emplace_back(str.substr(start, i));
                backTracking(str, start + i, end);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backTracking(s, 0, s.size() - 1);
        return res;
    }
private:
    vector<vector<string>> res;
    vector<string> temp;
};