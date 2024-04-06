// 按照频率将数组升序排序
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num: nums) {
            ++count[num];
        }
        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            if (count[a] != count[b]) {
                return count[a] < count[b];
            }
            return a > b;
        });
        return nums;
    }
};