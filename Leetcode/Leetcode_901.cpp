// 股票价格跨度
// 单调栈
class StockSpanner {
public:
    StockSpanner() {

    }
    int next(int price) {
        int res = 1;
        while (!minStk.empty() && price >= minStk.top()) {
            minStk.pop();
            res += weightStk.top();
            weightStk.pop();
        }
        minStk.push(price);
        weightStk.push(res);
        return res;
    }
private:
    stack<int> minStk;
    stack<int> weightStk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */