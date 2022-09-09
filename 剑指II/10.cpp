// ��Ϊ k ��������
// ��Ϊ���ֿ����ɸ�����Ϊֻ�ܲ���ǰ׺�ͣ����ܻ�������
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0;
        int preSum = 0;
        for (auto& num: nums) {
            preSum += num;
            if (m.count(preSum - k)) {
                res += m[preSum - k];
            }
            ++m[preSum];
        }
        return res;
    }
};