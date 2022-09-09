// 和可被 K 整除的子数组
// 前缀和
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> m = {{0, 1}};
        int sum = 0;
        int res = 0;
        for(auto& num: A) {
            sum += num;
            int remainder = (sum % K + K) % K;
            if(m.count(remainder)) res += m[remainder];
            ++m[remainder];
        }
        return res;
    }
};