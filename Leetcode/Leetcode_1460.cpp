// 通过翻转子数组使两个数组相等
// 判断量数组是否相同
// 哈希表
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto& num: target) ++m[num];
        for(auto& num: arr) --m[num];
        for(auto& t: m) {
            if(t.second != 0) return false;
        }
        return true;
    }
};

// 数组
class Solution2 {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int m[1001] = {0};
        for(auto& num: target) ++m[num];
        for(auto& num: arr) --m[num];
        for(int i = 0; i < 1001; ++i) {
            if(m[i] != 0) return false;
        }
        return true;
    }
};