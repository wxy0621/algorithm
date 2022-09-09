// 独一无二的出现次数
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> temp;
        for(int& num: arr) ++m[num];
        for(auto& t: m) {
            if(temp.count(t.second)) return false;
            else temp.insert(t.second);
        }
        return true;
    }
};