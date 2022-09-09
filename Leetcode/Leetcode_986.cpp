// 区间列表的交集
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n1 = firstList.size();
        int n2 = secondList.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (firstList[i][1] < secondList[j][0]) {
                ++i;
                continue;
            }
            if (firstList[i][0] > secondList[j][1]) {
                ++j;
                continue;
            }
            int left = max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            res.emplace_back(vector<int>{left, right});
            if (firstList[i][1] > secondList[j][1]) ++j;
            else if (firstList[i][1] < secondList[j][1]) ++i;
            else {
                ++i;
                ++j;
            }
        }
        return res;
    }
};