// 队列的最大值，通过辅助的双端队列实现
#include <bits/stdc++.h>

using namespace std;

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while(!d.empty() && d.back() < value)
            d.pop_back();
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int res = q.front();
        if(q.front() == d.front())
            d.pop_front();
        q.pop();
        return res;
    }
private:
    queue<int> q; // 队列为主
    deque<int> d; // 双端队列为辅

};

int main()
{
    
    return 0;
}