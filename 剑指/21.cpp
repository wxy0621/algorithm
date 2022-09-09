// 调整数组顺序使奇数位于偶数前面
#include <bits/stdc++.h>

using namespace std;

void ReorderOddEven(int* pData, unsigned int length)
{
    if(pData == nullptr || length == 0)
        return;
    int *begin = pData;
    int *end = pData + length - 1;

    while(begin < end)
    {
        while(begin < end && (*begin & 0x1) != 0)
            begin++;
        while(begin < end && (*end & 0x1) == 0)
            end--;
        if(begin < end)
        {
            int temp = *begin;
            *begin = *end;
            *end = temp;
        }
    }
}


int main()
{
    int nums[] = {1,2,3,4,5};
    unsigned int length = sizeof(nums) / sizeof(nums[0]);
    for(int i=0; i < length; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    ReorderOddEven(nums, length);
    for(int i=0; i < length; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}