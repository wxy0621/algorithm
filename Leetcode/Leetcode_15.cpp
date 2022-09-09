// 三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int k = 0; k <= n - 3; ++k) {
            if(nums[k] > 0)
                break;
            if(k > 0 && nums[k] == nums[k-1])
                continue;
            int i = k + 1;
            int j = n - 1;
            while(i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    vector<int> temp {nums[i], nums[j], nums[k]};
                    res.emplace_back(temp);
                    --j;
                    while(i < j && nums[j] == nums[j+1]) --j;
                } else if(sum < 0) {
                    ++i;
                } else {
                    --j;
                }
            }
        }
        return res;
    }
};

// new
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector< vector<int> > res;
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total == 0) {
                    res.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left-1]) ++left;
                    while (left < right && nums[right] == nums[right+1]) --right;
                } else if (total > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return res;
    }
};