// 最小栈
#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(!s2.empty() && s2.top() < x) {
            s2.push(s2.top());
        } else {
            s2.push(x);
        }
        s1.push(x);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    
    return 0;
}