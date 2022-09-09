// K 次取反后最大化的数组和
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int sum = 0, min_num = A[0];
        for(auto& num: A) {
            if(num < 0 && K > 0) {
                num = -num;
                --K;
            }
            min_num = min(min_num, num);
            sum += num;
        }
        if(K == 0 || K % 2 == 0) return sum;
        else return sum - 2 * min_num;
    }
};