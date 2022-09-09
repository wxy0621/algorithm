// 每个元音包含偶数次的最长子字符串
// 通过一个 32 大小的数组存储 32 种状态（1表示奇数个，0表示偶数个），只有 0 是符合条件的
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> pre(32, INT_MAX);
        pre[0] = -1; // -1距离，作减法正好得到距离
        int n = s.size();
        int res = 0, cur = 0;
        for(int i = 0; i < n; ++i) {
            switch(s[i]) { // 异或来交替出现 0 和 1
                case 'a': cur ^= 1; break;
                case 'e': cur ^= 1 << 1; break;
                case 'i': cur ^= 1 << 2; break;
                case 'o': cur ^= 1 << 3; break;
                case 'u': cur ^= 1 << 4; break;
                default: break;
            }
            if(pre[cur] == INT_MAX) pre[cur] = i; // 存储第一次出现该状态的情况，若再次出现，作减法可得状态0
            else res = max(res, i - pre[cur]); 
        }
        return res;
    }
};