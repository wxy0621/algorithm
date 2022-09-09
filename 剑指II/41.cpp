// 滑动窗口的平均值
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capcity = size;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() == capcity) {
            sum -= q.front();
            q.pop();
            sum += val;
            q.push(val);
        } else {
            sum += val;
            q.push(val);
        }
        return sum * 1.0 / q.size();
    }
private:
    queue<int> q;
    int sum;
    int capcity;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */