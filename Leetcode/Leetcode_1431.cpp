// 拥有最多糖果的孩子
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int max_candies = 0;
        for(auto& c: candies) max_candies = max(max_candies, c);
        for(auto& c: candies) {
            if(c + extraCandies >= max_candies) res.emplace_back(true);
            else res.emplace_back(false);
        }
        return res;
    }
};