// 根据身高重建队列
// 先排序，再插入（list）速度很快
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        list< vector<int> > res; // list 插入提高速度
        sort(people.begin(), people.end(), [](const vector<int>& l, const vector<int>& r){ return l[0] == r[0] ? l[1] <= r[1] : l[0] > r[0]; }); // 排序
        int n = people.size();
        // 循环插入
        for(int i = 0; i < n; ++i) {
            auto pos = res.begin();
            advance(pos, people[i][1]);
            res.insert(pos, people[i]);
        }
        return vector< vector<int> >(res.begin(), res.end());
    }
};

// 用 vector 速度慢得多
class Solution2 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector< vector<int> > res; // list 插入提高速度
        sort(people.begin(), people.end(), [](const vector<int>& l, const vector<int>& r){ return l[0] == r[0] ? l[1] <= r[1] : l[0] > r[0]; }); // 排序
        int n = people.size();
        // 循环插入
        for(int i = 0; i < n; ++i) {
            auto pos = res.begin();
            advance(pos, people[i][1]);
            res.insert(pos, people[i]);
        }
        return res;
    }
};