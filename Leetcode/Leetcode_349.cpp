// 两个数组的交集
// 自己的方法，空间复杂度较高
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s;
        unordered_set<int> s_temp;
        for(int& num: nums1) {
            if(s.find(num) != s.end()) {
                continue;
            }
            s.insert(num);
        }
        for(int& num: nums2) {
            if(s_temp.find(num) != s_temp.end()) {
                continue;
            }
            if(s.find(num) != s.end()) {
                res.emplace_back(num);
            }
            s_temp.insert(num);
        }
        return res;
    }
};


// 速度快了，使用空间没有减少
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s(nums2.begin(), nums2.end());
        for(int& num: nums1) {
            if(s.erase(num)) {
                res.emplace_back(num);
            }
        }
        return res;
    }
};

// 改
class Solution3 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s, res_s;
        for(auto& num: nums1) s.insert(num);
        for(auto& num: nums2) {
            if(s.count(num)) res_s.insert(num);
        }
        for(auto& num: res_s) res.emplace_back(num);
        return res;
    }
};