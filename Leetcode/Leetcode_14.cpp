// 最长公共前缀
// 纵向遍历
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        int len = strs[0].size();
        for(int i = 0; i < len; ++i) {
            char temp = strs[0][i];
            for (int j = 1; j < n; ++j) {
                if (i == strs[j].size() || temp != strs[j][i]) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        if(n == 1) return strs[0];
        // sort对vector按照字母顺序排序
        sort(strs.begin(), strs.end());
        for(int i=0; i < min(strs[0].length(), strs[n-1].length()); i++){
            if(strs[0][i] != strs[n-1][i])
                // 获得从0，开始的i位string
                return strs[0].substr(0, i);
        }
        // 若在上述循环下均一样，选取长度短的字符串
        return strs[0].length() > strs[n-1].length() ? strs[n-1] : strs[0];
    }
};
