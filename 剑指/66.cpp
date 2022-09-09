// 构建乘积数组
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        int temp = 1;
        vector<int> res(n, 1);
        for(int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * a[i - 1];
        }
        for(int i = n - 2; i >= 0; --i) {
            temp *= a[i + 1];
            res[i] *= temp;
        }
        return res;
    }
};