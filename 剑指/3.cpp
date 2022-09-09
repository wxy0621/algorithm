// 数组中的重复数字
#include <bits/stdc++.h>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length <= 0)
        return false;

    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
        {
            return false;
        }
    }

    for(int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}

int main()
{
    int numbers[] = {2, 3, 1, 0, 2, 5, 3};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int duplication;
    bool answer;
    answer = duplicate(numbers, length, &duplication);
    if(answer)
        cout << "有重复数字: " << duplication << endl;
    else
        cout << "无重复数字。 " << endl;

    return 0;
}