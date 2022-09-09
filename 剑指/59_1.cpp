// 队列的最大值，暴力法太慢，采用双端队列，最大的始终在队列的头部
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> res;
        if(nums.empty()) return res;
        for(int i = 0; i < k; ++i) {
            while(!deq.empty() && nums[i] >= nums[deq.back()])
                deq.pop_back();
            deq.push_back(i);
        }
        for(int i = k; i < nums.size(); ++i) 
        {
            res.push_back(nums[deq.front()]);
            while(!deq.empty() && nums[i] >= nums[deq.back()])
                deq.pop_back();
            if(!deq.empty() && deq.front() <= i - k)
                deq.pop_front();
            deq.push_back(i);
        }
        res.push_back(nums[deq.front()]);
        
        return res;
    }
};

int main()
{
    
    return 0;
}