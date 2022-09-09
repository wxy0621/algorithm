// 数位和相等数对的最大和
class Solution {
public:
    int countBitSum(int num) {
        int count = 0;
        while (num) {
            count += (num % 10);
            num /= 10;
        }
        return count;
    }
    int maximumSum(vector<int>& nums) {
        int res = -1;
        unordered_map<int, int> m;
        for (auto& num: nums) {
            int temp = countBitSum(num);
            if (m.count(temp)) {
                res = max(res, num + m[temp]);
                m[temp] = max(num, m[temp]);
            } else {
                m[temp] = num;
            }
        }
        return res;
    }
};