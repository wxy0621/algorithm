// 裁剪数字后查询第 K 小的数字
struct cmp {
    bool operator()(pair<string, int>& p1, pair<string, int>& p2) {
        if (p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    }
};
class Solution {
public:
    string trimString2Num(string& num, int trimNum) {
        string str = num.substr(num.size() - trimNum, trimNum);
        return str;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        for (auto& query: queries) {
            priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
            for (int i = 0; i < n; ++i) {
                string temp = trimString2Num(nums[i], query[1]);
                pair<string, int> p = {temp, i};
                pq.push(p);
                if (pq.size() > query[0]) {
                    pq.pop();
                }
            }
            res.emplace_back(pq.top().second);
        }
        return res;
    }
};