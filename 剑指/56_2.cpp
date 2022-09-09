// 数组中只要一个数出现一次，其余数都出现3次
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            int count = 0;
            for(int a: nums) {
                // 统计某一位的1的数量和
                if(a & (1 << i)) count++;
            }
            // 取余3，即使多余的那个数字
            if(count % 3 == 1) res ^= (1 << i);
        }
        return res;
    }
};

// 哈希表
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int res;
        map<int, int> mp;
        for(int i: nums) mp[i]++;
        for(auto i: mp) {
            if(i.second == 1) {
                res = i.first;
                break;
            }
        }
        return res;
    }
};

int main()
{
    int a = 6;
    1 << a;
    cout << a << endl;
    return 0;
}