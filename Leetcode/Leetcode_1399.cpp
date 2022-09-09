// 统计最大组的数目
// 哈希表
class Solution {
public:
    int countLargestGroup(int n) {
        int count = 0;
        int max_sum = 0;
        unordered_map<int, int> m;
        for(int i = 1; i <= n; ++i) {
            int temp = i;
            int t = 0;
            while(temp != 0) {
                t += temp % 10;
                temp /= 10;
            }
            ++m[t];
            max_sum = max(max_sum, m[t]);
        }
        for(auto& [_, value]: m) {
            if(value == max_sum) {
                ++count;
            }
        }
        return count;
    }
};