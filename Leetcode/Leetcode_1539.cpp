// 第 k 个缺失的正整数
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur = 1;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            while (cur < arr[i]) {
                if (k == 1) return cur;
                --k;
                ++cur;
            }
            if (cur == arr[i]) ++cur;
        }
        return cur + k - 1;
    }
};