// 柠檬水找零
// 哈希表
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m;
        for(auto& n: bills) {
            ++m[n];
            if(n == 10) {
                --m[5];
                if(m[5] < 0) return false;
            } else if(n == 20) {
                if(m[5] >= 1 && m[10] >= 1) {
                    --m[5];
                    --m[10];
                    continue;
                } else if(m[5] >= 3) {
                    m[5] -= 3;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};

// 改进版
class Solution2 {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m;
        for(auto& n: bills) {
            if(n == 5) ++m[5];
            else if(n == 10) {
                --m[5];
                ++m[10];
            } else if(n == 20 && m[10] > 0) {
                --m[5];
                --m[10];
            } else {
                m[5] -= 3;
            }
            if(m[5] < 0) return false;
        }
        return true;
    }
};

// 数组
class Solution3 {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m[2] = {0};
        for(auto& n: bills) {
            if(n == 5) ++m[0];
            else if(n == 10) {
                --m[0];
                ++m[1];
            } else if(n == 20 && m[1] > 0) {
                --m[0];
                --m[1];
            } else {
                m[0] -= 3;
            }
            if(m[0] < 0) return false;
        }
        return true;
    }
};

// 符号
class Solution4 {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto& n: bills) {
            if(n == 5) ++five;
            else if(n == 10) {
                --five;
                ++ten;
            } else if(n == 20 && ten > 0) {
                --five;
                --ten;
            } else {
                five -= 3;
            }
            if(five < 0) return false;
        }
        return true;
    }
};