// 颠倒二进制位
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> v;
        uint32_t res = 0;
        int count = 32;
        while(n != 0) {
            v.emplace_back(n % 2);
            n /= 2;
            --count;
        }
        while(count--) {
            v.emplace_back(0);
        }
        for(int i = 0; i < 32; ++i) {
            res = res * 2 + v[i];
        }
        return res;
    }
};

class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 32;
        while(count--) {
            res = res * 2 + (n % 2);
            n /= 2;
        }
        return res;
    }
};