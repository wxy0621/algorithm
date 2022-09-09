// 打印零与奇偶数
class ZeroEvenOdd {
private:
    int n;
    mutex m1;
    mutex m2;
    mutex m3;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        m2.lock();
        m3.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 1; i < n + 1; ++i) {
            m1.lock();
            printNumber(0);
            if(i % 2 == 0) m2.unlock();
            else m3.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 1; i < n + 1; ++i) {
            if(i % 2 == 0) {
                m2.lock();
                printNumber(i);
                m1.unlock();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i < n + 1; ++i) {
            if(i % 2) {
                m3.lock();
                printNumber(i);
                m1.unlock();
            }
        }
    }
};