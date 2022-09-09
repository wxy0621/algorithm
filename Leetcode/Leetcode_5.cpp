// 最长回文子串
// 中心扩散算法
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start, end;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int temp1 = getLength(s, i, i, n);
            int temp2 = getLength(s, i, i+1, n);
            res = max(res, temp1);
            res = max(res, temp2);
            if (res == temp1) start = i - (res - 1) / 2;
            if (res == temp2) start = i - (res - 2) / 2;
        }
        return s.substr(start, res);
    }
    int getLength(const string& s, int i, int j, const int& n) {
        while (i >= 0 && j < n && s[i] == s[j]) {
            --i;
            ++j;
        }
        return j - i - 1;
    }
};

// 弱智才保存两个，半年前的代码好蠢
class Solution2 {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0, n = s.size();
        for(int i = 0; i < n; ++i) {
            auto [left1, right1] = helper(s, i, i);
            auto [left2, right2] = helper(s, i, i+1);

            if(right1 - left1 >= end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 >= end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    pair<int, int> helper(const string& s, int start, int end) {
        while(start >= 0 && end < s.size() && s[start] == s[end]) {
            start--;
            end++;
        }
        return {start + 1, end - 1};
    }
};

int main()
{
    
    return 0;
}