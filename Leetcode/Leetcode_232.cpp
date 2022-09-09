// 用栈实现队列
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() = default;
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        if (!s2.empty()) {
            res = s2.top();
            s2.pop();
            return res;
        } else {
            while (!s1.empty()) {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
            res = s2.top();
            s2.pop();
            return res;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        } else {
            while (!s1.empty()) {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
            return s2.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};