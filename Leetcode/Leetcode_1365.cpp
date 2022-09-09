// 有多少小于当前数字的数字
// 桶排序 / 桶排序
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(101, 0);
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i) ++cnt[nums[i]];
        for(int i = 1; i <= 100; ++i) cnt[i] += cnt[i - 1];
        for(int i = 0; i < n; ++i) {
            if(nums[i]) res[i] = cnt[nums[i] - 1];
        }
        return res;
    }
};

// 变体
class Solution2 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        int count[101] = {0};
        for(auto& num: nums) ++count[num];
        for(auto& num: nums) {
            int temp = 0;
            for(int i = 0; i < num; ++i) {
                temp += count[i];
            }
            res.emplace_back(temp);
        }
        return res;
    }
};

// 排序
class Solution3 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector< pair<int, int> > tmp;
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i) tmp.emplace_back(nums[i], i);
        sort(tmp.begin(), tmp.end());
        int pre = -1;
        for(int i = 0; i < n; ++i) {
            if(i == 0) res[tmp[i].second] = pre + 1;
            else if(tmp[i].first == tmp[i - 1].first) res[tmp[i].second] = pre + 1;
            else {
                pre = i - 1;
                res[tmp[i].second] = pre + 1;
            }
        }
        return res;
    }
};