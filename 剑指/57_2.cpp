// 和为s的连续正数序列
// 典型的滑动窗口
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector< vector<int> > findContinuousSequence(int target) {
        int first = 1, end = 2;
        int total = first + end;
        vector< vector<int> > res;
        while(end <= (target+ 1 ) / 2) {
            if(total == target) {
                vector<int> temp;
                for(int i = first; i <= end; ++i) {
                    temp.push_back(i);
                }
                res.push_back(temp);
                total -= first;
                ++first;
            } else if(total > target) {
                total -= first;
                ++first;
            } else {
                ++end;
                total += end;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}