// 两个数组的交集II
// 哈希表优化
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> m;
        for (auto& num: nums1) ++m[num];
        for (auto& num: nums2) {
            if (m.count(num) && m[num] != 0) {
                res.emplace_back(num);
                --m[num];
            }
        }
        return res;
    }
};

// 哈希表
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int num: nums1)
            ++m[num];
        for(int num: nums2) {
            if(m.count(num)) {
                res.emplace_back(num);
                --m[num];
            }
            if(m[num] == 0)
                m.erase(num);
        }
        return res;
    }
};

// 排序法
class Solution3 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j])
                ++i;
            else if(nums1[i] > nums2[j])
                ++j;
            else {
                res.emplace_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return res;
    }
};