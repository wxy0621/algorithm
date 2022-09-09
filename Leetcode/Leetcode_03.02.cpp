// 栈的最小值
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(s2.empty() || x < s2.top()) s2.push(x);
        else s2.push(s2.top());
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
};