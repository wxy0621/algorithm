// 最后一块石头的重量
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int first_max;
        int second_max;
        while(stones.size() >= 2) {
            first_max = stones.back();
            stones.pop_back();
            second_max = stones.back();
            stones.pop_back();
            if(first_max - second_max) stones.emplace_back(first_max - second_max);
            sort(stones.begin(), stones.end());
        }
        return stones.empty() ? 0 : stones[0];
    }
};

// 优先队列
class Solution2 {
public:
    int lastStoneWeight(vector<int>& stones) {
        // less<int> 降序，大顶堆，top() 和 pop() 方法都是针对队头元素而言的
        priority_queue<int, vector<int>, less<int> > s;
        for(int i = 0; i < stones.size(); ++i) s.push(stones[i]);
        int first_max;
        int second_max;
        while(s.size() >= 2) {
            first_max = s.top();
            s.pop();
            second_max = s.top();
            s.pop();
            if(first_max - second_max) s.push(first_max - second_max);
        }
        return s.empty() ? 0 : s.top();
    }
};