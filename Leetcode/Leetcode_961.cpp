// 重复 N 次的元素
// 哈希表
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> m;
        for(auto& num: A) ++m[num];
        for(auto& t: m) if(t.second == n / 2) return t.first;
        return -1;
    }
};

