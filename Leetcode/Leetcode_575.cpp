// 分糖果
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        int count = 0;
        for(auto& t: candies) {
            if(!s.count(t)) {
                ++count;
                s.insert(t);
            }
        }
        return count >= candies.size() / 2 ? candies.size() / 2 : count;
    }
};