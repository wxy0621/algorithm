// 最长不含重复字符的子字符串
// 滑动窗口法
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int res = 0, l = 0, r = 0;
        while(r < s.size()) {
            // 若出现重复的字母，则更新l值，l为滑动窗口的左端
            if(m.find(s[r]) != m.end()) {
                // "abba", 若不用max函数，l会再跳回前面a的下一位
                l = max(l, m[s[r]] + 1);
            }
            // 更新元素的在哈希表中的值，存放字母的最新位置索引，若无则新增
            m[s[r++]] = r;
            // 由于r自增了1，所以不需要 r-l+1 了
            res = max(res, r - l);
        }

        return res;
    }
};

int main()
{
    return 0;
}