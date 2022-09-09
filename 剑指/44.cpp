// 数字序列中某一位的数字
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long digit = 1;
        long start = 1;
        long count = 9;
        while(n > count) {
            n -= count;
            digit++;
            start *= 10;
            count = 9 * digit * start;
        }
        long num = start + (n - 1) / digit;
        return to_string(num)[(n - 1) % digit] - '0';
    }
};

int main()
{
    
    return 0;
}