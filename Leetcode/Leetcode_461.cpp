// 汉明距离
// 自己的写的垃圾方法
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ham_dis = 0;
        vector<int> x_v(32, 0);
        vector<int> y_v(32, 0);
        for(int i = 0; i < 32; ++i) {
            if(x == 0)
                break;
            x_v[i] = x % 2;
            x = x / 2;
        }
        for(int i = 0; i < 32; ++i) {
            if(y == 0)
                break;
            y_v[i] = y % 2;
            y = y / 2;
        }
        for(int i = 0; i < 32; ++i) {
            if(y_v[i] != x_v[i])
                ++ham_dis;
        }
        return ham_dis;
    }
};

// 异或
class Solution2 {
public:
    int hammingDistance(int x, int y) {
        int ham_dis = 0;
        int temp = x ^ y;
        while(temp > 0) {
            if(temp & 1 == 1)
                ++ham_dis;
            temp >>= 1;
        }
        return ham_dis;
    }
};