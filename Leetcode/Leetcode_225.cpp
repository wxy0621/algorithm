// 用队列实现栈
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() = default;
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q2.front();
        q2.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};