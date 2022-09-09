#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 整个数组可以分为前后部分，第一部分递增，第二部分递减
        int i = 0;
        int j = numbers.size() - 1;
        int m;

        while(i < j)
        {
            m = (i + j) / 2;
            if(numbers[m] > numbers[j])
                i = m + 1; // 说明numbers[m]在递增部分，所以将i置于m后面
            else if(numbers[m] < numbers[j])
                j = m; // 说明numbers[m]在递减部分，所以将j置于m位置
            else
                j--; // 若出现相同情况，将j前置一位，使m可以重新计算
        }
        return numbers[i]; // 经过多次测试发现，numbers[i]一定是最小的
    }
};

int main()
{

    return 0;
}