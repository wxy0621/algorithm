// 两数之和 II - 输入有序数组
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i = 0, n = numbers.size();
        int j = n - 1;
        while(i < j) {
            if((numbers[i] + numbers[j]) == target) {
                res.emplace_back(i + 1);
                res.emplace_back(j + 1);
                break;
            }
            else if((numbers[i] + numbers[j]) > target) --j;
            else ++i;
        }
        return res;
    }
};