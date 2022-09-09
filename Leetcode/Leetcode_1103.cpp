// 分糖果II
// 暴力模拟
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int i = 0;
        int candies_num = 1;
        while(candies > 0) {
            if(candies_num > candies) {
                res[i] += candies;
                return res;
            } else {
                res[i] += candies_num;
                candies -= candies_num;
                ++candies_num;
                ++i;
            }
            if(i == num_people) i = 0;
        }
        return res;
    }
};