// 和为 K 的子数组
// 哈希表
// 假如存在区间[left,right]，使得在[left,right]这个区间的子数组的和为k。换句话说，就是前right项和减去前left项和等于k，即前left项和等于前right项和减去k。
// 可以这样做，在扫描数组的同时，假设当前扫到第i位，记录它的前i项和sum，用该和减去k，即sum-k，判断sum-k是否为某个位置的前n项和，若是，更新统计量。

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(int num: nums) {
            sum += num;
            if(m.find(sum - k) != m.end()) res += m[sum - k];
            ++m[sum];
        }
        return res;
    }
};