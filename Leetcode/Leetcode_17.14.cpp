// 最小K个数
// 优先队列，小顶堆
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue< int, vector<int>, greater<int> > q;
        for(int& num: arr) q.push(num);
        vector<int> res;
        while(k--) {
            res.emplace_back(q.top());
            q.pop();
        }
        return res;
    }
};

// 大顶堆
class Solution2 {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int> q;
        for(int& num: arr) {
            q.push(num);
            if(q.size() > k) q.pop();
        }
        vector<int> res;
        while(k--) {
            res.emplace_back(q.top());
            q.pop();
        }
        return res;
    }
};

// 排序
class Solution3 {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res;
        for(int i = 0; i < k; ++i) res.emplace_back(arr[i]);
        return res;
    }
};