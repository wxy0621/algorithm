// 约瑟夫环
#include <bits/stdc++.h>

using namespace std;

// 公式法，推导复杂
class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for(int i = 2; i <= n; ++i) {
            res = (res + m) % i;
        }
        return res;
    }
};

// 模拟法，但复杂度太高，会超时
class Solution2 {
public:
    int lastRemaining(int n, int m) {
        if(n == 1) return 0;
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            q.push(i);
        }
        int index = 1;
        while(q.size() > 1) {
            if(index == m) {
                q.pop();
                index = 1;
            } else {
                int tmp = q.front();
                q.pop();
                q.push(tmp);
                index++;
            }
        }
        return q.front();
    }
};

int main()
{
    
    return 0;
}