// 单调递增的数字
// 从最后开始遍历，若某数比前面的数小，则该数及之后的数全变9，某数-1
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int res = 0;
        string NStr = to_string(N);
        int n = NStr.size();
        int i = n - 1;
        while(i > 0) {
            if(NStr[i] < NStr[i-1]) {
                --NStr[i-1];
                for(int j = i; j < n; ++j) NStr[j] = '9';
            }
            --i;
        }
        for(i = 0; i < n; ++i) {
            res = res * 10 + (NStr[i] - 48);
        }
        return res;
    }
};