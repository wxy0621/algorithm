// 栈排序
// 辅助栈，但感觉不是很聪明的解法
class SortedStack {
public:
    SortedStack() {

    }
    
    void push(int val) {
        while (!minStk.empty() && val > minStk.top()) {
            int temp = minStk.top();
            minStk.pop();
            tempStk.push(temp);
        }
        minStk.push(val);
        while (!tempStk.empty()) {
            int temp = tempStk.top();
            tempStk.pop();
            minStk.push(temp);
        }
    }
    
    void pop() {
        if (!minStk.empty()) {
            minStk.pop();
        }
    }
    
    int peek() {
        if (!minStk.empty()) {
            return minStk.top();
        }
        return -1;
    }
    
    bool isEmpty() {
        return minStk.empty();
    }
private:
    stack<int> minStk;
    stack<int> tempStk;
};