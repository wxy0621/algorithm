// 多数元素
// 排序
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// 哈希表
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int res;
        int temp_max = 0;
        for(int& num: nums) {
            ++m[num];
            if(m[num] > temp_max) {
                res = num;
                temp_max = m[num];
            }
        }
        return res;
    }
};

// Boyer-Moore 投票算法
// 把众数记为 +1, 其他数 −1, 结果那个最多的数肯定是 >0
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int count = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] == res)
                ++count;
            else if(--count == 0) {
                res = nums[i];
                ++count;
            }
        }
        return res;
    }
};