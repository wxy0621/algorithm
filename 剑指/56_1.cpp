// 数组中数字出现的次数
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res1 = 0, res2 = 0;

        // 先异或遍历所有的数
        int temp = 0;
        for(int i: nums) {
            temp ^= i;
        }

        // 然后从右找出第一位非零的数，利用该非零数，可以划分出这两个数为两个不同的数组
        int div = 1;
        while((div & temp) == 0) {
            div <<= 1;
        }

        // 再分组遍历一遍
        for(int i: nums) {
            if(div & i)
                res1 ^= i;
            else
                res2 ^= i;
        }

        return vector<int> {res1, res2};
    }
};

int main()
{
    
    return 0;
}