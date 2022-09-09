// 两个栈实现队列 & 两个队列实现栈
#include <bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    stack<int> pushs, pops;//利用两个栈实现队列
    //1.只有当pops栈中为空的时候，才可以将pushs栈中的元素倒入pops栈
    //2.而且pushs栈要一次倒完
    void push2pop()
    {
        if(pops.empty())
        {
            while(!pushs.empty())
            {
                pops.push(pushs.top());
                pushs.pop();
            }
        }
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        //直接压入
        pushs.push(x);
    }
    
    int pop() {
        //如果pops中没有元素，就先把pushs中的元素依次弹出压入pops
        push2pop();
        //pops中已经有元素了,就直接获取pops的栈顶元素
        int res = pops.top();
        pops.pop();
        return res;
    }
    
    int peek() {
        //如果pops中没有元素，就先把pushs中的元素依次弹出压入pops
        push2pop();
        //pops中已经有元素了,就直接获取pops的栈顶元素
        int res = pops.top();
        return res;
    }
    
    bool empty() {
        //只要有一个栈元素不为空，队列就不为空
        return pushs.empty() && pops.empty();
    }
};

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        topValue = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(q1.size() > 1)
        {
            topValue = q1.front();
            q2.push(topValue);
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        queue<int> tmp = q1;
        q1 = q2;
        q2 = tmp;
        return res;

    }
    
    /** Get the top element. */
    int top() {
        return topValue;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
    int topValue;
};

int main()
{
    // 两栈模拟队列
    MyQueue A;
    A.push(1);
    A.push(2);
    A.push(3);
    cout << A.pop() << " " << A.pop() << " " << A.pop() << endl;

    // 两队列模拟栈
    MyStack B;
    B.push(1);
    B.push(2);
    B.push(3);
    cout << B.pop() << " " << B.pop() << " " << B.pop() << endl;

    return 0;
}