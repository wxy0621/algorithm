// 数组异或操作
class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for(int i = 0; i < n; ++i) res ^= (i * 2 + start);
        return res;
    }
};