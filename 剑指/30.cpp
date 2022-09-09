// 最小栈
#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() = default;
    
    void push(int x) {
        s.push(x);
        if(s_tmp.empty() || s_tmp.top() > x) {
            s_tmp.push(x);
        } else {
            s_tmp.push(s_tmp.top());
        }
    }
    
    void pop() {
        s.pop();
        s_tmp.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return s_tmp.top();
    }
private:
    stack<int> s;
    stack<int> s_tmp;
};

int main()
{

    return 0;
}