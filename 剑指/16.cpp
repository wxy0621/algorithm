// 快速幂非递归
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        int t = n;
        while(n) {
            if(n & 0x1) 
                res *= x;
            x *= x;
            n /= 2;
        }
        return t > 0 ? res : 1.0/res;
    }
};

int main()
{
    

    return 0;
}