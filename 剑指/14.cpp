// 剪绳子
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        // 贪婪法，当长度大于5时，尽量多剪成3的绳子，当剩余长度为4时，尽量剪成2的绳子
        // 书上的动态规划暂时没看懂
        if(n < 2)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        
        int len_three = n / 3;
        if((n - len_three * 3) == 1)
            len_three--;
        
        int len_two = ((n - len_three * 3)) / 2;

        return (int)(pow(3, len_three) * (pow(2, len_two)));
    }
};

int main()
{
    
    cout << endl;

    return 0;
}